function HA = buck_cora(~)


%% Generated on 19-May-2022

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
%   x1' == 8151232084910891.0 * x1 * x2 / 281474976710656.0 - 4093935506054123.0 * x2 / 17592186044416.0 - 6576282501786685.0 * x1 / 17592186044416.0 + 7284516860072967.0 * x1 ^ 2.0 / 1125899906842624.0 - 2927197926445625.0 * x2 ^ 2.0 / 144115188075855872.0 + 2789.2762602924136 &
%    x2' == 1209052687878493.0 * x2 / 1099511627776.0 - 5725276808341829.0 * x1 / 70368744177664.0 + 8116349032574343.0 * x1 * x2 / 281474976710656.0 - 6423242370548607.0 * x1 ^ 2.0 / 281474976710656.0 - 2771913659414835.0 * x2 ^ 2.0 / 35184372088832.0 - 2411.53905560294
dynamics = nonlinearSys(@buck_cora_St1_FlowEq,2,1); 

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
%   -0.0007872 * x1 - 0.0826 * x2 + 1.0 < 0.0
A = ...
[-0.0007872000000000000524691401437849,...
-0.082600000000000006750155989720952];
b = ...
[-1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 2,[]);

loc{1} = location('S1', inv, trans, dynamics);



%------------------------------State loc2----------------------------------

%% equation:
%   x1' == 3310441217128939.0 * x2 / 70368744177664.0 - 7684940035815905.0 * x1 / 140737488355328.0 + 6382682002572739.0 * x1 * x2 / 1125899906842624.0 - 8572158031044939.0 * x1 ^ 2.0 / 1125899906842624.0 - 4909139297429565.0 * x2 ^ 2.0 / 2251799813685248.0 - 300.1548105344621 &
%    x2' == 2581033876095029.0 * x1 * x2 / 9007199254740992.0 - 1556822466617749.0 * x2 / 2199023255552.0 - 178651500549451.0 * x1 / 2199023255552.0 + 3065711424760557.0 * x1 ^ 2.0 / 281474976710656.0 + 7010435710535015.0 * x2 ^ 2.0 / 281474976710656.0 + 5004.196714416355
dynamics = nonlinearSys(@buck_cora_St2_FlowEq,2,1); 

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
%   2.337 * x1 - 0.1122 * x2 + 1.0 < 0.0
A = ...
[2.3370000000000001882938249764265,-0.11219999999999999418243135096418];
b = ...
[-1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 3,[]);

loc{2} = location('S2', inv, trans, dynamics);



%------------------------------State loc3----------------------------------

%% equation:
%   x1' == 6662307014193281.0 * x1 / 274877906944.0 + 5662304321094693.0 * x2 / 35184372088832.0 - 7770093196679501.0 * x1 * x2 / 4398046511104.0 - 8114545899978747.0 * x1 ^ 2.0 / 137438953472.0 - 3418811758812599.0 * x2 ^ 2.0 / 562949953421312.0 - 1010.2706704047573 &
%    x2' == 6169541157778843.0 * x2 / 35184372088832.0 - 1786175858449119.0 * x1 / 34359738368.0 + 1168800067111029.0 * x1 * x2 / 274877906944.0 - 628503606243585.0 * x1 ^ 2.0 / 2147483648.0 - 4171513379086491.0 * x2 ^ 2.0 / 562949953421312.0 - 778.449980409669
dynamics = nonlinearSys(@buck_cora_St3_FlowEq,2,1); 

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
%   -0.03057 * x1 - 0.08402 * x2 + 1.0 > 0.0
A = ...
[0.030569999999999999951150186916493,0.084019999999999997464250611756142];
b = ...
[1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 1,[]);

loc{3} = location('S3', inv, trans, dynamics);



HA = hybridAutomaton(loc);


end