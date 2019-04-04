clc
clear

addpath(['.', filesep, 'trainingdata']);
addpath(['..', filesep, '..', filesep, 'src']);
global lambda num_var num_ud Ts 
Ts  = 0.00005;
lambda = 0.001;  
num_var = 2; num_ud = 0;
num =1; x = []; ud = []; 

for i = 1:10
    load(['training', int2str(i),'.mat']);
    
    trace_temp = FnProcessData(xout, num_var);
    
    trace(num) = trace_temp;
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end
%%
iter = 1000; % number of iterations 
threshDist = 0.05; % tolerance 
inNum = 10; %the least number of inlayers
outputDir=pwd;
FnMain(trace, x, ud, iter, threshDist, inNum, outputDir);