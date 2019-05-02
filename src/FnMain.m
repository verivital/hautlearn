function FnMain(trace, x, ud, iter, threshDist, inNum, outputDir, lambda, num_var, num_ud, Ts)
dbstop at 14 in FnMain
trace = FnClusterSegs(trace, x, ud, lambda);

for n =1:length(trace)
    trace(n).labels_trace = [trace(n).labels_trace;0];
end

ode = FnEstODE(trace, Ts, num_var, num_ud);
[trace,label_guard] = FnLI(trace, iter, threshDist, inNum, num_var);
pta_trace = FnPTA(trace);
disp("Manually remove redundant invalid transitions in dataset *pta_trace*")

% FnGenerateHyst assumes it is in current directory
cd(fileparts(mfilename('fullpath')));
FnGenerateHyst([outputDir, filesep, 'automata_learning'],label_guard, num_var, ode, pta_trace);

% SpaceExToStateflow assumes it is in current directory
cd(['hyst', filesep, 'src', filesep, 'matlab']);
%addpath(['hyst', filesep, 'src', filesep, 'matlab']);

try
    SpaceExToStateflow([outputDir, filesep 'automata_learning.xml']);
catch
end
cd(outputDir);
end
