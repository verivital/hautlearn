function HA = ex1_linear(~)


%% Generated on 30-May-2022

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
%   x1' == 0.00000000000001887379141862766 * x1 - 0.0000000000000009829601348143184 * x2 + 1.0 &
%    x2' == x1 - 0.0000000000000011102230246251565 * x2 - 0.000000000000013968860790303239
dynA = ...
[1.8873791418627661187201738357544E-14,...
-9.8296013481431839083751423122174E-16;1,...
-1.1102230246251565404236316680908E-15];
dynB = ...
[0;0];
dync = ...
[1;-1.3968860790303239127752021886408E-14];
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
%   0.0000005511 * x2 - 0.2482 * x1 + 1.0 < 0.0
A = ...
[-0.24820000000000000395239396766556,5.5110000000000000481371669955322E-07];
b = ...
[-1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 2,[]);

loc{1} = location('S1', inv, trans, dynamics);



%------------------------------State loc2----------------------------------

%% equation:
%   x1' == 0.0000000000000004198234099811604 - 0.049999999999954525 * x2 - 0.000000000000013322676295501878 * x1 &
%    x2' == 0.00000000000005091228954312111 * x1 + 0.00000000000005773159728050814 * x2 + 1.0
dynA = ...
[-1.332267629550187848508358001709E-14,...
-0.049999999999954525264911353588104;...
5.0912289543121108157678944344457E-14,...
5.7731597280508140102028846740723E-14];
dynB = ...
[0;0];
dync = ...
[4.1982340998116038789055494468057E-16;1];
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
%   43.09132960916031 * x1 + 0.021145646542095164 * x2 + 1.0 < 0.0 &
%    -75.02048562094569 * x1 - 0.1991395009226835 * x2 + 1.0 > 0.0
A = ...
[43.091329609160311520099639892578,0.021145646542095164477359503507614;...
75.0204856209456920623779296875,0.19913950092268350999802350997925];
b = ...
[-1;1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 1,[]);

loc{2} = location('S2', inv, trans, dynamics);



HA = hybridAutomaton(loc);


end