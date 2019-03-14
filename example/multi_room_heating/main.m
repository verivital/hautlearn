clc
clear

addpath(['.', filesep, 'trainingdata']);
addpath(['..', filesep, '..', filesep, 'src']);
global lambda num_var num_ud
lambda = 0.00005;  
num_var = 3; num_ud = 1;
x = []; ud = [];
num =1;
for i = [2,5,6,8]
    load(['training', int2str(i),'.mat'])
    
    trace_temp = FnProcessData(xout, num_var, num_ud, num_var+num_ud, num_var, .04);

    trace(num) = trace_temp;  
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end

%%
iter = 1000; % number of iterations 
threshDist = 0.05; % tolerance 
inNum = 5; %the least number of inlayers
cd(['..', filesep, '..', filesep, '..']);
FnMain(trace, x, ud, iter, threshDist, inNum);