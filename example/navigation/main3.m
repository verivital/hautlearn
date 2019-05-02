clc
clear

addpath(['.', filesep, 'trainingdata3']);
addpath(['..', filesep, '..', filesep, 'src']);
lambda = 0.000001;  
num_var = 4; num_ud = 0;
x = []; ud = []; 
num =1;
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

%%

iter = 1000; % number of iterations 
threshDist = 0.008; % tolerance 
inNum = 5; %the least number of inlayers
outputDir=pwd;
FnMain(trace, x, ud, iter, threshDist, inNum, outputDir, lambda, num_var, num_ud, 0);