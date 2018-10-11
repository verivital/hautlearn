function points_num = changepoint(values)

  valdif1 = [values(1); diff(values)];
  valdif2 =  diff(valdif1);
  indx = find(abs(valdif2) >=0.003);
  points_num = union(1,[indx; length(values)]);
end
  