function gen_data_dynamics()
    %% Create data using the true dynamics of the car model for ACC
    % Collect multiple traces (short traces we will learn later on)
    t = tic;
    traces = 500;
    dt = 0.01; tf = 3;
    tspan = 0:dt:tf;
    % Initial states lead car
    xlead = 50*rand([1,traces]) + 60; % [60,110]
    vlead = 10*rand([1,traces]) + 20; % [20,30]
    ylead = zeros([1,traces]); % 0
    % Initial states ego car
    xego = 50*rand([1,traces]); % [0,50]
    vego = 10*rand([1,traces]) + 20; % [20,30]
    yego = zeros([1,traces]); % 0
    a_lead = 5*rand([1,traces]) - 3; %[-3,2]
    a_ego = 5*rand([1,traces]) - 3; %[-3,2]
    for i=1:traces
        initX = [xlead(i);vlead(i);ylead(i);xego(i);vego(i);yego(i)];
        [~,y] = ode45(@car_dynamics,tspan,initX,[],a_ego(i),a_lead(i));
        data = struct;
        data.states = y;
        data.tspan = tspan;
        data.initial = [initX;a_ego(i);a_lead(i)];
        filename = "data/cardata"+string(i)+".mat";
        save(filename,'data');
    end
    toc(t);
    disp("Data collected successfully")
end

