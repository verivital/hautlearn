function trace = FnProcessData(xout, num_var, num_ud, chpoints_offset, chpoints_cols, chpoints_tolerance)

    chpoints = [];
    for i = 1:chpoints_cols
        chpoints = union(chpoints, changepoint(xout(:,chpoints_offset+i), chpoints_tolerance));
    end
    
    % remove redundant chpoints
    dif_chpoints = diff(chpoints);
    ids = find(dif_chpoints==1);
    chpoints(ids,:) = [];
    xout_reduced= xout(:, 1:num_var);

    trace.x = xout_reduced;
    trace.chpoints = chpoints;
    trace.ud = [];
    trace.labels_num = []; 
    trace.labels_trace = [];  
end

function points_num = changepoint(values, tolerance)

  valdif1 = [values(1); diff(values)];
  indx = find(abs(valdif1) >= tolerance);
  points_num = union(1,[indx; length(values)]);
end