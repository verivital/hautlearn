function HA = ex2_linear(~)


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
%   x1' == 1.0 - 0.000000000000000961045907511629 * x2 - 0.00000000000005551115123125783 * x1 &
%    x2' == x1 + 0.00000000000005551115123125783 * x2 + 0.000000000000045565459771187283
dynA = ...
[-5.5511151231257827021181583404541E-14,...
-9.610459075116290464563065874923E-16;1,...
5.5511151231257827021181583404541E-14];
dynB = ...
[0;0];
dync = ...
[1;4.5565459771187283299909154266061E-14];
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
%   x1' == 0.5848145036870847 - 1.8145402457303135 * x2 - 0.1459967979776593 * x1 &
%    x2' == 0.0000000000000034718422901589377 * x1 + 0.00000000000015417254719103741 * x2 - 1.0
dynA = ...
[-0.14599679797765929833985865116119,-1.814540245730313472449779510498;...
3.4718422901589377325471878863328E-15,...
1.5417254719103741348551982713599E-13];
dynB = ...
[0;0];
dync = ...
[0.58481450368708465248346328735352;-1];
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