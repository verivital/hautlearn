function HA = ex2_nl(~)


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
%   x1' == 17709872814793.0 * x2 / 147573952589676410000.0 - 4885549301075.0 * x1 / 295147905179352830000.0 - 25560522869469.0 * x1 * x2 / 36893488147419103000.0 + 23348987725423.0 * x1 ^ 2.0 / 295147905179352830000.0 + 37317396741413.0 * x2 ^ 2.0 / 36893488147419103000.0 + 0.9999999961747696 &
%    x2' == 4503599648254823.0 * x1 / 4503599627370496.0 + 475678987389.0 * x2 / 9223372036854776000.0 - 192670781808847.0 * x1 * x2 / 295147905179352830000.0 + 55569792035993.0 * x1 ^ 2.0 / 1180591620717411300000.0 + 336092630055397.0 * x2 ^ 2.0 / 295147905179352830000.0 - 0.0000000020426695939894023
dynamics = nonlinearSys(@ex2_nl_St1_FlowEq,2,1); 

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
%   x1' == 11278941379.0 * x1 * x2 / 2251799813685248.0 - 614502682225.0 * x2 / 36028797018963968.0 - 1617979564213.0 * x1 / 144115188075855872.0 + 2104648728409.0 * x1 ^ 2.0 / 1152921504606846980.0 - 9007161403513265.0 * x2 ^ 2.0 / 9007199254740992.0 + 0.00001782211096618136 &
%    x2' == 2069062415.0 * x1 / 1125899906842624.0 + 14700152253.0 * x2 / 4503599627370496.0 - 238660367459.0 * x1 * x2 / 288230376151711740.0 - 399866766279.0 * x1 ^ 2.0 / 1152921504606846980.0 - 55380855441.0 * x2 ^ 2.0 / 72057594037927936.0 - 1.0000030969954306
dynamics = nonlinearSys(@ex2_nl_St2_FlowEq,2,1); 

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