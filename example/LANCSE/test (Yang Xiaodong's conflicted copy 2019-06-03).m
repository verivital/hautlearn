clc
clear
filepath = '.\nosegments';
addpath(filepath)
file0 = xlsread('vc11il334mode1vref14nominal0.csv_segment0.csv');
PLANT_SimulationTime_low  = file0(:,1);
PLANT_VC_low  = file0(:,2);
PLANT_Model_low = file0(:,3);
CTRL_Model_low = file0(:,4);
PLANT_SimulationTime_high  = file0(:,5);
PLANT_VC_high = file0(:,6);
PLANT_Model_high = file0(:,7);
CTRL_Model_high = file0(:,8);

xout = [PLANT_VC_low, PLANT_VC_high, CTRL_Model_low];