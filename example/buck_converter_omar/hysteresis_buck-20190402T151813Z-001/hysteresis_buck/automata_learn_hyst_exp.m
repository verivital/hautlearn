% This mfile plots data for the hysteresis controlled DC-DC Buck converter
% The data is recorded using an experimental setup
clc
clear
% Vref = 12, Vin = 24;
load('exp_r10.mat'); % load data
% defines time, voltage, and current vectors
% texp=0:1/50000:(1/50000)*(50002-17309);% time 
step = 30;
iexp=I_test1(17309:step:end,end);% current data from Buck converter
vexp=V_test1(17309:step:end,end);% voltage data from Buck converter

% plot(texp,iexp);% plot time vs current
plot(iexp);
grid on;
figure;
% plot(texp,vexp);% plot time vs voltage
plot(vexp);
grid on;