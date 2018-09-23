function [M, inlayer]= FnInequalitySymbol(indx_ch, wb, inlayer_temp, trace)
   inlayer = {};
   M = [wb; zeros(1, size(wb,2))];
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
        elseif pnum <=0.1 
            M(end,i) = 1; %>
        end
    end
end