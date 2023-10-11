function ode = FnEstNODE(trace)
global num_var 
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