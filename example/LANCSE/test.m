clc
clear
filepath = '.\matrices';
addpath(filepath)
file0 = xlsread('_c0l7r19vref11nominal0_csv_segment0.csv');
PLANT_VC_low = file0(:,1);
CTRL_low = file0(:,2);
PLANT_Model_low = file0(:,3);
PLANT_SimulationTime_low = file0(:,4);
PLANT_VC_high = file0(:,5);
CTRL_Model_high = file0(:,6);
PLANT_Model_high = file0(:,7);
PLANT_SimulationTime_high = file0(:,8);