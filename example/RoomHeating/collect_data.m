% System Dynamics ---------------------------------------------------------

HA = roomHeating();


% Parameter ---------------------------------------------------------------

params.tFinal = 12;
params.startLoc = 1;
% params.timeStep = 0.001;
params.R0 = zonotope([20.5;20.5],diag([0.1,0.1]));  
params.U = zonotope(4,0.01);


% Reachability Settings ---------------------------------------------------

% settings for continuous reachability 
options.taylorTerms = 5; 
options.zonotopeOrder = 10; 
options.timeStep = 0.005; 
 
% settings for hybrid systems
options.enclose = {'box','pca'}; 
options.guardIntersect = 'zonoGirard';


% Simulation --------------------------------------------------------------

simOpt.points = 10;        % number of initial points
simOpt.fracVert = 0.5;     % fraction of vertices initial set
simOpt.fracInpVert = 0.5;  % fraction of vertices input set
simOpt.inpChanges = 20;    % changes of input over time horizon
simOpt.timeStep = 0.001;

simRes = simulateRandom(HA,params,simOpt);

% Visualization -----------------------------------------------------------

% temperature room 1 over time
figure; box on; hold on
plotOverTime(simRes,1);
xlabel('Time')
ylabel('Temperature');
title('Room 1');
xlim([0,params.tFinal]);

% temperature room 2 over time
figure; box on; hold on
plotOverTime(simRes,2);
xlabel('Time')
ylabel('Temperature');
title('Room 2');
xlim([0,params.tFinal]);