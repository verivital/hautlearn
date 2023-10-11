%% Neural ODE modeling of plant dynamics
number_of_layers = 2;
neurons = 30;
% Load training data
data_train = load('data/trace1.mat');
data = data_train.data_mat(1:6,:);
data_train2 = load('data/trace2.mat');
data = [data,  data_train2.data_mat(1:6,:)];
data_train3 = load('data/trace3.mat');
data = [data, data_train3.data_mat(1:6,:)];
data_train4 = load('data/trace4.mat');
data = [data, data_train4.data_mat(1:6,:)];
data_train5 = load('data/trace5.mat');
data = [data, data_train5.data_mat(1:6,:)];
% Estimate neural ode
neuralOdeSteps = 2;
batchSize = 200;
dlnet = EstNodeCustom(data,number_of_layers,neurons,neuralOdeSteps, batchSize);

%% Test what the results look like 
% (Let's do like an open loop trajectory where we input data rows and predict the next step)
test_data = load('data/trace10.mat');
test_data = test_data.data_mat;
tvec = data_train.data_mat(9,1:2);
odeOptions = odeset('RelTol', 1.e-7, 'AbsTol', 1.e-9);
test_length = 100;
xPred = zeros(6,test_length);
% One-step prediction
for k=1:test_length
    xPred(:,k) = predictWithOde45(dlnet,tvec', test_data(1:6,k)', odeOptions);
end
% Results
figure;
plotTrueAndPredictedSolutions(test_data(1:6,1:test_length), xPred, 1, 4)

%% Multi-step prediction (Possible error accumulation)
xPred2 = zeros(6,test_length);
xPred2(:,1) =  predictWithOde45(dlnet, tvec', test_data(1:6,1)', odeOptions);
% One-step prediction
for k=2:test_length
    xPred2(:,k) = predictWithOde45(dlnet, tvec', [xPred2(1:5,k-1);test_data(6,k)] , odeOptions);
end
% Results
figure;
plotTrueAndPredictedSolutions(test_data(1:6,1:test_length), xPred2, 1, 4)
figure;
plotTrueAndPredictedSolutions(test_data(1:6,1:test_length), xPred2, 'time', 1)

%% Notes
% This is clearly not working, how could we address this? Are we doing
% something wrong with the data?

%% Helper Functions
function xPred = predictWithOde45(dlnet,tPred,x0Pred,odeOptions)

% Extract the learnt dynamics
internalNeuralOdeLayer = dlnet.Layers(1);
dlnetODEFcn = @(t,y) evaluateODE(internalNeuralOdeLayer, y);

[~,xPred] = ode45(dlnetODEFcn, tPred, x0Pred, odeOptions);
% Get only last point
xPred = xPred(end,:)';
% error = mean(abs(xTrue - xPred), 'all');
end

function plotTrueAndPredictedSolutions(xTrue, xPred, dim1, dim2)
if isnumeric(dim1)
    plot(xTrue(dim1,:),xTrue(dim2,:),'r--',xPred(dim1,:),xPred(dim2,:),'b-','LineWidth',1);
% title("x_0 = " + x0Str + ", err = " + num2str(err) )
    xlabel("x_"+string(dim1));
else
    tvec = 0.01:0.01:length(xPred)*0.01;
    plot(tvec',xTrue(dim2,:),'r--',tvec',xPred(dim2,:),'b-','LineWidth',1);
    xlabel('Time (s)')
end
ylabel("x_"+string(dim2));
% xlim([-2 2])
% ylim([-2 2])
legend('Ground truth', 'Predicted')
end