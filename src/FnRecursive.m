function indx = FnRecursive(x,ud,chpoints)  
    winlen = 1;
    global lambda;
    
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
        index_start1 = chpoints(1,1);
        index_end1 = chpoints(1,2);
        xseg1 = x(:,index_start1: index_end1); 
        udseg1 = ud(:,index_start1: index_end1);
        
        %variable number
        num_var = size(x,1);
        %size of ud
        num_ud = size(ud,1);
        %choose t1
        C = eye(num_var);
        
        xk1 = xseg1(:,1:end - winlen); 
        ud1 = [];
        for ii = 1:winlen
            ud1 = [ud1;[udseg1(:,ii:end - winlen+ii-1); ones(1,size(xk1,2))]];
        end
        xki1 = [];
        for ii = 1:winlen
            xki1 = [xki1; xseg1(:,ii+1:end-winlen+ii)];
        end
        
        Ok = [xk1;ud1];
        Oki = xki1;
        
        %error tolerance
        error_t = (lambda * length(Ok))^2;

        setlmis([]);
        nv = 3; %number of variable
        structV = [winlen*nv, winlen+winlen+nv];
        V = lmivar(2, structV);
        C = eye(size(Oki, 1));
        error_t = (lambda * size(Oki,2))^2;
        for i = 1:size(Oki,1)
            n = (i+(1-1)*num_var);
            %n = i;
            lmiterm([-n, 1,1,0],1);
            lmiterm([-n, 1,2,-V],Ok',C(i,:)')
            lmiterm([-n, 1,2,0],-Oki'*C(i,:)')
            lmiterm([-n, 2,1,V],C(i,:),Ok)
            lmiterm([-n, 2,1,0],-C(i,:)*Oki)
            lmiterm([-n, 2,2,0], error_t)
        end
        lmi = getlmis; 
        
        for j = 2:num_segments
            num_segments
            j
            if num_segments == 120
                yy = 0;
            end
            index_startj = chpoints(j,1);
            index_endj = chpoints(j,2);
            
            %heater = x(4:6,index_startj: index_endj);
            xsegj = x(:,index_startj: index_endj);
            xkj = xsegj(:,1:end - winlen);
            xkij = [];
            for ii = 1:winlen
                xkij = [xkij; xsegj(:, ii+1:end-winlen+ii)];
            end
  
            udsegj = ud(:,index_startj: index_endj);
            udj = [];
            for ii = 1:winlen
                udj = [udj;[udsegj(:,ii:end - winlen+ii-1); ones(1,size(xkj,2))]];
            end
        
            Okj = [xkj; udj];
            Okij = xkij;
            
            setlmis(lmi);
            error_t = (lambda * size(Okj,2))^2;
            for i = 1:size(Okij,1)
                n = (i+(j-1)*num_var);
                %n = 3 + i;
                lmiterm([-n, 1,1,0],1);
                lmiterm([-n, 1,2,-V],Okj',C(i,:)')
                lmiterm([-n, 1,2,0],-Okij'*C(i,:)')
                lmiterm([-n, 2,1,V],C(i,:),Okj)
                lmiterm([-n, 2,1,0],-C(i,:)*Okij)
                lmiterm([-n, 2,2,0], error_t)
            end
            lmi = getlmis; 
            %plot(Okij')
        
            tic
            [tmin,xfeas] = feasp(lmi);
            toc
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
                    %n = 3 + i;
                    lmi = dellmi(lmi,n);
                end
            else
                if num_segments ==2 
                    indx = [1;-1;1;-1];
                    return;
                end
                for i = 1:size(Okij,1)
                    n = (j-1)*num_var+i;
                    %n = 3 + i;
                    lmi = dellmi(lmi,n);
                end
                xc = [xc, xsegj]; 
                udc = [udc, udsegj];
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