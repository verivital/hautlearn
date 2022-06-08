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
%   x1' == 0.0704534481999417 * x1 - 1.0682322679022036 * x2 - 0.15567711649509874 &
%    x2' == 0.8992468202686723 * x2 - 0.013011252348547941 * x1 + 1.9777609818411293
dynA = ...
[0.070453448199941703933291137218475,-1.068232267902203602716326713562;...
-0.013011252348547941437573172152042,0.89924682026867230888456106185913];
dynB = ...
[0;0];
dync = ...
[-0.15567711649509874405339360237122;1.9777609818411292508244514465332];
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
%   x1' == 0.04840411734767258 * x1 - 1.0018367484590271 * x2 + 0.0767735259660185 &
%    x2' == 6.452419820823707 * x1 - 0.019179947266934505 * x2 + 6.124703451030655
dynA = ...
[0.04840411734767258167266845703125,-1.0018367484590271487832069396973;...
6.4524198208237066864967346191406,-0.019179947266934505023527890443802];
dynB = ...
[0;0];
dync = ...
[0.076773525966018496546894311904907;6.1247034510306548327207565307617];
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