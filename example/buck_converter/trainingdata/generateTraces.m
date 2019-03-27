clc
clear
mdl1 = '.\buck_dcm_vs1';
mdl2 = '.\automata_learning';
T = 0.02; % running time
Ts = 0.00005; % sample time
% il_init = rand*(-20)-10; % range(0,15)
% vc_init = 0; %rand*20+10; % range(0,30)
sim(mdl2)

plot(xout)