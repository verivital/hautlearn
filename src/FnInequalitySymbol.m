function [M, inlayer]= FnInequalitySymbol(indx_ch, wb, inlayer_temp, trace, points)
   inlayer = {};
   M = [wb; zeros(1, size(wb,2))];
   %
   for i = 1:length(inlayer_temp)
        indx_temp = cell2mat(inlayer_temp(i));
        indx = indx_ch(indx_temp);
        inlayer(i) = {indx};
        inlayer_points = [];
        for j = 1:length(indx)
            inlayer_points = [inlayer_points; FnGetSeg(indx(j), trace)];
        end
        len = size(inlayer_points, 1);
        distance = (inlayer_points * wb(1:end-1, i) + repmat(wb(end, i),len, 1))/norm(wb(1:end-1, i));
        pnum = length(find(distance>=0))/length(distance);
        if pnum>=0.90
            M(end,i) = -1; %<
        elseif pnum <=0.10 
            M(end,i) = 1; %>
        end
   end
   
   if length(inlayer_temp)>=2
        for i = 1:length(inlayer_temp)
            arr = 1:length(inlayer_temp);
            arr(i) = [];
            for j = arr
                indx_temp = cell2mat(inlayer_temp(j));
                ipoints = points(indx_temp,:);
            end
            len = size(ipoints, 1);
            idistance = (ipoints * wb(1:end-1, i) + repmat(wb(end, i),len, 1))/norm(wb(1:end-1, i));
            pnum = length(find(idistance>=0))/length(idistance);
            symb = 0;
            if pnum>=0.90
                symb = 1; 
            elseif pnum <=0.10 
                symb = -1; 
            end
            % if other change points statisft ith gurad condition
            if symb == M(end,i)
                sat = 1;
            else 
                sat = 0;
                break
            end
        end
        
        if sat ==1
            merg_inlayer = [];
            for i = 1:length(inlayer)
                merg_inlayer = [merg_inlayer; cell2mat(inlayer(i))];
            end
            inlayer = {merg_inlayer};
        end
   end
  
end