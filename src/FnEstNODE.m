function ode = FnEstNODE(trace)
global Ts num_var num_ud
len_labels = length(trace(1).labels_num);
for label = 1:len_labels
    x_seg = [];
    x_seg_plus = [];
    ud_seg = [];
    for j = 1:length(trace)
        labels_trace = trace(j).labels_trace;
        idx = find(labels_trace == label);
        x = trace(j).x(:,1:num_var);
        ud = trace(j).ud;
         
        startj = trace(j).chpoints(idx);
        endj = trace(j).chpoints(idx+1)-1;
        
        for n = 1:length(startj)
            x_seg = [x_seg, x(startj(n):(endj(n)-1), :)'];
            if isempty(ud)
                ud_seg = [ud_seg, ones(1, (endj(n)- startj(n)))];
            else
                ud_seg = [ud_seg, [ud(startj(n):(endj(n)-1), :)'; ones(1, (endj(n)- startj(n)))]];
            end
            x_seg_plus = [x_seg_plus, x((startj(n)+1):endj(n), :)'];
        end
    end
    
    dlnet = FnEst_node(x_seg_plus);
    ode(label) = dlnet;
end

%% Some notes
% we need to combine the cluster data into different time-series, do some
% type of k-1 validation, and use that model for each trace.
% We are going to have to do that manually
% For now, we could  estimate different models for each trace? How is it
% done here?
%
% Let's analyze how the neural ode training is done, and then we can think
% about it. Is it done by picking two points in the set and computing
% integration between them? It does not make sense to simply concatenate
% traces because that may imply some jumps in the data that we don't
% want...
%
% I'm also very confused as of how the ODEs are estimated in the hautlearn
% framework