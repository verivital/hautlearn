function labels = FnIndxarrange(cluster_idx, index)
    newindx = [];
    NOne = find(cluster_idx == -1);
    labels = ones(NOne(1)-1,1);
    nNOne = length(NOne);
    indxx = 1:(length(cluster_idx) - nNOne);
    
    starti = 1;
    endi = NOne(1) - 1;
    indx_temp = indxx(cluster_idx(starti : endi));
    idx = indx_temp;
    indxx = setdiff(indxx, indx_temp);
    for n = 2:nNOne
        labels = [labels; n*ones(NOne(n)- NOne(n-1)-1,1);];
        starti = NOne(n -1) + 1;
        endi = NOne(n) - 1;
        indx_temp = indxx(cluster_idx(starti : endi)); 
        idx = [idx, indx_temp];
        indxx = setdiff(indxx, indx_temp);
        
    end
    idx = index(idx);
    labels = [idx, labels];
end