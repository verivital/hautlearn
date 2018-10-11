clc
clear

addpath('.\trainingdata')
addpath('..\..\src')
global lambda num_var num_ud
lambda = 0.00005;  
num_var = 3; num_ud = 1;
x = []; ud = [];
num =1;
for i = [2,5,6,7,8]
    load(['training', int2str(i),'.mat'])
    trace_temp = FnProcessData(xout);

    trace(num) = trace_temp;  
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end

trace = FnClusterSegs(trace, x, ud);
%%
ode = FnEstODE(trace);

iter = 1000; % number of iterations 
threshDist = 0.05; % tolerance 
inNum = 5; %the least number of inlayers
trace = FnLI(trace, iter, threshDist, inNum);
pta_trace = FnPTA(trace);