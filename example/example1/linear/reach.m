%% Load HA
HA = ex1_linear();

% Parameter ---------------------------------------------------------------

% problem description
params.R0 = zonotope([0;0],diag([0.01,0.01]));      % initial set
params.startLoc = 1;                                % initial location
params.tFinal = 1;                                % final time


% Reachability Options ----------------------------------------------------

% settings for continuous reachability 
options.timeStep = 0.01;
options.taylorTerms = 10;
options.zonotopeOrder = 20;

% settings for hybrid systems
options.guardIntersect = 'polytope';
options.enclose = {'pca'}; 


% Reachability Analysis ---------------------------------------------------

tic;
R = reach(HA,params,options);
tComp = toc;

disp(['Computation time for reachable set: ',num2str(tComp),' s']);


% Simulation --------------------------------------------------------------

% settings for random simulation
simOpt.points = 10;        % number of initial points
simOpt.fracVert = 0.5;     % fraction of vertices initial set
simOpt.fracInpVert = 0.5;  % fraction of vertices input set
simOpt.inpChanges = 10;    % changes of input over time horizon  

% random simulation
simRes = simulateRandom(HA,params,simOpt); 



% Visualization -----------------------------------------------------------

figure 
hold on

% plot reachable set
plot(R,[1,2],'w','EdgeColor','k');

% plot initial set
plot(params.R0,[1,2],'r','Filled',true,'EdgeColor','k');

% plot simulated trajectories
plot(simRes,[1,2],'b');

grid;

% axis([0,1.2,-6,4]);