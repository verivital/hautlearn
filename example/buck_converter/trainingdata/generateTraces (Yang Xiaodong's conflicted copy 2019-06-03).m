% clc
% clear
mdl1 = '..\buck_dcm_vs1';
mdl2 = '..\automata_learning';
T = 0.02; % running time
Ts = 0.00005; % sample time
% x0(1) = rand*(-20)-10; % range(0,15)
% x0(2) = 0; %rand*20+10; % range(0,30)
sim(mdl1)

plot(xout)