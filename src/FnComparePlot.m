

function FnComparePlot(mdl1, mdl2, x0, T, Ts)

close all;
figure;
hold on;

sim(mdl1); % output xout
n = length(x0); % number of vars

colors = 'bgrcmyk';

for i = 1:1

    t_vec = [0:Ts:T]'; % todo: if Ts is given, can multiply by this

    % initial condition for simulation, the model uses eg x1 = x0(1) for
    % variable 1's initial condition
    
    res = sim(mdl2, 'ReturnWorkspaceOutputs', 'on');

    for j = 1 : n
        j_color = mod( j, length(colors)) + 1;
        jhat_color = mod( j + 1, length(colors)) + 1;
        subplot(n, 1, j);
        hold on;
        c = colors(j_color);
        chat = colors(jhat_color);
        
        plot( t_vec, xout(:, j), 'b-');

        % trace(i)
        temp_trace = res.ScopeData.signals(j).values();
      
        plot( t_vec, temp_trace, 'r-');

        legend('Original system', 'Inferred automaton')
        ylabel(['x', int2str(j)])
        xlabel('Time/sec')
      
    end
end

end 