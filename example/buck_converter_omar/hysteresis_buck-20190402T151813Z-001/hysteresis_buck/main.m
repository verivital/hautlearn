clc
% clear

addpath(['..', filesep, '..', filesep,'..', filesep,'..', filesep, 'src']);
global lambda num_var num_ud Ts winlen
Ts  = 0.00005;
lambda = 0.01;  winlen = 15;
num_var = 2; num_ud = 0;
num =1; x = []; ud = []; 

for i = 1:1
    load('exp_r10.mat');
    
    step = 5;
    iexp=I_test1(17309:step:27309,end);% current data from Buck converter
    vexp=V_test1(17309:step:27309,end);% voltage data from Buck converter
    
    xout = [iexp, vexp];
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
% cd(['..', filesep, '..', filesep, '..']);
% FnMain(trace, x, ud, iter, threshDist, inNum);
trace = FnClusterSegs(trace, x, ud);

for n =1:length(trace)
    trace(n).labels_trace = [trace(n).labels_trace;0];
end

ode = FnEstODE(trace);
[trace,label_guard] = FnLI(trace, iter, threshDist, inNum);
pta_trace = FnPTA(trace);
%%
disp("Manually remove redundant invalid transitions in dataset *pta_trace*")
FnGenerateHyst('automata_learning',label_guard, num_var, ode, pta_trace);
%%
addpath(['..', filesep, '..', filesep, 'src',filesep,'hyst', filesep, 'src', filesep, 'matlab']);
try
    SpaceExToStateflow('.\automata_learning.xml');
catch
end