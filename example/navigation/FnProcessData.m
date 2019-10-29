function trace = FnProcessData(xout, num_var, num_ud)

    chpoints = [];
    for i = 1:num_var
        chpoints = union(chpoints, changepoint(xout(:,i)));
    end
    
    idx = find(diff(chpoints)<=2);
    chpoints(idx)=[];
    trace.chpoints = chpoints;
    e = (2*rand(size(xout(:,1:num_var),1),num_var)-1)*0.005;
    trace.x = xout(:,1:num_var);%+e;
    trace.ud = [];
    trace.labels_num = []; 
    trace.labels_trace = []; 
    
   
end

function points_num = changepoint(values)

  valdif1 = [values(1); diff(values)];
  valdif2 =  diff(valdif1);
  indx = find(abs(valdif2) >=0.003);
  points_num = union(1,[indx; length(values)]);
end