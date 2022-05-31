%% Train neural ODE with new function from 2022a
% Load data
data_train = load('../ACC/data/trace4.mat');
data = data_train.data_mat(1:6,:);
% test_data = load('../ACC/data/trace10.mat');
test_data = load('../ACC/data/trace4.mat');
test_data = test_data.data_mat;
xTrain = data;
% Visualize data
figure;
subplot(3,2,1);
title("Ground Truth Dynamics")
plot(xTrain(1,:)) % Relative distance
ylabel("x_1")
subplot(3,2,2);
plot(xTrain(2,:)) % Ego speed
ylabel("x_2") 
subplot(3,2,3);
plot(xTrain(3,:)) % Lead spped
ylabel("x_3") 
subplot(3,2,4); % Relative speed
plot(xTrain(4,:))
ylabel("x_4") 
subplot(3,2,5);
plot(xTrain(5,:)) % Lead acceleration
ylabel("x_5")
subplot(3,2,6);
plot(xTrain(6,:)) % Ego acceleration
ylabel("x_6") 
grid on;

%% Define Model
neuralOdeTimesteps = 10;
dt = 0.01;
timesteps = (0:neuralOdeTimesteps)*dt;
% Initialize parameters structure
neuralOdeParameters = struct;
stateSize = size(xTrain,1);
hiddenSize = 20;

neuralOdeParameters.fc1 = struct;
sz = [hiddenSize stateSize];
neuralOdeParameters.fc1.Weights = initializeGlorot(sz, hiddenSize, stateSize);
neuralOdeParameters.fc1.Bias = initializeZeros([hiddenSize 1]);

neuralOdeParameters.fc2 = struct;
sz = [stateSize hiddenSize];
neuralOdeParameters.fc2.Weights = initializeGlorot(sz, stateSize, hiddenSize);
neuralOdeParameters.fc2.Bias = initializeZeros([stateSize 1]);

%% Specify training options

gradDecay = 0.9;
sqGradDecay = 0.999;
learnRate = 0.001;
numIter = 1200;
miniBatchSize = 100;
plotFrequency = 50;
f = figure;
f.Position(3) = 2*f.Position(3);

subplot(1,2,1)
C = colororder;
lineLossTrain = animatedline(Color=C(2,:));
ylim([0 inf])
xlabel("Iteration")
ylabel("Loss")
grid on

averageGrad = [];
averageSqGrad = [];

%% Train model
numTimeSteps = length(data);
numTrainingTimesteps = numTimeSteps;
trainingTimesteps = 1:numTrainingTimesteps;
plottingTimesteps = 2:numTimeSteps;

start = tic;

for iter = 1:numIter
    
    % Create batch 
    [X, targets] = createMiniBatch(numTrainingTimesteps, neuralOdeTimesteps, miniBatchSize, xTrain);

    % Evaluate network and compute loss and gradients
    [loss,gradients] = dlfeval(@modelLoss,timesteps,X,neuralOdeParameters,targets);
    
    % Update network 
    [neuralOdeParameters,averageGrad,averageSqGrad] = adamupdate(neuralOdeParameters,gradients,averageGrad,averageSqGrad,iter,...
        learnRate,gradDecay,sqGradDecay);
    
    % Plot loss
    subplot(1,2,1)
    currentLoss = double(loss);
    addpoints(lineLossTrain,iter,currentLoss);
    D = duration(0,0,toc(start),Format="hh:mm:ss");
    title("Elapsed: " + string(D))
    drawnow
    
    % Plot predicted vs. real dynamics
%     if mod(iter,plotFrequency) == 0  || iter == 1
%         subplot(1,2,2)
% 
%         % Use ode45 to compute the solution 
%         y = dlode45(@odeModel,t,dlarray(x0),neuralOdeParameters,DataFormat="CB");
%         
%         plot(xTrain(1,plottingTimesteps),xTrain(2,plottingTimesteps),"r--")
%         
%         hold on
%         plot(y(1,:),y(2,:),"b-")
%         hold off
% 
%         xlabel("x(1)")
%         ylabel("x(2)")
%         title("Predicted vs. Real Dynamics")
%         legend("Training Ground Truth", "Predicted")
% 
%         drawnow
%     end
end

%% Evaluate model
tPred = 0.01:0.01:0.1;

