function trace = FnClusterSegs(trace, x, ud)

    segIndex = [0,0]; 
    for i=1:length(trace)  
        chpoints = (trace(i).chpoints);
        chsegments = [chpoints(1:end-1), chpoints(2:end)];    
        segIndex = [segIndex; segIndex(end,2) + chsegments]; 
    end
    segIndex(1,:) = [];
    seglength = diff(segIndex')'+1;
    [sorted_length, index] = sort(seglength,'descend');
    sorted_index = segIndex(index,:);

    mix_label= FnRecursive3(x',ud',sorted_index);
    labels = FnIndxarrange(mix_label, index);
    labels_num = unique(1,labels);
    cluster_segs = sortrows(labels,1); %
 %%   
    for i=1:length(trace)
        chpoints = trace(i).chpoints;
        len_segs = length(chpoints)-1;
        trace(i).labels_num = labels_num;
        trace(i).labels_trace = cluster_segs(1:len_segs,2);
        cluster_segs(1:len_segs,:) = [];
    end

    



