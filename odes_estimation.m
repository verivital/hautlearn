for label = 1:3
    xt = [];
    xt_plus = [];
    for j = 1:length(trace)
        labels = trace(j).labels;
        idx = find(labels == label);
        vx_segs = trace(j).vx;
        vy_segs = trace(j).vy;
        
        startj = trace(j).chpoints(idx);
        endj = trace(j).chpoints(idx+1);
        
        vx_seg_temp = vx_segs(startj:endj)';
        vy_seg_temp = vy_segs(startj:endj)';      
        xt = [xt,[vx_seg_temp(1:end-1); vy_seg_temp(1:end-1); ones(1, length(vy_seg_temp)-1)]];
        xt_plus = [xt_plus, [vx_seg_temp(2:end); vy_seg_temp(2:end)]];
    end
    label
    A_Bu = mrdivide(xt_plus,xt)
    
end