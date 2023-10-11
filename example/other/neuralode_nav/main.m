clc
clear

% addpath(['.', filesep, 'trainingdata1.1']);
% addpath(['..', filesep, '..', filesep, 'src']);
global sigma num_var num_ud Ts winlen Time
sigma = 0.000005;  winlen = 10;
num_var = 4; num_ud = 0; Ts  = 0.01; Time = false;
x = []; ud = []; 
num =1;
for i = 1:81 
    
    load(['../navigation/trainingdata1.1/test', int2str(i),'.mat']);
    
    trace_temp = FnProcessData(xout, num_var, num_ud);
    chpoints = trace_temp.chpoints;
    if min(diff(chpoints))>=10
        trace(num) = trace_temp;
        x = [x; trace(num).x];
        ud = [ud; trace(num).ud];
        num = num+1; 
    end
end

%%

eta = 1000; % number of iterations 
lambda = 0.01; % tolerance 
gamma = 10; %the least number of inlayers

tic
trace = FnClusterSegs(trace, x, ud);
t1 = toc;
% 
for n =1:length(trace)
    trace(n).labels_trace = [trace(n).labels_trace;0];
end
%%
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


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
     
        if (~ismember(pta_trace(nn).id1, id1s)) && (pta_trace(nn).id1~=1)
            pta_trace(nn) = [];
        else
            nn = nn+1;
        end
    end
    pta_trace_new = pta_trace;
end

function trace = FnProcessData(xout, num_var, num_ud)

    chpoints = [];
    for i = 1:num_var
        chpoints = union(chpoints, changepoint(xout(:,i)));
    end
    
    idx = find(diff(chpoints)<=2);
    chpoints(idx)=[];
    trace.chpoints = chpoints;
    e = (2*rand(size(xout(:,1:num_var),1),num_var)-1)*0.005;
    trace.x = xout(:,1:num_var);%+e;
    trace.ud = [];
    trace.labels_num = []; 
    trace.labels_trace = []; 
    
   
end

function points_num = changepoint(values)

  valdif1 = [values(1); diff(values)];
  valdif2 =  diff(valdif1);
  indx = find(abs(valdif2) >=0.003);
  points_num = union(1,[indx; length(values)]);
end