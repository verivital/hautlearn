clc
clear

addpath(['.', filesep, 'trainingdata3']);
addpath(['..', filesep, '..', filesep, 'src']);
global lambda num_var num_ud winlen
lambda = 0.001;  winlen = 10;
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
% % cd(['..', filesep, '..', filesep, '..']);
% FnMain(trace, x, ud, iter, threshDist, inNum);
trace = FnClusterSegs(trace, x, ud);

for n =1:length(trace)
    trace(n).labels_trace = [trace(n).labels_trace;0];
end
%%
ode = FnEstODE(trace);
[trace,label_guard] = FnLI(trace, iter, threshDist, inNum);
pta_trace = FnPTA(trace);
disp("Manually remove redundant invalid transitions in dataset *pta_trace*")
FnGenerateHyst('automata_learning',label_guard, num_var, ode, pta_trace);

addpath(['..', filesep, '..', filesep, 'src',filesep,'hyst', filesep, 'src', filesep, 'matlab']);
try
    SpaceExToStateflow('.\automata_learning.xml');
catch
end