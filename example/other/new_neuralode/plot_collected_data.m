%% Plot data
% Why? Controller function seems wrong. Maybe the original MPC is not
% working as expected

for i = 1:50
    datafile = "../ACC/data/trace"+string(i)+".mat";
    data_train = load(datafile);
    figure;
    subplot(3,2,1)
    plot(data_train.data_mat(9,:),data_train.data_mat(1,:));
    xlabel('Time (s)')
    ylabel('dist_{rel}')
    subplot(3,2,2)
    plot(data_train.data_mat(9,:),data_train.data_mat(2,:));
    xlabel('Time (s)')
    ylabel('v_{ego}')
    subplot(3,2,3)
    plot(data_train.data_mat(9,:),data_train.data_mat(3,:));
    xlabel('Time (s)')
    ylabel('v_{lead}')
    subplot(3,2,4)
    plot(data_train.data_mat(9,:),data_train.data_mat(4,:));
    xlabel('Time (s)')
    ylabel('v_{rel}')
    subplot(3,2,5)
    plot(data_train.data_mat(9,:),data_train.data_mat(5,:));
    xlabel('Time (s)')
    ylabel('a_{lead}')
    subplot(3,2,6)
    plot(data_train.data_mat(9,:),data_train.data_mat(6,:));
    xlabel('Time (s)')
    ylabel('a_{ego}')
end
% tracs: 3,4,5,6,10,12,14,15,17,19,20 are bad data, do not use for training (old data)

% New data looks much better

% Next step is to evaluate our controller on good data
%% Test controller
% good_data = [1,2,7,8,9,11,16,18];
linear = load("controller_node.mat");
nonlinear = load("controller_node_nl.mat");
for k=1:50
    datafile = "../ACC/data/trace"+string(k)+".mat";
    data_train = load(datafile);
%     figure;
%     subplot(4,1,1)
%     plot(data_train.data_mat(9,:),data_train.data_mat(1,:));
%     xlabel('Time (s)')
%     ylabel('dist_{rel}')
%     subplot(4,1,2)
%     plot(data_train.data_mat(9,:),data_train.data_mat(6,:));
%     xlabel('Time (s)')
%     ylabel('a_{ego}')
%     % Compute predictions
    sim_lin = lmodel(0:0.1:0.1,data_train.data_mat([7,8,2,1,4],:),linear);
    sim_nl = nlmodel(0:0.1:0.1,data_train.data_mat([7,8,2,1,4],:),nonlinear);
%     subplot(4,1,3)
%     plot(data_train.data_mat(9,:),sim_lin);
%     xlabel('Time (s)')
%     ylabel('linear')
%     subplot(4,1,4)
%     plot(data_train.data_mat(9,:),sim_nl);
%     xlabel('Time (s)')
%     ylabel('Nonlinear')
    figure;
    hold on;
    plot(data_train.data_mat(9,:),sim_nl,'DisplayName','Linear');
    plot(data_train.data_mat(9,:),sim_lin,'DisplayName','Nonlinear');
    plot(data_train.data_mat(9,:),data_train.data_mat(6,:),'DisplayName','True');
    legend;
    pause;
end
% Graphs look good enough, may need to find other examples on our
% reachability analysis


%% Helper Functions
function X = lmodel(tspan,X0,mp)
X = dlode45(@linModel,tspan,dlarray(X0),mp.neuralOdeParameters,DataFormat="CB");
X = X(5,:,:);
end

function X = nlmodel(tspan,X0,mp)
X = dlode45(@odeModel,tspan,dlarray(X0),mp.neuralOdeParameters,DataFormat="CB");
X = X(5,:,:);
end

% Linear model
function y = linModel(~,y,theta)
y = theta.fc1.Weights*y + theta.fc1.Bias;
y = theta.fc2.Weights*y + theta.fc2.Bias;
end

% Nonlinear model
function y = odeModel(~,y,theta)
y = tanh(theta.fc1.Weights*y + theta.fc1.Bias);
y = theta.fc2.Weights*y + theta.fc2.Bias;
end


% d_rel = logsout.get('d_rel').Values.Data; % var 1
% v_ego = logsout.get('v_ego').Values.Data; % var 2
% v_lead = logsout.get('v_lead').Values.Data; %var 3
% v_rel = v_lead - v_ego; % var 4
% a_lead = logsout.get('a_lead').Values.Data; % var 5
% a_ego = logsout.get('a_ego').Values.Data; % var 6
% v_sets = v_set*ones(length(v_ego),1); % var 7
% t_gaps = t_gap*ones(length(v_ego),1); % var 8