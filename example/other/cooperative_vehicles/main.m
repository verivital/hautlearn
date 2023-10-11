clc
clear

addpath(['.', filesep, 'trainingdata']);
addpath(['..', filesep, '..', filesep, 'src']);
global sigma num_var num_ud Ts winlen Time
Time = true;
Ts  = 0.05;
sigma = 0.008; %0.00002;  
winlen = 10;
num_var = 9; num_ud = 1;
num =1; x = []; ud = []; 


for i =1:16
    load(['.\trainingdata\trainingdata', int2str(i),'.mat']);
    trace_temp = FnProcessNoiseData(trainingdata, num_var);
    trace(num) = trace_temp;
    x = [x; trace(num).x(:,1:num_var)];
    ud = [ud; trace(num).ud];
    num = num+1; 
end
%%
eta = 100000; % number of iterations 
lambda = 0.02; % tolerance 
gamma = 10; %the least number of inlayers
% % cd(['..', filesep, '..', filesep, '..']);
% FnMain(trace, x, ud, iter, threshDist, inNum);
tic
trace = FnClusterSegs(trace, x, ud);
toc
t1 = toc;
%%
for n =1:length(trace)
    trace(n).labels_trace = [trace(n).labels_trace;0];
end

ode = FnEstODE(trace);
[trace,label_guard] = FnLI(trace, eta, lambda, gamma);
t2 = toc;
pta_trace = FnPTA(trace);
pta_trace = pta_filter(pta_trace);
t3 = toc;
%%
FnGenerateHyst('automata_learning',label_guard, num_var, ode, pta_trace);

 addpath(['..', filesep, '..', filesep, 'src',filesep,'hyst', filesep, 'src', filesep, 'matlab']);
try
    SpaceExToStateflow('.\automata_learning.xml');
catch
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
    for i = 1:(num_var+1)
        chpoints = union(chpoints, changepoint(xout(1:(end-1),i)));
    end
    
    % remove redundant chpoints
    chpoints = filterindx(chpoints);
    xout_reduced= xout(1:(end-1), 1:(num_var+1));
    ud = xout(1:(end-1),end);

    trace.x = xout_reduced;
    trace.chpoints = chpoints;
    trace.ud = ud;
    trace.labels_num = []; 
    trace.labels_trace = [];  
end

function indx = changepoint(values)
    len = 4;
    diffs = diff(values(1:end-len,:)-values((len+1):end,:));
    indx = find(diffs<=-1.0|diffs>=1.0)+len;
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