function HA = stable2d_linear(~)


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
%   x1' == 0.0000009001406845437349 - 0.9999960669356369 * x2 - 0.0000007631377191633093 * x1 &
%    x2' == 0.8776739059467218 * x1 + 0.012313356278895071 * x2 + 0.5176177851772081
dynA = ...
[-7.631377191633093026723599905381E-07,...
-0.99999606693563691806048154830933;0.87767390594672178849577903747559,...
0.012313356278895071227452717721462];
dynB = ...
[0;0];
dync = ...
[9.0014068454373485916875097245793E-07;0.51761778517720813397318124771118];
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
%   0.3288 * x1 - 0.333 * x2 + 1.0 < 0.0
A = ...
[0.32879999999999998117061750235735,-0.33300000000000001820765760385257];
b = ...
[-1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 2,[]);

loc{1} = location('S1', inv, trans, dynamics);



%------------------------------State loc2----------------------------------

%% equation:
%   x1' == -0.000008342971326819049 * x1 - 0.9999939545105008 * x2 - 0.000011790638267755726 &
%    x2' == 6.093528869838337 * x1 + 0.004641196259910885 * x2 + 5.569810735149076
dynA = ...
[-8.3429713268190486274988870718516E-06,...
-0.99999395451050077099353075027466;6.0935288698383374139666557312012,...
0.0046411962599108846916351467370987];
dynB = ...
[0;0];
dync = ...
[-1.1790638267755726431573748413939E-05;5.5698107351490762084722518920898];
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
%   0.499 * x2 - 0.0006802 * x1 + 1.0 < 0.0
A = ...
[-0.00068020000000000005371120215258429,0.49899999999999999911182158029987];
b = ...
[-1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 1,[]);

loc{2} = location('S2', inv, trans, dynamics);



HA = hybridAutomaton(loc);


end