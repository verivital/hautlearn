%% estimate linear inequality for each type of transitions 
[state_trans, ia, ic ]= unique(trans(:,1:2), 'stable', 'rows');

for i = 1:size(state_trans,1)
    states = state_trans(i,:);
    indx_ch = find(ic == i);
    points = trans(indx_ch,5:6); % changepoints 
    
    n = 2; % number of continuous variables
    iter = 1000; % number of iterations 
    threshDist = 0.01; % tolerance 
    inNum = 5; %the least number of inlayers
    % wb: inequality parameters, inlayer: index of inlayer points
    [wb_temp, inlayer_temp] = LinearInequality(points, [], n,iter,threshDist,inNum);
    [wb, inlayer]= FnInequalitySymbol(indx_ch, wb_temp, inlayer_temp, trace);
    
    LI(i).states = states;
    LI(i).points = points;
    LI(i).inlayer = inlayer;
    LI(i).wb = wb;
end