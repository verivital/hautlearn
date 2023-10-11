function HA = ex1_nl(~)


%% Generated on 29-May-2022

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
%   x1' == 54674876419.0 * x1 * x2 / 2305843009213694000.0 - 53162286057.0 * x2 / 1152921504606846980.0 - 4986999627.0 * x1 / 281474976710656.0 + 8639540389.0 * x1 ^ 2.0 / 2251799813685248.0 + 617091417.0 * x2 ^ 2.0 / 36893488147419103000.0 + 1.0000176972466388 &
%    x2' == 4503581376076071.0 * x1 / 4503599627370496.0 - 13133867609.0 * x2 / 2305843009213694000.0 + 11376815311.0 * x1 * x2 / 2305843009213694000.0 + 92691138733.0 * x1 ^ 2.0 / 72057594037927936.0 + 4617080777.0 * x2 ^ 2.0 / 295147905179352830000.0 + 0.0000018410548132397064
dynamics = nonlinearSys(@ex1_nl_St1_FlowEq,2,1); 

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
%   x1' == 145211639.0 * x1 / 4398046511104.0 - 7036799687709.0 * x2 / 140737488355328.0 - 317966099.0 * x1 * x2 / 2251799813685248.0 - 602871029.0 * x1 ^ 2.0 / 140737488355328.0 - 43990649.0 * x2 ^ 2.0 / 288230376151711740.0 - 0.0000634889212278722 &
%    x2' == 180223901.0 * x1 * x2 / 4503599627370496.0 - 176002231.0 * x2 / 1125899906842624.0 - 674003615.0 * x1 / 70368744177664.0 + 166242189.0 * x1 ^ 2.0 / 140737488355328.0 - 56764227.0 * x2 ^ 2.0 / 576460752303423490.0 + 1.0000193672808564
dynamics = nonlinearSys(@ex1_nl_St2_FlowEq,2,1); 

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