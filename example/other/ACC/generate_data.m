% clear
% clc
% close all
%addpath(fullfile(matlabroot,'examples','mpc','main'));
    
global mdl Ts T G_ego t_gap D_default v_set amin_ego amax_ego
global x0_lead v0_lead x0_ego v0_ego seed
mdl = 'mpcACCsystem';
open_system(mdl)

% Generate training data
for i = 1:50
    generate_trace(i);
end


function generate_trace(i)
global mdl Ts T G_ego t_gap D_default v_set amin_ego amax_ego
global x0_lead v0_lead x0_ego v0_ego seed
%Uniform random generator 
seed = randi([0,1000]);
% %Define the sample time, Ts, and simulation duration, T, in seconds.
Ts = 0.1;
T = 100;

%Specify the linear model for ego car.
G_ego = tf(1,[0.5,1,0]);

t_gap = 1.4;
D_default = 10;

%Specify the driver-set velocity in m/s.
v_set = 30; % Desired speed

%The acceleration is constrained to the range [-3,2] (m/s^2).
amin_ego = -3;
amax_ego = 2;

%Specify the initial position and velocity for the two vehicles.
x0_lead = 50 + 1.5 - 3*rand(1);   % initial position for lead car (m)
v0_lead = 25 + 1.5 - 3*rand(1);  % initial velocity for lead car (m/s)

x0_ego = 10 + 1.5 - 3*rand(1);   % initial position for ego car (m)
v0_ego = 25 + 1.5 - 3*rand(1);  % initial velocity for ego car (m/s)

%Run the simulation.
sim(mdl)

% Get all data
d_rel = logsout.get('d_rel').Values.Data; % var 1
v_ego = logsout.get('v_ego').Values.Data; % var 2
v_lead = logsout.get('v_lead').Values.Data; %var 3
v_rel = v_lead - v_ego; % var 4
a_lead = logsout.get('a_lead').Values.Data; % var 5
a_ego = logsout.get('a_ego').Values.Data; % var 6
v_sets = v_set*ones(length(v_ego),1); % var 7
t_gaps = t_gap*ones(length(v_ego),1); % var 8
% rp = 10; 
% a_ego = zeros(length(d_rel),1);
% a_ego = [];
% for kk = 1:length(aego(1:end-1))
%     a_ego = [a_ego ; repmat(aego(kk),[10,1])];
% end
% a_ego = [a_ego; aego(end)]; % Repeat the a_ego value until next control period

t_vec = logsout.get('a_lead').Values.Time; % var 9

data_mat = [d_rel, v_ego, v_lead, v_rel, a_lead, a_ego, v_sets, t_gaps, t_vec]';
save(['data/trace',num2str(i),'.mat'],'data_mat'); 

% a_ego = logsout.get(1).Values.Data; 
% output_mat = a_ego;
% output_cell = num2cell(output_mat',1);
end