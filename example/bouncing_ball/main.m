clc
clear

addpath(['.', filesep, 'trainingdata']);
addpath(['..', filesep, '..', filesep, 'src']);
global lambda num_var num_ud Ts; 
lambda = 0.00001;  
num_var = 2; num_ud = 0; Ts = 0.1;
x = []; ud = []; 
num =1;
for i = 1:10
    load(['training', int2str(i),'.mat']);
    
    trace_temp = FnProcessData(xout, num_var, num_ud, 1, 1, 5);
 
    trace(num) = trace_temp;
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end
%%
iter = 1000; % number of iterations 
threshDist = 0.001; % tolerance 
inNum = 5; %the least number of inlayers
outputDir=pwd;
FnMain(trace, x, ud, iter, threshDist, inNum, outputDir);