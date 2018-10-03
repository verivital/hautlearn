function indx = FnRecursive2(i,x,ud,chpoints, winlen)  
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
        
        xk1 = seg1(1:end - winlen, :); 
        xki1 = seg1(winlen+1:end, :);
        Ok = [xk1, ones(size(xk1,1),winlen)];
        Oki = xki1;
        
        
        for j = 2:num_segments
            index_startj = chpoints(j,1);
            index_endj = chpoints(j,2);
        
            xsegj = x(index_startj: index_endj, :);
            xkj = xsegj(1:end - winlen, :);
            xkij = xsegj(winlen+1:end, :);
            
            Okj = [xkj, ones(size(xkj,1),winlen)];
            Okij = xkij;
            
            %add jth data
            Ok = [Ok; Okj];
            Oki = [Oki; Okij];
            
            %error tolerance
            error_t = (lambda * eye(1))^2;
            
            %set up a LIM
            setlmis([]);
            structV = [winlen+2, 2];
            V = lmivar(2, structV);
%                 lmiterm([-1,1,1, 0], 1);
%                 lmiterm([-1,1,2, 0], 0);
%                 lmiterm([-1,1,3, V], Ok, C1);
%                 lmiterm([-1,1,3, 0], -Oki*C1);
%                 lmiterm([-1,1,4, 0], 0);
%                 lmiterm([-1,2,2, 0], 1);
%                 lmiterm([-1,2,3, 0], 0);
%                 lmiterm([-1,2,4, V], Ok, C2);
%                 lmiterm([-1,2,4, 0], -Oki*C2);
%                 lmiterm([-1,3,3, 0], error_t);
%                 lmiterm([-1,3,4, 0], 0);
%                 lmiterm([-1,4,4, 0], error_t);
                lmiterm([-1,1,1, 0], 1);
                lmiterm([-1,1,2, V], Ok, C1);
                lmiterm([-1,1,2, 0], -Oki*C1);
                lmiterm([-1,2,2, 0], error_t);
                lmiterm([-2,1,1, 0], 1);
                lmiterm([-2,1,2, V], Ok, C2);
                lmiterm([-2,1,2, 0], -Oki*C2);
                lmiterm([-2,2,2, 0], error_t);                
            Ilmi = getlmis;
        
            tic
            [tmin,xfeas] = feasp(Ilmi);
            toc
            %v = dec2mat(Ilmi,xfeas,V);
            if (tmin <=0)      
                indx = [indx; j]; 
                lenj = length(Okj);
                len = length(Ok);
                Ok(len-lenj+1:end,:)=[];
                Oki(len-lenj+1:end,:)=[];
            else
                lenj = length(Okj);
                len = length(Ok);
                Ok(len-lenj+1:end,:)=[];
                Oki(len-lenj+1:end,:)=[];
                xc = [xc; xsegj]; 
                if chpc == 1
                    chpc = [1,size(xsegj,1)];
                else
                    chpc = [chpc;[chpc(end)+1,size(xsegj,1)+ chpc(end)]];
                end
            end
        end
      
        indx = [indx; -1];
        
        indxx = FnRecursive2(i,xc,[],chpc, winlen);
        indx = [indx; indxx];
         
    else
        indx = [];
    end
end