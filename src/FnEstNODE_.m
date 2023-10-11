function ode = FnEstNODE_(trace)
global num_var 
len_labels = length(trace(1).labels_num);
for label = 1:len_labels
    x_seg_plus = {};
    traj_length = [];
    tj = 1; % Keep track of number of different traces
    for j = 1:length(trace)
        labels_trace = trace(j).labels_trace;
        idx = find(labels_trace == label);
        x = trace(j).x(:,1:num_var);
         
        startj = trace(j).chpoints(idx);
        endj = trace(j).chpoints(idx+1)-1;
        
        for n = 1:length(startj)
            x_seg_plus{tj} = x((startj(n)+1):endj(n), :)';
            tj = tj+1;
            traj_length = [traj_length, abs(startj(n)+1-endj(n))];
        end
    end
    min_length = min(traj_length);
    trajs = zeros(num_var,length(x_seg_plus),min_length);
    for k=1:length(x_seg_plus)
        x_seg = x_seg_plus{k};
        trajs(:,k,:) = x_seg(:,1:min_length);
    end
    dlnet = FnEst_node_(trajs);
    ode{label} = dlnet;
end