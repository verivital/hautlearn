function points_num = changepoint(values)

  valdif1 = diff([values(1); values]);
  indx = find(abs(valdif1) >=5);
  points_num = union(1,[indx; length(values)]);
end
  