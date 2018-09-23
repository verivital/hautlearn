clear
addpath('.\trainingdata1.1');
ndata = 50;
run('main_segs_cluster.m')
save 'run_history_data1_1.mat'
rmpath('.\trainingdata1.1');

% clear
% addpath('.\trainingdata1.2');
% ndata = 23;
% run('main_segs_cluster.m')
% save 'run_history_data1_2.mat'
% rmpath('.\trainingdata1.2');
% 
% clear
% addpath('.\trainingdata1.3');
% ndata = 42;
% run('main_segs_cluster.m')
% save 'run_history_data1_3.mat'
% rmpath('.\trainingdata1.3');
% 
% clear
% addpath('.\trainingdata2.1');
% ndata = 38;
% run('main_segs_cluster.m')
% save 'run_history_data2_1.mat'
% rmpath('.\trainingdata2.1');
% 
% clear
% addpath('.\trainingdata2.2');
% ndata = 24;
% run('main_segs_cluster.m')
% save 'run_history_data2_2.mat'
% rmpath('.\trainingdata2.2');
% 
% clear
% addpath('.\trainingdata2.3');
% ndata = 14;
% run('main_segs_cluster.m')
% save 'run_history_data2_3.mat'
% rmpath('.\trainingdata2.3');

clear
addpath('.\trainingdata3');
ndata = 48;
run('main_segs_cluster.m')
save 'run_history_data3.mat';
rmpath('.\trainingdata3');