close all;
figure;
hold on;

n = size( trace(1).x, 2); % number of vars
N = length(trace); % number of traces

colors = 'bgrcmyk';

idx_subset = [1:10]';%[1; 5; 10; 20; 30; 40; 50; 60; 70; 75]';
allTrace_tmax = 0;

for i = 1 : N % todo: switch back to N, just testing with small numbers for now
%for i = 1:10 %idx_subset
    % traces may be different lengths, so we need to have a time vector for
    % each
    tmax_steps = length(trace(i).x);
    allTrace_tmax = max(allTrace_tmax, tmax_steps);
    t_vec = [0:tmax_steps - 1]'; % todo: if Ts is given, can multiply by this

    % initial condition for simulation, the model uses eg x1 = x0(1) for
    % variable 1's initial condition
    x0 = trace(i).x(1,:);
    
    res = sim('automata_learning_nav', 'ReturnWorkspaceOutputs', 'on');
%    res = sim('con_ESTbouncing', 'ReturnWorkspaceOutputs', 'on');
    
    for j = 1 : n
        j_color = mod( j, length(colors)) + 1;
        jhat_color = mod( j + 1, length(colors)) + 1;
        subplot(n, 1, j);
        hold on;
        c = colors(j_color);
        chat = colors(jhat_color);
        
        plot( t_vec, trace(i).x(:, j), strcat(c, '-'));
        
        % todo: need to set the IC here as the same as that used in
        % trace(i)
        
        trace(i).xHat(:, j) = res.ScopeData.signals(j).values(1:tmax_steps);
        
        % todo: will have n + 1 as the output will have a mode too
        
        % todo: the length of xHat is dependent upon time, e.g., the
        % sampling selected, maximum simulation time, etc., so N and the number of points in xHat may
        % differ
        plot( t_vec, trace(i).xHat(:, j), strcat(chat, '+:'));

        
        % delete all the duplicate x axes since they are all the same
        set(gca,'xtick',[]); % ,'ytick',[]
        %axes('Position', [0 0 0 0]);
    end
    set(gca,'xtickMode', 'auto');
    
    %figure;
    error = trace(i).x - trace(i).xHat; % error along each dimension across the whole trace (for error vs. time plots for example)
    errorAbs = abs(error); % error along each dimension (absolute value for magnitude)
    trace(i).traceError = vecnorm(error,2,2); % 2-norm along the time dimension across all the n state variables (for error vs. time)
    %plot( t_vec, traceError);
    
    for j = 1 : n
        subplot(n, 1, j);
        
        hold on;
        
        plot( t_vec, trace(i).x(:, j) + errorAbs(:,j), '-.k');
        plot( t_vec, trace(i).x(:, j) - errorAbs(:,j), '-.k');
    end
    
    trace(i).e_mseT = norm(trace(i).traceError);
    trace(i).e_mse = norm(error);
    trace(i).e_immse = immse(trace(i).x, trace(i).xHat); % this looks to be way too small
    
    opt_mse = 0;
    if opt_mse
        for j = 1 : n
            subplot(n, 1, j);

            hold on;

            plot( t_vec, trace(i).x(:, j) + e_mse, '-.m');
            plot( t_vec, trace(i).x(:, j) - e_mse, '-.m');
        end
    end
end

% aggregate mse across all traces
min([trace(:).e_mse])
max([trace(:).e_mse])
mean([trace(:).e_mse])
median([trace(:).e_mse])

varNamesPlots = {'x', 'y', 'v_x', 'v_y'};
% add axes labels, etc.
for j = 1 : n
    subplot(n, 1, j);
    ylabel(varNamesPlots{j});
    xlim([0 allTrace_tmax]);
end
xlabel('Time steps [k]');