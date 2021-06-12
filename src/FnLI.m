function [trace,label_guard] = FnLI(trace, iter, threshDist, inNum)


global num_var num_ud Time

% first two are the source state and destination state, last two is a changepoint
trans = []; 
for i = 1:length(trace)
    chpoints = trace(i).chpoints;
    labels_trace = trace(i).labels_trace;
    x = trace(i).x;   
    for j = 1:length(labels_trace)-1  % last chpoints is the end point 
        chpoints_temp = chpoints(j+1);
        trans(end+1,:) = [trace(i).labels_trace(j),trace(i).labels_trace(j+1),...
        x(chpoints_temp,:)]; 
    end
end

%% estimate linear inequality for each type of transitions 
[state_trans, ia, ic ]= unique(trans(:,1:2), 'stable', 'rows');
num = 1;
for i = 1:size(state_trans,1)
    states = state_trans(i,:);
    id_chpoint = find(ic == i);
    points = trans(id_chpoint,3:end); 
%     if states(1)==states(2)
%         wb = zeros(num_var+2,1);
%         LI(i).states = states;
%         LI(i).points = points;
%         LI(i).inlayer = {id_chpoint};
%         LI(i).wb = {zeros(num_var+2,1)};
%         continue;
%     end
    
    if size(points,1)<inNum
        continue;
    end
    % wb: inequality parameters, inlayer: index of inlayer points
    if Time
        num_vars = num_var+1;
    else
        num_vars = num_var;
    end
    [wb_temp, inlayer_temp] = FnEstLI(points, num_vars,iter,threshDist,inNum);
    if isempty(wb_temp)
%         LI(i).states = states;
%         LI(i).points = points;
%         LI(i).inlayer = {id_chpoint};
%         LI(i).wb = {zeros(num_var+2,1)};
        continue;
    end
    [wb, inlayer]= FnInequalitySymbol(id_chpoint, wb_temp, inlayer_temp, trace, points);
    
    LI(i).states = states;
    LI(i).points = points;
    LI(i).inlayer = inlayer;
    LI(i).wb = wb;
    
    num = num+1;
end
%%
num_guard = 1;
guard_trace = zeros(size(trans,1),1);
for n = 1:length(LI)
    for i = 1:length(LI(n).inlayer)
        if ~isempty(LI(n).inlayer(1,i))
            iwb = (LI(n).wb);
            if length(LI(n).inlayer)==1
                label_guard(num_guard) = {iwb};
            else
                label_guard(num_guard) = {iwb(:,i)};
            end
            id = cell2mat(LI(n).inlayer(1,i));
            guard_trace(id,:) = num_guard;
            num_guard = num_guard + 1;
        end
    end
end



%%
for n = 1:length(trace)
    labels_trace = trace(n).labels_trace;
    len_guard = length(labels_trace)-1;
    trace(n).guard_trace = guard_trace(1:len_guard,:);
    guard_trace(1:len_guard,:) = [];
end
end

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
   
   flag = true;
   for i = 1:length(inlayer_temp)
       indx_temp = cell2mat(inlayer_temp(i));
       points_temp = points;
       points_temp(indx_temp,:) = [];
       vals_temp = M(1:end-2,i)'*points_temp' + 1;
       if length(find(sign(vals_temp)==M(end,i)))/size(points_temp,1)<=0.01
           flag = false*flag;
       end 
   end
   if flag
       % assume that LIs are conjunctive
        merg_inlayer = [];
        for i = 1:length(inlayer)
            merg_inlayer = [merg_inlayer; cell2mat(inlayer(i))];
        end
        inlayer = {merg_inlayer};
       
   end
    
%    if length(inlayer_temp)>=2
%         for i = 1:length(inlayer_temp)
%             arr = 1:length(inlayer_temp);
%             arr(i) = [];
%             for j = arr
%                 indx_temp = cell2mat(inlayer_temp(j));
%                 ipoints = points(indx_temp,:);
%             end
%             len = size(ipoints, 1);
%             idistance = (ipoints * wb(1:end-1, i) + repmat(wb(end, i),len, 1))/norm(wb(1:end-1, i));
%             pnum = length(find(idistance>=0))/length(idistance);
%             symb = 0;
%             if pnum>=0.90
%                 symb = 1; 
%             elseif pnum <=0.10 
%                 symb = -1; 
%             end
%             % if other change points statisft ith gurad condition
%             if symb == M(end,i)
%                 sat = 1;
%             else 
%                 sat = 0;
%                 break
%             end
%         end
%         
%         if sat ==1
%             merg_inlayer = [];
%             for i = 1:length(inlayer)
%                 merg_inlayer = [merg_inlayer; cell2mat(inlayer(i))];
%             end
%             inlayer = {merg_inlayer};
%         end
%    end
  
end

function seg = FnGetSeg(indx, trace)
    t = 1;
    seg = [];
    for i = 1:length(trace)
        for j = 1:length(trace(i).labels_trace)-1
            if t == indx 
                x_temp = trace(i).x(trace(i).chpoints(j):trace(i).chpoints(j+1),:);
                seg = x_temp;
                return;
            end
            t = t+1;
        end
    end
end