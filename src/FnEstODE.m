function ode = FnEstODE(trace)
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
    
    % it is to check if it is a reset action
    if size(x_seg,2)/length(trace)==2
        A_Bu = mrdivide(x_seg_plus,[x_seg;ud_seg]);
        dA = A_Bu(:,1:num_var);
        dB = A_Bu(:,num_var+1:end);
        % -1 indicate the ode is discrete and is used for variable reset
        ode(label) = {[dA, dB, -ones(num_var,1)]};
        return
    end
    
    A_Bu = mrdivide(x_seg_plus,[x_seg;ud_seg]);
    dA = A_Bu(:,1:num_var);
    dB = A_Bu(:,num_var+1:end);
    dC = eye(num_var); dD = zeros(num_var, num_ud+1);
    sysd = ss(dA, dB, dC, dD, Ts);
    sysc = d2c(sysd);
    ode(label) = {[sysc.A, sysc.B]};
end
