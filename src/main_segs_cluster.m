% clc
% clear
%
%addpath('.\trainingdata1.1');
global Ts 
Ts = 0.01;
X = []; % store all the data 
segIndex = []; % index to segment X;
num =1;
 
winLen = 10;

for i = 1:ndata
    load(['test', int2str(i),'.mat']);
    
    trace_temp = FnProcessData(xout);
    chpoints = trace_temp.chpoints;
    if min(diff(chpoints))>= winLen+10
        trace(num) = trace_temp;
        vx = trace(num).vx; % vx trace;
        vy = trace(num).vy; % vy trace;
        X = [X; vx,vy];
    
        if size(chpoints,1)==1
            chsegments = chpoints;
        else
            chsegments = [chpoints(1:end-1), chpoints(2:end)];
        end
        if isempty(segIndex) %get changepoints and segments
            segIndex = chsegments; % segments' start index and end index
        else
            segIndex = [segIndex; segIndex(end,2) + chsegments];
        end 
        num = num+1;
    end
    
end
seglength = diff(segIndex')'+1;
[sorted_length, index] = sort(seglength,'descend');
sorted_index = segIndex(index,:);

global lambda;
lambda = 0.005;  
winLen = 5;
tic
idx= FnRecursive2(1,X,[],sorted_index, winLen);
labels = FnIndxarrange(idx, index);
%load labels.mat
%% assign labels to segments
t = 1;
for i = 1:length(trace)
    for j = 1:length(trace(i).chpoints)-1
        trace(i).labels(end+1) = labels(find(labels(:,1)==t),2);
        t = t+1;
    end
end
%% extract transitions and changepoints
trans = []; % first two are the source state and destination state, last two is a changepoint
for i = 1:length(trace)
    ichpoints = trace(i).chpoints;
    ivx = trace(i).vx;
    ivy = trace(i).vy;
    ix = trace(i).x;
    iy = trace(i).y;
    for j = 1:length(ichpoints)-1
        if j ==length(ichpoints)-1
            chpoints_temp = ichpoints(j+1);%the last point of the trace i
            trans(end+1,:) = [trace(i).labels(j),0,...
                ivx(chpoints_temp), ivy(chpoints_temp),...
                ix(chpoints_temp), iy(chpoints_temp)]; % 0 is the terminal state
        else
            chpoints_temp = ichpoints(j+1);
            trans(end+1,:) = [trace(i).labels(j),trace(i).labels(j+1),...
                ivx(chpoints_temp), ivy(chpoints_temp),...
                ix(chpoints_temp), iy(chpoints_temp)];
        end    
    end
end

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


