function trace = FnClusterSegs(trace, x, ud)

    segIndex = [0,0]; 
    for i=1:length(trace)  
        chpoints = (trace(i).chpoints);
        chsegments = [chpoints(1:end-1), chpoints(2:end)];
        chsegments(2:end,1) = chsegments(2:end,1)+1;
        segIndex = [segIndex; segIndex(end,2) + chsegments]; 
    end
    segIndex(1,:) = [];
    seglength = diff(segIndex')'+1;
    [sorted_length, index] = sort(seglength,'descend');
    sorted_index = segIndex(index,:);

    mix_label= FnRecursive(x',ud',sorted_index);
    labels = FnIndxarrange(mix_label, index);
    labels_num = unique(labels(:,2));
    cluster_segs = sortrows(labels,1); %
 %%   
    for i=1:length(trace)
        chpoints = trace(i).chpoints;
        len_segs = length(chpoints)-1;
        trace(i).labels_num = labels_num;
        trace(i).labels_trace = cluster_segs(1:len_segs,2);
        cluster_segs(1:len_segs,:) = [];
    end
end
    
function labels = FnIndxarrange(cluster_idx, index)
    newindx = [];
    NOne = find(cluster_idx == -1);
    labels = ones(NOne(1)-1,1);
    nNOne = length(NOne);
    indxx = 1:length(index);%(length(cluster_idx) - nNOne);
    
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

function indx = FnRecursive(x,ud,chpoints)  
    global sigma winlen;
    
    if size(x,1) ~= 0
        
        xc = [];
        udc = [];
        chpc = 1;
        indx = 1;
        unindx = [];
        
        num_segments = size(chpoints,1);
        if num_segments ==1
            indx = [1;-1];
            return;
        end
        
        %variable number
        num_var = size(x,1);
        %size of ud
        num_ud = size(ud,1);
        
        index_start1 = chpoints(1,1);
        index_end1 = chpoints(1,2);
        xseg1 = x(:,index_start1: index_end1);
        xk1 = xseg1(:,1:end - winlen); 
        ud1 = [];
        if num_ud ==0
            ud1 = ones(1,size(xk1,2));
        else
            udseg1 = ud(:,index_start1: index_end1);
            ud1 = udseg1(:,1:end - winlen);
            ud1 = [ud1; ones(1,size(xk1,2))];
        end
        xki1 =  xseg1(:,winlen+1:end);
        
        Ok = [xk1;ud1];
        Oki = xki1;
        
        setlmis([]); % Set a new LMI
        structV = [1, 1+num_ud+num_var]; %matrix structure
        for i = 1:num_var % create Vi matrix for each variable
            V{i} = lmivar(2, structV);
        end
        
        error_t = (sigma * size(Oki,2))^2; %error tolerance
        for i = 1:size(Oki,1)
            n = (i+(1-1)*num_var);
            lmiterm([-n, 1,1,0],1);
            lmiterm([-n, 2,1,V{i}],1,Ok)
            lmiterm([-n, 2,1,0],-Oki(i,:))
            lmiterm([-n, 2,2,0], error_t)
        end
        lmi = getlmis; 
        
             
        for j = 2:num_segments
            disp([int2str(j),'/', int2str(num_segments)])
            index_startj = chpoints(j,1);
            index_endj = chpoints(j,2);
                       
            xsegj = x(:,index_startj: index_endj);
            %plot(xsegj')
            xkj = xsegj(:,1:end - winlen);
            xkij = [];
            xkij = xsegj(:, winlen+1:end);
            
            if num_ud == 0
                udj = ones(1,size(xkj,2));
            else
                udsegj = ud(:,index_startj: index_endj);
                udj = udsegj(:,1:end - winlen);
                udj = [udj; ones(1,size(xkj,2))];
            end

            Okj = [xkj; udj];
            Okij = xkij;
            
            setlmis(lmi);
            error_tj = (sigma * size(Okj,2))^2;
            for i = 1:num_var
                n = (i+(j-1)*num_var);
                lmiterm([-n, 1,1,0],1);
                lmiterm([-n, 2,1,V{i}],1,Okj)
                lmiterm([-n, 2,1,0],-Okij(i,:))
                lmiterm([-n, 2,2,0], error_tj)
            end
            lmi = getlmis; 
            newlmi = lmi;  
            [tmin,xfeas] = feasp(newlmi);
            %toc
            %v = dec2mat(Ilmi,xfeas,V);
            if (tmin <=0)     
                if num_segments ==2 
                    indx = [1;2;-1];
                    return;
                end
                indx = [indx; j]; 
                lenj = length(Okj);
                len = length(Ok);
                for i = 1:size(Okij,1)
                    n = (j-1)*num_var+i;
                    lmi = dellmi(lmi,n);
                end
            else
                if num_segments ==2 
                    indx = [1;-1;1;-1];
                    return;
                end
                for i = 1:size(Okij,1)
                    n = (j-1)*num_var+i;
                    lmi = dellmi(lmi,n);
                end
                xc = [xc, xsegj]; 
                if num_ud ==0
                    udc = [];
                else
                    udc = [udc, udsegj];
                end
                if chpc == 1
                    chpc = [1,size(xsegj,2)];
                else
                    chpc = [chpc;[chpc(end)+1,size(xsegj,2)+ chpc(end)]];
                end
            end
        end
      
        indx = [indx; -1];
        
        indxx = FnRecursive(xc,udc,chpc);
        indx = [indx; indxx];
         
    else
        indx = [];
    end
end