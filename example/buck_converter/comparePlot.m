clc
clear
addpath(['..', filesep, '..', filesep, 'src']);
mdl1 = 'buck_dcm_vs1';
mdl2 = 'automata_learning';
T = 0.02;
Ts = 0.00005;
x0(1) = rand*(40)-20; %li range(-20,20)
x0(2) = rand*(20); %li range(0,20)
FnComparePlot(mdl1, mdl2, x0, T, Ts)