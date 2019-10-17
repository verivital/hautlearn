clc
clear

<<<<<<< HEAD
addpath('.\trainingdata');
addpath('..\..\src')
=======
addpath(['.', filesep, 'trainingdata']);
addpath(['..', filesep, '..', filesep, 'src']);
lambda = 0.00001;  
num_var = 2; num_ud = 0; Ts = 0.1;
>>>>>>> c4f570113d445d24db597b6c610b26180c69b578
x = []; ud = []; 
num =1;
global lambda num_var num_ud Ts
Ts = 0.1;
lambda = 0.00001;  
num_var = 2; num_ud = 0;
for i = 1:10
    load(['training', int2str(i),'.mat']);
    
    trace_temp = FnProcessData(xout, num_var, num_ud);
    chpoints = trace_temp.chpoints;
 
    trace(num) = trace_temp;
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end
%%
trace = FnClusterSegs(trace, x, ud);
%%
ode = FnEstODE(trace);
%%
iter = 1000; % number of iterations 
threshDist = 0.001; % tolerance 
inNum = 5; %the least number of inlayers
<<<<<<< HEAD
[trace,label_guard] = FnLI(trace, iter, threshDist, inNum);
pta_trace = FnPTA(trace);
=======
outputDir=pwd;
FnMain(trace, x, ud, iter, threshDist, inNum, outputDir, lambda, num_var, num_ud, Ts);
>>>>>>> c4f570113d445d24db597b6c610b26180c69b578
