# Automata-Learning
Navigation, a case study from the paper "benchmarks for hybrid systems verification"
The algorithm includes three main programs:1) "main_segs_cluster.m", 2) "odes_estimation.m", and 3) "PTA*.m".
The "main_segs_cluster" aims to cluster trace segments with the same dynamics and estimate the transition conditions based on their changepoints.
The "odes_estimation" aims to estimate the linear equations of the cluster segments
The "PTA*" aims to construct the state transitions for each data traces, based on which the similar states get merged and final estimated automata are achieved.
The "run_history_data1_1.mat" and "run_history_data3.mat" stores the workspace of the "main_segs_cluster" respectively on the training data "trainingdata1.1" and "trainingdata3"
The "test_navigation1_1.slx" and "test_navigation3_0.slx" are two estimated automatas
The "comparison*.mat" stores the traces from the original system and the estimates, the columns of which are "x_position", "y_position","x_velocity" and "y_velocity" 
