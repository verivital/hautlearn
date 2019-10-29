function trace = FnProcessData(xout, num_var, num_ud)

    chpoints = [];
    for i = 1:num_var
        chpoints = union(chpoints, changepoint(xout(:,i)));
    end
    
    % remove redundant chpoints
    dif_chpoints = diff(chpoints);
    ids = find(dif_chpoints<=2);
    chpoints(ids,:) = [];
    xout_reduced= xout(:, 1:num_var);

    e = (2*rand(size(xout_reduced,1),2)-1)*0.05; 
    trace.x = xout_reduced + e;
    trace.chpoints = chpoints;
    trace.ud = [];
    trace.labels_num = []; 
    trace.labels_trace = [];  
end

function points_num = changepoint(values)
  valdif1 = [values(1); diff(values)];
  valdif2 =  diff(valdif1);
  indx = find(abs(valdif2) >=0.03);
  points_num = union(1,[indx; length(values)]);
end