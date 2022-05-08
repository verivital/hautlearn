% Plot data to be used for training neural ode for the plant models
for i = 1:500
    datafile = "data/cardata"+string(i)+".mat";
    load(datafile);
    figure;
    subplot(3,2,1)
    plot(data.tspan,data.states(:,1));
    xlabel('Time (s)')
    ylabel('x_{lead}')
    subplot(3,2,2)
    plot(data.tspan,data.states(:,2));
    xlabel('Time (s)')
    ylabel('v_{lead}')
    subplot(3,2,3)
    plot(data.tspan,data.states(:,3));
    xlabel('Time (s)')
    ylabel('a_{lead}')
    subplot(3,2,4)
    plot(data.tspan,data.states(:,4));
    xlabel('Time (s)')
    ylabel('x_{ego}')
    subplot(3,2,5)
    plot(data.tspan,data.states(:,5));
    xlabel('Time (s)')
    ylabel('v_{ego}')
    subplot(3,2,6)
    plot(data.tspan,data.states(:,6));
    xlabel('Time (s)')
    ylabel('a_{ego}')
    if ~mod(i,50)
        pause;
    end
end