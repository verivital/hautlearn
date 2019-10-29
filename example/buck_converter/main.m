clc
clear

addpath(['.', filesep, 'trainingdata']);
addpath(['..', filesep, '..', filesep, 'src']);
global lambda num_var num_ud Ts winlen
Ts  = 0.00005;
lambda = 0.02;  winlen = 6;
num_var = 2; num_ud = 0;
num =1; x = []; ud = []; 

for i = 1:9
    load(['training', int2str(i),'.mat']);
    
    trace_temp = FnProcessData(xout, num_var);
    
    trace(num) = trace_temp;
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end
%%
iter = 1000; % number of iterations 
threshDist = 0.04; % tolerance 
inNum = 10; %the least number of inlayers
% % cd(['..', filesep, '..', filesep, '..']);
% FnMain(trace, x, ud, iter, threshDist, inNum);
tic
trace = FnClusterSegs(trace, x, ud);
toc
t1 = toc;
%%
for n =1:length(trace)
    trace(n).labels_trace = [trace(n).labels_trace;0];
end

ode = FnEstODE(trace);
[trace,label_guard] = FnLI(trace, iter, threshDist, inNum);
t2 = toc;
pta_trace = FnPTA(trace);
t3 = toc;

disp("Manually remove redundant invalid transitions in dataset *pta_trace*")
FnGenerateHyst('automata_learning',label_guard, num_var, ode, pta_trace);

addpath(['..', filesep, '..', filesep, 'src',filesep,'hyst', filesep, 'src', filesep, 'matlab']);
try
    SpaceExToStateflow('.\automata_learning.xml');
catch
end