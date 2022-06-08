function HA = ex1_node(~)


%% Generated on 07-Jun-2022

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
%   x1' == 0.002086562738824682 * x2 - 0.06258858929709277 * x1 + 1.0731875028614013 &
%    x2' == 0.7014102662978985 * x1 + 0.004290363107898543 * x2 + 0.3763837828655596
dynA = ...
[-0.06258858929709276708308607339859,...
0.0020865627388246821283246390521526;0.70141026629789848811924457550049,...
0.0042903631078985426938743330538273];
dynB = ...
[0;0];
dync = ...
[1.073187502861401299014687538147;0.37638378286555962404236197471619];
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
%   x1' == 0.10104580940196684 * x1 - 0.044842719787084206 * x2 - 0.4112039586834726 &
%    x2' == 0.027354503509286587 * x1 - 0.0006732579461932175 * x2 + 0.8892702702814859
dynA = ...
[0.10104580940196683513931930065155,...
-0.044842719787084206473082304000854;...
0.027354503509286587359383702278137,-0.00067325794619321754908014554530382];
dynB = ...
[0;0];
dync = ...
[-0.41120395868347259238362312316895;0.88927027028148586396127939224243];
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