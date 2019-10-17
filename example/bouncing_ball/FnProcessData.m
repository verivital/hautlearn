function trace = FnProcessData(xout, num_var, num_ud)

    chpoints = [];
    for i = 1:num_var
        chpoints = union(chpoints, changepoint(xout(:,i)));
    end
    trace.chpoints = chpoints;
    e = (2*rand(size(xout(:,1:num_var),1),num_var)-1)*0.1;
    trace.x = xout(:,1:num_var)+e;
    trace.ud = [];
    trace.labels_num = []; 
    trace.labels_trace = []; 
end

function points_num = changepoint(values)
  valdif1 = diff([values(1); values]);
  indx = find(abs(valdif1) >=5);
  points_num = union(1,[indx; length(values)]);
end