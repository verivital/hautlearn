function [trace,label_guard] = FnLI(trace, iter, threshDist, inNum)


global num_var num_ud

% first two are the source state and destination state, last two is a changepoint
trans = []; 
for i = 1:length(trace)
    chpoints = trace(i).chpoints;
    labels_trace = trace(i).labels_trace;
    x = trace(i).x;   
    ud = trace(i).ud;
    for j = 1:length(labels_trace)-1  % last chpoints is the end point 
        chpoints_temp = chpoints(j+1);
%         if isempty(ud)
%             trans(end+1,:) = [trace(i).labels_trace(j),trace(i).labels_trace(j+1),...
%             x(chpoints_temp,:)];  
%         else
%             trans(end+1,:) = [trace(i).labels_trace(j),trace(i).labels_trace(j+1),...
%             x(chpoints_temp,:), ud(chpoints_temp,:)];  
%         end
        trans(end+1,:) = [trace(i).labels_trace(j),trace(i).labels_trace(j+1),...
        x(chpoints_temp,:)]; 
    end
end

%% estimate linear inequality for each type of transitions 
[state_trans, ia, ic ]= unique(trans(:,1:2), 'stable', 'rows');

for i = 1:size(state_trans,1)
    states = state_trans(i,:);
    id_chpoint = find(ic == i);
    points = trans(id_chpoint,3:end); 
    if states(1)==states(2)
        wb = zeros(num_var+2,1);
        LI(i).states = states;
        LI(i).points = points;
        LI(i).inlayer = {id_chpoint};
        LI(i).wb = {wb};
        continue;
    end
    
    if size(points,1)<inNum
        continue;
    end
    % wb: inequality parameters, inlayer: index of inlayer points
    [wb_temp, inlayer_temp] = FnEstLI(points, num_var,iter,threshDist,inNum);
    [wb, inlayer]= FnInequalitySymbol(id_chpoint, wb_temp, inlayer_temp, trace, points);
    
    LI(i).states = states;
    LI(i).points = points;
    LI(i).inlayer = inlayer;
    LI(i).wb = {wb};
end
%%
num_guard = 1;
guard_trace = zeros(size(trans,1),1);
for n = 1:length(LI)
    for i = 1:length(LI(n).inlayer)
        if ~isempty(LI(n).inlayer(1,i))
            iwb = cell2mat(LI(n).wb);
            label_guard(num_guard) = {iwb(:,i)};
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