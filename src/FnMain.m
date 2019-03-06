function FnMain(trace, x, ud, iter, threshDist, inNum)

global num_var;
trace = FnClusterSegs(trace, x, ud);
%%% for buck_converter, navigation
% for n =1:length(trace)
%     trace(n).labels_trace = [trace(n).labels_trace;0];
% end
%%%
ode = FnEstODE(trace);
[trace,label_guard] = FnLI(trace, iter, threshDist, inNum);
pta_trace = FnPTA(trace);
FnGenerateHyst('automata_learning',label_guard, num_var, ode, pta_trace);

cd(['hyst', filesep, 'src', filesep, 'matlab']);
try
    SpaceExToStateflow(['..', filesep, '..', filesep, '..', filesep, 'automata_learning.xml']);
catch
end
cd(['..', filesep, '..', filesep, '..']);
end