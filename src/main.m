%clear all;

% opt_learn = 0;
% Ts = 0.1;
% num_var = 4; num_ud = 0;
% Ts = 0.1
% if opt_learn
%     addpath(['..', filesep, 'example', filesep, 'navigation', filesep]);
%     addpath(['..', filesep, 'example', filesep, 'navigation', filesep, 'trainingdata1.1']);
%     addpath(['.', filesep]);
%     x = []; ud = []; 
%     num =1;
%     global lambda num_var num_ud Ts
%     lambda = 0.000001;  
%     num_var = 4; num_ud = 0;
%     for i = 1:5
%         load(['test', int2str(i),'.mat']);
% 
%         trace_temp = FnProcessData(xout, num_var, num_ud);
%         chpoints = trace_temp.chpoints;
%         if min(diff(chpoints))>=10
%             trace(num) = trace_temp;
%             x = [x; trace(num).x];
%             ud = [ud; trace(num).ud];
%             num = num+1; 
%         end
%     end
% 
%     trace = FnClusterSegs(trace, x, ud);
%     for n =1:length(trace)
%         trace(n).labels_trace = [trace(n).labels_trace;0];
%     end
%     %%
% end
% ode = FnEstODE(trace);

% iter = 1000; % number of iterations 
% threshDist = 0.01; % tolerance 
% inNum = 5; %the least number of inlayers
% [trace,label_guard] = FnLI(trace, iter, threshDist, inNum);
% pta_trace = FnPTA(trace);

save('tmp');
FnGenerateHyst('unimportant', 'tmp');
delete tmp.mat;

cd(['hyst', filesep, 'src', filesep, 'matlab']);
try
    SpaceExToStateflow(['..', filesep, '..', filesep, '..', filesep, 'automata_learning.xml']);
catch
end
cd(['..', filesep, '..', filesep, '..']);