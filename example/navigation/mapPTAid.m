ids = [];
for i = 1:length(pta_trace)
    ids(end+1) = pta_trace(i).id1;
    ids(end+1) = pta_trace(i).id2;
end
[uniq_ids, ia,ic ]= unique(ids);

num=1;
for i = 1:length(pta_trace)
    pta_trace(i).id1 = ic(num);
    num = num+1;
    pta_trace(i).id2 = ic(num);
    num = num+1;
end