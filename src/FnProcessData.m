function trace = FnProcessData(xout)
    [vx, vy, x, y, chpoints1, chpoints2] = FnLoadData(xout);
    trace.vx = vx;
    trace.vy = vy;
    trace.x = x;
    trace.y = y;
    trace.labels = []; % segments' label
    % vx
    if length(chpoints1) == 1 % no changepoints
       trace.vx_segments(1) = {vx};
       trace.xchpoints = [1,length(vx)]; % the end of data trace
    else
        for n = 1: length(chpoints1)-1
            trace.vx_segments(n) = {vx(chpoints1(n):chpoints1(n+1))}; 
        end
        trace.xchpoints = chpoints1;
    end
    
    %vy
    if length(chpoints2) == 1 % no changepoints
       trace.vy_segments(1) = {vy};
       trace.ychpoints = [1,length(vy)]; % the end of data trace
    else
        for n = 1: length(chpoints2)-1
            trace.vy_segments(n) = {vy(chpoints2(n):chpoints2(n+1))}; 
        end
        trace.ychpoints = chpoints2;
    end
    
    chpoints = union(trace.xchpoints, trace.ychpoints);
    trace.chpoints = chpoints;
end