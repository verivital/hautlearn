%% Generate benchmarks
disp('Generating HAs for Example 1');
cd example1;

% run run_all.m
cd ..;

disp('Generating HAs for Example 2');
cd example2;

run run_all.m
cd ..;

disp('Generating HAs for 2-dimensional stable system');
cd stable2d;

run run_all.m
cd ..;

disp('Generating HAs for 3-dimensional stable system');
cd stable3d;

run run_all.m
cd ..;

disp('All experiments are conducted');
