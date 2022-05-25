%% Test the resulting model
HA = buck_cora();
% Parameter ---------------------------------------------------------------

% problem description
params.startLoc = 1;                           % initial location

% Reachability Options ----------------------------------------------------

% settings for continuous reachability 
% options.timeStep = 5e-4; 
% options.taylorTerms = 20;
% options.zonotopeOrder = 20;
% 
% % settings for hybrid systems
% options.guardIntersect = 'zonoGirard';
% options.enclose = {'pca'};

% Simulation Options ------------------------------------------------------

simOptions.startLoc = params.startLoc; 


% FIRST PART --------------------------------------------------------------

% system input:
u = 0; 
simOptions.u = u; 

% set start and end time
params.tFinal = 0.02;
simOptions.tFinal = params.tFinal;

simOptions.x0 = [0;2];
    
% simulate hybrid automaton
[t,x,loc] = simulate(HA,simOptions); 
x = x{1};

% % Load buck converter data
% load('../buck_converter/trainingdata/training2.mat')
% plot(x(:,1),x(:,2),'r');
% hold on;
% plot(xout(:,1),xout(:,2),'b');