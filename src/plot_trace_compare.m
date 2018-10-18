close all;
figure;
hold on;

n = size( trace(1).x, 2); % number of vars
N = length(trace); % number of traces

colors = 'bgrcmyk';

for i = 1 : N
    % traces may be different lengths, so we need to have a time vector for
    % each
    tmax_steps = length(trace(i).x);
    t_vec = [0:tmax_steps - 1]'; % todo: if Ts is given, can multiply by this

    for j = 1 : n
        j_color = mod( j, length(colors)) + 1;
        subplot(n, 1, j);
        hold on;
        plot( t_vec, trace(i).x(:, j));
        
        % delete all the duplicate x axes since they are all the same
        set(gca,'xtick',[]); % ,'ytick',[]
        %axes('Position', [0 0 0 0]);
    end
    set(gca,'xtickMode', 'auto');
end