x0Pred1 = test_data(1:6,1);     xTrue1 = test_data(1:6,2:10);
x0Pred2 = test_data(1:6,101);   xTrue2 = test_data(1:6,102:110);
x0Pred3 = test_data(1:6,6541);  xTrue3 = test_data(1:6,6542:6550);
x0Pred4 = test_data(1:6,10501); xTrue4 = test_data(1:6,10502:10510);

xPred1 = dlode45(@odeModel,tPred,dlarray(x0Pred1),neuralOdeParameters,DataFormat="CB");
xPred2 = dlode45(@odeModel,tPred,dlarray(x0Pred2),neuralOdeParameters,DataFormat="CB");
xPred3 = dlode45(@odeModel,tPred,dlarray(x0Pred3),neuralOdeParameters,DataFormat="CB");
xPred4 = dlode45(@odeModel,tPred,dlarray(x0Pred4),neuralOdeParameters,DataFormat="CB");
% Visualize results
% figure
% subplot(2,2,1)
plotTrueAndPredictedSolutions(xTrue1, xPred1, tPred);
% subplot(2,2,2)
plotTrueAndPredictedSolutions(xTrue2, xPred2, tPred);
% subplot(2,2,3)
plotTrueAndPredictedSolutions(xTrue3, xPred3, tPred);
% subplot(2,2,4)
plotTrueAndPredictedSolutions(xTrue4, xPred4, tPred);

%% Helper functions
function X = model(tspan,X0,neuralOdeParameters)
X = dlode45(@odeModel,tspan,X0,neuralOdeParameters,DataFormat="CB");
end

% Linear model
% function y = odeModel(~,y,theta)
% y = theta.fc1.Weights*y + theta.fc1.Bias;
% y = theta.fc2.Weights*y + theta.fc2.Bias;
% end

% Nonlinear model
function y = odeModel(~,y,theta)
y = tanh(theta.fc1.Weights*y + theta.fc1.Bias);
y = theta.fc2.Weights*y + theta.fc2.Bias;
end

function [loss,gradients] = modelLoss(tspan,X0,neuralOdeParameters,targets)
% Compute predictions.
X = model(tspan,X0,neuralOdeParameters);
% Compute L1 loss.
loss = l1loss(X,targets,NormalizationFactor="all-elements",DataFormat="CBT");
% Compute gradients.
gradients = dlgradient(loss,neuralOdeParameters);
end

function [x0, targets] = createMiniBatch(numTimesteps,numTimesPerObs,miniBatchSize,X)
% Create batches of trajectories.
s = randperm(numTimesteps - numTimesPerObs, miniBatchSize);
x0 = dlarray(X(:, s));
targets = zeros([size(X,1) miniBatchSize numTimesPerObs]);
for i = 1:miniBatchSize
    targets(:, i, 1:numTimesPerObs) = X(:, s(i) + 1:(s(i) + numTimesPerObs));
end
end

function plotTrueAndPredictedSolutions(xTrue,xPred,tPred)
xPred = squeeze(xPred);
err = mean(abs(xTrue - xPred), "all");
figure;
subplot(3,2,1);
title("Ground Truth Dynamics")
plot(tPred(1:end-1), xTrue(1,:),"r--",tPred(1:end-1), xPred(1,:),"b-",LineWidth=1) % Relative distance
ylabel("x_1")
subplot(3,2,2);
plot(tPred(1:end-1), xTrue(2,:),"r--",tPred(1:end-1), xPred(2,:),"b-",LineWidth=1) % Ego speed
ylabel("x_2") 
subplot(3,2,3);
plot(tPred(1:end-1), xTrue(3,:),"r--",tPred(1:end-1), xPred(3,:),"b-",LineWidth=1) % Lead spped
ylabel("x_3") 
subplot(3,2,4); % Relative speed
plot(tPred(1:end-1), xTrue(4,:),"r--",tPred(1:end-1), xPred(4,:),"b-",LineWidth=1)
ylabel("x_4") 
subplot(3,2,5);
plot(tPred(1:end-1), xTrue(5,:),"r--",tPred(1:end-1), xPred(5,:),"b-",LineWidth=1) % Lead acceleration
ylabel("x_5")
subplot(3,2,6);
plot(tPred(1:end-1), xTrue(6,:),"r--",tPred(1:end-1), xPred(6,:),"b-",LineWidth=1) % Ego acceleration
ylabel("x_6") 
title("Absolute Error = " + num2str(err,"%.4f"))
xlabel("x_1")
ylabel("x_2")
legend("Ground Truth","Predicted")
end