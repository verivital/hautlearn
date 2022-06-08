function HA = buck_cora(~)


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
%   x1' == 8619012724139445.0 * x1 * x2 / 2251799813685248.0 - 3326131401589025.0 * x2 / 8796093022208.0 - 4748530302476993.0 * x1 / 17592186044416.0 - 5266598956251995.0 * x1 ^ 2.0 / 2251799813685248.0 - 8298740708991723.0 * x2 ^ 2.0 / 36028797018963968.0 + 9043.472189641088 &
%    x2' == 4066047469383711.0 * x1 / 8796093022208.0 - 7676740797799193.0 * x2 / 281474976710656.0 - 603330186473109.0 * x1 * x2 / 140737488355328.0 + 1993770440733165.0 * x1 ^ 2.0 / 2251799813685248.0 - 4721981863483955.0 * x2 ^ 2.0 / 4503599627370496.0 - 32.133729229638845
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
%   -0.0006553 * x1 - 0.08273 * x2 + 1.0 < 0.0
A = ...
[-0.00065530000000000004477945791947491,...
-0.082729999999999997983834987280716];
b = ...
[-1];
polyOpt = struct('A', A, 'b', b);
guard = mptPolytope(polyOpt);

trans{1} = transition(guard, reset, 2,[]);

loc{1} = location('S1', inv, trans, dynamics);



%------------------------------State loc2----------------------------------

%% equation:
%   x1' == 7443955942023847.0 * x1 / 4398046511104.0 - 7372455516821553.0 * x2 / 274877906944.0 - 894555039364449.0 * x1 * x2 / 4398046511104.0 + 6702032194549759.0 * x1 ^ 2.0 / 140737488355328.0 + 2393494058660005.0 * x2 ^ 2.0 / 2199023255552.0 + 161847.10973675753 &
%    x2' == 826045894847635.0 * x1 / 1099511627776.0 + 7506359986894825.0 * x2 / 274877906944.0 - 470063073077917.0 * x1 * x2 / 8796093022208.0 + 5308660278588869.0 * x1 ^ 2.0 / 281474976710656.0 - 4395306927710371.0 * x2 ^ 2.0 / 4398046511104.0 - 184538.37940016115
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
%   x1' == 3306700931727881.0 * x1 / 68719476736.0 - 5901610401205565.0 * x2 / 4398046511104.0 - 3529884864719121.0 * x1 * x2 / 2199023255552.0 - 6104736063107663.0 * x1 ^ 2.0 / 17179869184.0 + 417151576854597.0 * x2 ^ 2.0 / 8796093022208.0 + 9088.465494702321 &
%    x2' == 7444565291381387.0 * x1 / 1099511627776.0 + 2742401755154365.0 * x2 / 17592186044416.0 - 5528322438330775.0 * x1 * x2 / 8796093022208.0 + 2714552677641095.0 * x1 ^ 2.0 / 34359738368.0 - 8163938912191255.0 * x2 ^ 2.0 / 1125899906842624.0 - 1466.587814011843
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