function trace = FnProcessData(xout, num_var, num_ud, chpoints_offset, chpoints_cols, chpoints_tolerance)

    chpoints = [];
    for i = 1:chpoints_cols
        chpoints = union(chpoints, changepoint(xout(:,chpoints_offset+i), chpoints_tolerance));
    end

    trace.chpoints = chpoints;
    trace.x = xout(:,1:num_var);
    if num_ud>0
        trace.ud = xout(:,(num_var+1):(num_var+num_ud));
    else
        trace.ud = [];
    end
    trace.labels_num = []; 
    trace.labels_trace = []; 
end

function points_num = changepoint(values, tolerance)

  valdif1 = [values(1); diff(values)];
  indx = find(abs(valdif1) >= tolerance);
  points_num = union(1,[indx; length(values)]);
end