clc
clear

addpath(['.', filesep, 'trainingdata']);
addpath(['..', filesep, '..', filesep, 'src']);
global lambda num_var num_ud Ts 
lambda = 0.000001;
num_var = 3; num_ud = 0; Ts  = 0.001;
x = []; ud = []; 
num =1;
for i = 1:1
    load(['training', int2str(i),'.mat']);
    
    trace_temp = FnProcessData(xout, num_var, num_ud);
    chpoints = trace_temp.chpoints;
    
    trace(num) = trace_temp;
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end
%%
iter = 1000; % number of iterations 
threshDist = 0.01; % tolerance 
inNum = 5; %the least number of inlayers
cd(['..', filesep, '..', filesep, '..']);
FnMain(trace, x, ud, iter, threshDist, inNum);