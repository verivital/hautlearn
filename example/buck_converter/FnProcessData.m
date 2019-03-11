function trace = FnProcessData(xout, num_var, num_ud)

%%%    ichpoints = {};
    chpoints = [];
    for i = 1:num_var
%%%        ichpoints(i) = {changepoint(xout(:,i))};
        chpoints = union(chpoints, changepoint(xout(:,4)));
    end
%%%    trace.ichpoints = ichpoints;
    trace.chpoints = chpoints;
    trace.x = xout(:,1:num_var);
    trace.ud = [];
    trace.labels_num = []; 
    trace.labels_trace = []; 
    
%     % x1
%     for n = 1: length(chpoint1)-1
%         trace.x1_segments(n) = {x1(chpoint1(n):chpoint1(n+1))}; 
%     end
% 
%     % x2
%     for n = 1: length(chpoint2)-1
%         trace.x2_segments(n) = {x2(chpoint2(n):chpoint2(n+1))}; 
%     end
% 
%     % x3
%     for n = 1: length(chpoint3)-1
%         trace.x3_segments(n) = {x3(chpoint3(n):chpoint3(n+1))}; 
%     end
   
end

function points_num = changepoint(values)

  valdif1 = [values(1); diff(values)];
  valdif2 =  diff(valdif1);
  indx = find(abs(valdif1) >=0.5);
  points_num = union(1,[indx; length(values)]);
end