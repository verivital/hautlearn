%% Collect Buck Converter data
HA = HM_orig();
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
params.tFinal = 2.0;
simOptions.tFinal = params.tFinal;
% simOptions.timeStep = 0.000001;

simOptions.x0 = [0;0;0;0];
    
% simulate hybrid automaton
[t,x,loc] = simulate(HA,simOptions); 
x = x{1};
plot(x(:,1),x(:,2),'r');