clc
clear

addpath(['.', filesep, 'trainingdata']);
addpath(['..', filesep, '..', filesep, 'src']);
global sigma num_var num_ud winlen Ts Time
Ts = 0.1; Time = false;
sigma = 0.00005;  winlen=1;
num_var = 3; num_ud = 1;
x = []; ud = [];
num =1;
for i = 1:4
    load(['training', int2str(i),'.mat'])
    
    trace_temp = FnProcessData(xout);

    trace(num) = trace_temp;  
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end

%%
tic
eta = 1000; % number of iterations 
lambda = 0.05; % tolerance 
gamma = 7; %the least number of inlayers

trace = FnClusterSegs(trace, x, ud);

t1 = toc;
for n =1:length(trace)
    trace(n).labels_trace = [trace(n).labels_trace;0];
end

ode = FnEstNODE(trace);
[trace,label_guard] = FnLI(trace, eta, lambda, gamma);
t2 = toc;
pta_trace = FnPTA(trace);
pta_trace = pta_filter(pta_trace);
t3 = toc;

FnHystNODE('automata_learning',label_guard, num_var, ode, pta_trace);

addpath(['..', filesep, '..', filesep, 'src',filesep,'hyst', filesep, 'src', filesep, 'matlab']);
try
    SpaceExToStateflow('.\automata_learning.xml');
catch
end
toc


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

function trace = FnProcessData(xout, num_var, num_ud)

    global num_var num_ud
    
    ichpoints = {};
    chpoints = [];
    for i = 1:num_var
        ichpoints(i) = {changepoint(xout(:,num_var+num_ud+i))};
        chpoints = union(chpoints, changepoint(xout(:,num_var+num_ud+i)));
    end
    trace.ichpoints = ichpoints;
    trace.chpoints = chpoints;
    trace.x = xout(:,1:3);
    trace.ud = xout(:,(num_var+1):(num_var+num_ud));
    trace.labels_num = []; 
    trace.labels_trace = []; 
    
end

function [points_num] = changepoint(values)

  valdif1 = [values(1); diff(values)];
  %valdif2 =  diff(valdif1);
  indx = find(abs(valdif1) >=0.04);
  points_num = union(1,[indx; length(values)]);
end
  