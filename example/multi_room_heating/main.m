clc
clear

addpath(['.', filesep, 'trainingdata']);
addpath(['..', filesep, '..', filesep, 'src']);
global lambda num_var num_ud winlen Ts
Ts = 0.1;
lambda = 0.00005;  winlen=1;
num_var = 3; num_ud = 1;
x = []; ud = [];
num =1;
for i = [2,5,6,8]
    load(['training', int2str(i),'.mat'])
    
    trace_temp = FnProcessData(xout);

    trace(num) = trace_temp;  
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end

%%
tic
iter = 1000; % number of iterations 
threshDist = 0.05; % tolerance 
inNum = 10; %the least number of inlayers
% % cd(['..', filesep, '..', filesep, '..']);
% FnMain(trace, x, ud, iter, threshDist, inNum);
% trace = FnClusterSegs(trace, x, ud);
% 
% t1 = toc;
% for n =1:length(trace)
%     trace(n).labels_trace = [trace(n).labels_trace;0];
% end

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
toc

%save history2.mat