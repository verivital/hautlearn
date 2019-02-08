%function FnEstCondition(trace)
addpath(['..', filesep, 'linear_inequality'])
num_var = 3;
num_ud = 1;
xchpoints = [];
for i = 1:11
    load(['HeatingData', int2str(i),'test','.mat']);
    xout = FnLoadT(TempHeat);
    trace_temp = FnProcessData(xout, num_var, num_ud);
    labels_trace = FnPredictLabel(trace_temp, ode);
    
    trace_temp.labels_trace = labels_trace;
    xchpoints =[xchpoints; x(chpoints, :)];
end

for n = 1:length(trace)
    x = trace(n).x;
    chpoints = trace(n).chpoints;
    xchpoints =[xchpoints; x(chpoints, :)];
end

min_left = 10000;
for n = 1:10
    num = 3; % number of continuous variables
    iter = 10000; % number of iterations 
    threshDist = 0.1; % tolerance 
    inNum = 50; %the least number of inlayers
    [wb, inlayer, leftover] = FnEstLI(xchpoints, num,iter,threshDist,inNum);
    if size(leftover,1)<min_left
        min_left = size(leftover,1);
        best_wb = wb;
        best_inlayer = inlayer;
    end
end
min_left
best_wb