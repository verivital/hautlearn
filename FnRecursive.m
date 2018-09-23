function indx = FnRecursive(i,x,ud,chpoints, winlen)  
    global lambda;
    
    if size(x,1) ~= 0
        
        xc = [];
        udc = [];
        chpc = 1;
        indx = 1;
        unindx = [];
        
        num_segments = length(chpoints);
        index_start1 = chpoints(1,1);
        index_end1 = chpoints(1,2);
        seg1 = x(index_start1: index_end1, :);
        %chose x1
        C1 = [1;0];
        %chose x1
        C2 = [0;1];
        
        xk1 = seg1(1:end - winlen, :); % 
        xki1 = seg1(winlen+1:end, :);
        Ok1 = [xk1, ones(size(xk1,1),winlen)];
        Oki1 = xki1;
        
        %1st LMI
        lam1 = (lambda * eye(1))^2;
        setlmis([]);
        structV = [winlen+2, 2];
        V = lmivar(2, structV);
            lmiterm([-1,1,1, 0], 1);
            lmiterm([-1,1,2, 0], 0);
            lmiterm([-1,1,3, V], Ok1, C1);
            lmiterm([-1,1,3, 0], -Oki1*C1);
            lmiterm([-1,1,4, 0], 0);
            lmiterm([-1,2,2, 0], 1);
            lmiterm([-1,2,3, 0], 0);
            lmiterm([-1,2,4, V], Ok1, C2);
            lmiterm([-1,2,4, 0], -Oki1*C2);
            lmiterm([-1,3,3, 0], lam1);
            lmiterm([-1,3,4, 0], 0);
            lmiterm([-1,4,4, 0], lam1);
        mylmi1 = getlmis;
        
        Ilmi = mylmi1;
        
        for j = 2:num_segments
            index_startj = chpoints(j,1);
            index_endj = chpoints(j,2);
        
            xsegj = x(index_startj: index_endj, :);
            xkj = xsegj(1:end - winlen, :);
            xkij = xsegj(winlen+1:end, :);
            
            Okj = [xkj, ones(size(xkj,1),winlen)];
            Okij = xkij;

            %jth LMI
            lamj = (lambda * eye(1))^2;
            setlmis(Ilmi);
            lmiterm([-2,1,1, 0], 1); %j
            lmiterm([-2,1,2, 0], 0);%j
            lmiterm([-2,1,3, V], Okj, C1);%j
            lmiterm([-2,1,3, 0], -Okij*C1);%j
            lmiterm([-2,1,4, 0], 0);%j
            lmiterm([-2,2,2, 0], 1);%j
            lmiterm([-2,2,3, 0], 0);%j
            lmiterm([-2,2,4, V], Okj, C2);%j
            lmiterm([-2,2,4, 0], -Okij*C2);%j
            lmiterm([-2,3,3, 0], lamj);%j
            lmiterm([-2,3,4, 0], 0);%j
            lmiterm([-2,4,4, 0], lamj);%j
            Ilmi = getlmis;

            
            [tmin,xfeas] = feasp(Ilmi);
            v = dec2mat(Ilmi,xfeas,V);
            
            if (tmin <=0)      
                indx = [indx; j]; 
                Ilmi = dellmi(Ilmi, 2);%j
            else
                Ilmi = dellmi(Ilmi, 2);%j
                xc = [xc; xsegj]; 
                if chpc == 1
                    chpc = [1,size(xsegj,1)];
                else
                    chpc = [chpc;[chpc(end)+1,size(xsegj,1)+ chpc(end)]];
                end
            end
        end
      
        indx = [indx; -1];
        
        indxx = FnRecursive(i,xc,[],chpc, winlen);
        indx = [indx; indxx];
         
    else
        indx = [];
    end
end