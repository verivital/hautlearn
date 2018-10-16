clc
clear

addpath('.\trainingdata3');
addpath('..\..\src')
x = []; ud = []; 
num =1;
global lambda num_var num_ud
lambda = 0.000001;  
num_var = 4; num_ud = 0;
for i = 1:66
    load(['test', int2str(i),'.mat']);
    
    trace_temp = FnProcessData(xout, num_var, num_ud);
    chpoints = trace_temp.chpoints;
    if min(diff(chpoints))>=10
        trace(num) = trace_temp;
        x = [x; trace(num).x];
        ud = [ud; trace(num).ud];
        num = num+1; 
    end
end

trace = FnClusterSegs(trace, x, ud);
for n =1:length(trace)
    trace(n).labels_trace = [trace(n).labels_trace;0];
end
%%
ode = FnEstODE(trace);

iter = 1000; % number of iterations 
threshDist = 0.008; % tolerance 
inNum = 5; %the least number of inlayers
[trace,label_guard] = FnLI(trace, iter, threshDist, inNum);
pta_trace = FnPTA(trace);