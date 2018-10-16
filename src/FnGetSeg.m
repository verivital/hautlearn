function seg = FnGetSeg(indx, trace)
    t = 1;
    seg = [];
    for i = 1:length(trace)
        for j = 1:length(trace(i).labels_trace)-1
            if t == indx 
                x_temp = trace(i).x(trace(i).chpoints(j):trace(i).chpoints(j+1),:);
                seg = x_temp;
                return;
            end
            t = t+1;
        end
    end
end