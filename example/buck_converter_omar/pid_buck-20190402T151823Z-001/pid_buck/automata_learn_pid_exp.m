% This mfile plots data for the PI controlled DC-DC Buck converter
% The data is recorded using an experimental setup
clc
clear
% Vref = 15; Vin = 30;
load ('pid_buck_data.mat');% load data
% defines time, voltage, and current vectors
texp=0:1/50000:(1/50000)*(2500002-1258015);% time 
iexp=Exp_Results(1258015:end,end); % current data from Buck converter
vexp=Exp_Results(1258015:end,2);% voltage data from Buck converter

plot(texp,iexp);% plot time vs current
grid on;
figure;
plot(texp,vexp);% plot time vs voltage
grid on;
