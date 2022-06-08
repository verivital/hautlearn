clc
clear

global sigma num_var num_ud Ts winlen Time PolyDegree
Time = false;
Ts  = 0.05;
sigma = 0.003;  
winlen = 10;
num_var = 2;
num_ud = 0;
PolyDegree = 3;
num = 1; x = []; ud = []; 

% Load data, process noise and detect changepoints
for i = 1:10
    load(['..', filesep, 'trainingdata' , filesep, 'run', int2str(i), '.mat']);
%     xout = xout(:,1:2);
    trace_temp = FnProcessNoiseData(xout, num_var);
    trace(num) = trace_temp;
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end

%%

tic
trace = FnClusterSegs(trace, x, ud);
toc
t1 = toc;

%%
for n=1:length(trace)
    trace(n).labels_trace = [trace(n).labels_trace;0];
end

tode = tic;
ode = FnEstNL(trace);
tode = toc(tode);
save('tode.mat','tode');

%% 
eta = 100000; % number of iterations 
lambda = 0.05; % tolerance 
% gamma = 10; %the least number of inliers
gamma = 3;
[trace,label_guard] = FnLI(trace, eta, lambda, gamma);
t2 = toc;
pta_trace = FnPTA(trace);
pta_trace = pta_filter(pta_trace);
t3 = toc;
%%
FnHystNL('automata_learning',label_guard, num_var, ode, pta_trace);

addpath(['..', filesep, '..', filesep, 'src',filesep,'hyst', filesep, 'src', filesep, 'matlab']);
try
    SpaceExToStateflow('automata_learning.xml');
catch
end

disp('Converting Hybrid Automaton from SpaceEx to CORA')
try
    spaceex2cora('automata_learning.xml',0,'automata_learning_sys','ex1_linear',pwd);
catch
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function pta_trace_new = pta_filter(pta_trace)
    % remove false pta
    label1s = extractfield(pta_trace,'label1');
    label2s = extractfield(pta_trace,'label2');
    id1s = extractfield(pta_trace,'id1');
    id2s = extractfield(pta_trace,'id2');
    nn = 1;
    while true
        if nn>length(pta_trace)
            break;
        end
        %flag1 = pta_trace(nn).times<=2;
        flag2 = ~ismember(pta_trace(nn).label1, label2s);
        flag3 = ~ismember(pta_trace(nn).label2, label1s);
        flag4 = ~ismember(pta_trace(nn).id1, id1s);
        flag5 = ~ismember(pta_trace(nn).id2, id2s);
        
        if (~ismember(pta_trace(nn).id1, id2s)) && (pta_trace(nn).id1~=1) || ~ismember(pta_trace(nn).id2, id1s)
            pta_trace(nn) = [];
        else
            nn = nn+1;
        end
    end
    pta_trace_new = pta_trace;
end

function trace = FnProcessNoiseData(xout, num_var)

    chpoints = [];
    for i = 1:num_var
        chpoints = union(chpoints, changepoint(xout(:,i)));
    end
    
    % remove redundant chpoints
    chpoints = filterindx(chpoints);
    xout_reduced= xout(:, 1:num_var);

    trace.x = xout_reduced;
    trace.chpoints = chpoints;
    trace.ud = [];
    trace.labels_num = []; 
    trace.labels_trace = [];  
end

function indx = changepoint(values)
    diffs = diff(values,2);
    indx = find(diffs<=-0.005|diffs>=0.005)+1;
    indx = union(1,[indx; length(values)]);
    
end

function indx = filterindx(indx)
    n = 1;
    windw = 10; 
    while true
        if n >= length(indx)
            break;
        end
        id1 = indx(n);
        while true
            if n+1 >= length(indx)
                break;
            end
            id2 = indx(n+1);
            if id2-id1<=windw
                indx(n+1) = [];
            else
                break;
            end
        end
        n = n+1;
    end
end