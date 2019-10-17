clc
clear

addpath(['.', filesep, 'nosegments']);
addpath(['..', filesep, '..', filesep, 'src']);
global lambda num_var num_ud Ts winlen
Ts  = 0.00005;
lambda = 0.6;  
num_var = 2; num_ud = 0; winlen = 6;
num =1; x = []; ud = [];

for i = 1%[0,1,2,30,31]
%     file0 = xlsread([eID{n},int2str(i),'_combined.csv']);
    file0 = xlsread('vc120il552mode1vref15nominal0.csv_segment0.csv');
    PLANT_VC_low = file0(:,2);
    CTRL_Model_low = file0(:,3);
    %PLANT_Model_low = file0(:,2);
    %PLANT_SimulationTime_low = file0(:,1);
    PLANT_VC_high = file0(:,6);
    %CTRL_Model_high = file0(:,8);
    %PLANT_Model_high = file0(:,7);
    %PLANT_SimulationTime_high = file0(:,5);
    
    xout = [PLANT_VC_low, PLANT_VC_high, CTRL_Model_low];
    xstep = 15; step_vector = [1:xstep:size(xout,1)];
    xout = xout(step_vector,:);
    
    trace_temp = FnProcessData(xout, num_var);
    plot(xout)
    i
    trace_temp.chpoints
    
    trace(num) = trace_temp;
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end
%%
iter = 1000; % number of iterations 
threshDist = 0.05; % tolerance 
inNum = 4; %the least number of inlayers
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