function HA = HM_orig(~)
% Hybrid model of buck converter used in hardware simulations
%  state x := [il; vc; t]
%  input u := [uDummy]

%% Parameters
C = 4.4e-6; % capacitor value
L = 5e-5; % inductor value
R = 4; % resistor value
% T = 0.00001;% sample time
T = 1e-5;
Vs = 10;% input (source) voltage
Vref = 6;% reference voltage
% Tmax = 1000*(1/R*C);% max simulation time
D = Vref / Vs;% duty cycle
rs=100e-5;% switching loss 
rL=520e-5;% inductor loss

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% State 1 - Charging
A1 = [-(rL+rs)/L -1/L 0 0;
    1/C -1/(R*C) 0 0;
    0 0 0 0;
    0 0 0 0];
B1 = Vs*[1/L; 0; 0; 0];
C1 = [0;0;1;1]; % Constant value for dimension 3 (time)
dyn1 = linearSys(A1,B1,C1);

%invariant (t > 0) Is this the only invariant? Set invariant same as guard?
invA = [0 0 -1 0;
    0 0 1 0];
invb = [0;D*T];
% inv = halfspace(invA,invb);
invOpt = struct('A', invA, 'b', invb);
inv = mptPolytope(invOpt);

% reset (t == 0)
resetA = [1 0 0 0;
    0 1 0 0;
    0 0 0 0;
    0 0 0 1];
resetb = [0;0;0;0];
reset = struct('A', resetA, 'c', resetb);

% Guard (t >= D*T)
guardA = [0 0 1 0];
guardb = D*T;

% guard = halfspace(guardA, guardb);
% guardOpt = struct('A', guardA, 'b', guardb);
% guard = mptPolytope(guardOpt);
guard = conHyperplane(guardA,guardb);

trans = {};
trans{1} = transition(guard, reset, 2);

loc{1} = location('S1',inv, trans, dyn1);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% State 2 - Discharging

A2 = [-rL/L -1/L 0 0;
    1/C -1/(R*C) 0 0;
    0 0 0 0
    0 0 0 1];
B2 = [0; 0; 0;0];
C1 = [0;0;1;1]; % Constant value for dimension 3 (time)
dyn2 = linearSys(A2,B2,C1);

%invariant (t > 0) Is this the only invariant? Set invariant same as guard?
invA = [0 0 -1 0;
    0 0 1 0];
invb = [0;(1-D)*T];
% inv = halfspace(invA,invb);
invOpt = struct('A', invA, 'b', invb);
inv = mptPolytope(invOpt);

%%%%%%% Transition 1 - Transition to charging mode   %%%%%%%%%
% reset (t == 0)
resetA = [1 0 0 0;
    0 1 0 0;
    0 0 0 0;
    0 0 0 1];
resetb = [0;0;0;0];
reset = struct('A', resetA, 'c', resetb);

% Guard (t >= (1-D)*T)
guardA = [0 0 1 0];
guardb = (1-D)*T;

% guardOpt = struct('A', guardA, 'b', guardb);
% guard = mptPolytope(guardOpt);
guard = conHyperplane(guardA,guardb);

trans = {};
trans{1} = transition(guard, reset, 1);

%%%%%%%% Transition 2 - Transition to charging mode   %%%%%%%%%%
% reset (t == 0)
resetA = [1 0 0 0;
    0 1 0 0;
    0 0 0 0;
    0 0 0 1];
resetb = [0;0;0;0];
reset = struct('A', resetA, 'c', resetb);

% Guard (i <= 0)
guardA = [0 1 0 0];
guardb = 0;

% guardOpt = struct('A', guardA, 'b', guardb);
% guard = mptPolytope(guardOpt);
guard = conHyperplane(guardA,guardb);

trans{2} = transition(guard, reset, 3);

loc{2} = location('S2',inv, trans, dyn2);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% State 3 - Discontinuous

A3 = [0 0 0 0;
    0 -1/(R*C) 0 0;
    0 0 0 0;
    0 0 0 0];
B3 = [0; 0; 0; 0];
C1 = [0;0;1;1]; % Constant value for dimension 3 (time)
dyn3 = linearSys(A3,B3,C1);

%invariant (t > 0) Is this the only invariant? Set invariant same as guard?
invA = [0 0 -1 0;
    0 0 1 0];
invb = [0;(1-D)*T];
% inv = halfspace(invA,invb);
invOpt = struct('A', invA, 'b', invb);
inv = mptPolytope(invOpt);

% reset (t == 0)
resetA = [1 0 0 0;
    0 1 0 0;
    0 0 0 0;
    0 0 0 1];
resetb = [0;0;0;0];
reset = struct('A', resetA, 'c', resetb);

% Guard (t >= D*T)
guardA = [0 0 1 0];
guardb = (1-D)*T;

% guardOpt = struct('A', guardA, 'b', guardb);
% guard = mptPolytope(guardOpt);
guard = conHyperplane(guardA,guardb);

trans = {};
trans{1} = transition(guard, reset, 1);

loc{3} = location('S3',inv, trans, dyn3);

% Define Hybrid System
HA = hybridAutomaton(loc);

end

