%% Add src and necessary functions to the MATLAB PATH
addpath(genpath('src')); % For generating the hybrid automata
addpath(genpath('../nnv/code/nnv')); % To include cora for generating cora models
rmpath(genpath('../nnv/code/nnv/engine/hyst')); % Remove hyst path to avoid conflicts as we have out own hyst in this repo