function HA = ex1_node(~)


%% Generated on 06-Jun-2022

%-------Automaton created from Component 'automata_learning_sys'-----------

%% Interface Specification:
%   This section clarifies the meaning of state, input & output dimensions
%   by showing their mapping to SpaceEx variable names. 

% Component 1 (automata_learning_sys):
%  state x := [x1; x2]
%  input u := [uDummy]

%--------------------Component automata_learning_sys-----------------------

%------------------------------State loc1----------------------------------

%% equation:
%   x1' == 0.0019203483826295553 * x1 - 0.002234165921400688 * x2 + 1.0041255866563006 &
%    x2' == 1.0012670358046307 * x1 + 0.0026515378004603463 * x2 + 0.0036474745315118184
dynA = ...
[0.0019203483826295553171803476288915,...
-0.0022341659214006881484237965196371;1.0012670358046307228505611419678,...
0.0026515378004603462613886222243309];
dynB = ...
[0;0];
dync = ...
[1.0041255866563005838543176651001;0.0036474745315118184407765511423349];
dynamics = linearSys(dynA, dynB, dync);

%% equation:
%   
A = ...
zeros([0,0]);
b = ...
zeros([0,1]);
polyOpt = struct('A', A, 'b', b);
inv = mptPolytope(polyOpt);

trans = {};
%% equation:
%   no reset equation given
resetA = ...
[1,0;0,1];
resetc = ...
[0;0];
reset = struct('A', resetA, 'c', resetc,'hasInput',0);

%% equation:
%   0.0009391 * x2 - 0.4996 * x1 + 1.0 < 0.0
A = ...
[-0.49959999999999998854249838586838,0.00093910000000000000419664303308309];
b = ...
[-1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 2,[]);

loc{1} = location('S1', inv, trans, dynamics);



%------------------------------State loc2----------------------------------

%% equation:
%   x1' == 2.196858510840684 - 3.0009834348456934 * x2 - 0.008509749367533459 * x1 &
%    x2' == -0.001119577985690512 * x1 - 0.0022594534979702985 * x2 - 0.9984868437313708
dynA = ...
[-0.008509749367533459007972851395607,...
-3.0009834348456934094429016113281;-0.001119577985690511923166923224926,...
-0.0022594534979702984855975955724716];
dynB = ...
[0;0];
dync = ...
[2.1968585108406841754913330078125;-0.99848684373137075453996658325195];
dynamics = linearSys(dynA, dynB, dync);

%% equation:
%   
A = ...
zeros([0,0]);
b = ...
zeros([0,1]);
polyOpt = struct('A', A, 'b', b);
inv = mptPolytope(polyOpt);

trans = {};
%% equation:
%   no reset equation given
resetA = ...
[1,0;0,1];
resetc = ...
[0;0];
reset = struct('A', resetA, 'c', resetc,'hasInput',0);

%% equation:
%   0.01034 * x1 + 196.7 * x2 + 1.0 < 0.0
A = ...
[0.01034000000000000023259172365897,196.6999999999999886313162278384];
b = ...
[-1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 1,[]);

loc{2} = location('S2', inv, trans, dynamics);



HA = hybridAutomaton(loc);


end