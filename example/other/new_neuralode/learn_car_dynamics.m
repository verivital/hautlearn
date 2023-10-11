%% Train neural ODE with new function from 2022a
% Load data
data_traces = 100;
xTrain = zeros(6,data_traces,301); % states, traces, tspan
X0 = zeros(8,data_traces);
for td = 1:data_traces
    datafile = "data/cardata"+string(td)+".mat";
    data_train = load(datafile);
    data = data_train.data;
    xTrain(:,td,:) = data.states';
    X0(:,td) = data.initial';
end
test_data = load('data/cardata170.mat');
tspan = test_data.data.tspan;
% test_data = test_data.data_mat;

%% Define Model
% neuralOdeTimesteps = 20;
% dt = 0.01;
% timesteps = (0:neuralOdeTimesteps)*dt;
timesteps = tspan;
% Initialize parameters structure
neuralOdeParameters = struct;
% stateSize = size(X0,1);
stateSize = 4; % acelaration states and inputs, others are derived -> 3rd order neural ode
hiddenSize = 10;

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
numIter = 10000;
miniBatchSize = 10;
plotFrequency = 50;
f = figure;
f.Position(3) = 2*f.Position(3);

subplot(4,2,1)
C = colororder;
lineLossTrain = animatedline(Color=C(2,:));
ylim([0 inf])
xlabel("Iteration")
ylabel("Loss")
grid on

averageGrad = [];
averageSqGrad = [];

%% Train model
numTimeSteps = length(tspan);
numTrainingTimesteps = numTimeSteps;
trainingTimesteps = 1:numTrainingTimesteps;
plottingTimesteps = 2:numTimeSteps;

start = tic;
X = dlarray(X0);
targets = xTrain(:,:,2:end);
xmin = min(xTrain,[],3);
xmax = max(xTrain,[],3);
% norm_targets = (targets - xmin)./(xmax-xmin);

for iter = 1:numIter
    
    % Create batch 
%     [X, targets] = createMiniBatch(numTrainingTimesteps, neuralOdeTimesteps, miniBatchSize, xTrain);

    % Evaluate network and compute loss and gradients
%     [loss,gradients] = dlfeval(@modelLoss,timesteps,X,neuralOdeParameters,targets,xmin,xmax);
    [loss,gradients] = dlfeval(@modelLoss,timesteps,X,neuralOdeParameters,targets);
    
    % Update network 
    [neuralOdeParameters,averageGrad,averageSqGrad] = adamupdate(neuralOdeParameters,gradients,averageGrad,averageSqGrad,iter,...
        learnRate,gradDecay,sqGradDecay);
    
    % Plot loss
    subplot(4,2,1)
    currentLoss = double(loss);
    addpoints(lineLossTrain,iter,currentLoss);
    D = duration(0,0,toc(start),Format="hh:mm:ss");
    title("Elapsed: " + string(D)+" -- Loss = "+string(extractdata(currentLoss)))
    drawnow
    
    % Plot predicted vs. real dynamics
    if mod(iter,plotFrequency) == 0  || iter == 1
        y = dlode45(@odeModel,tspan,dlarray(test_data.data.initial),neuralOdeParameters,DataFormat="CB");
        y = reshape(y(1:6,1,:),[6, 300]);
        % subplot1
        subplot(4,2,2)
        plot(tspan(2:end),test_data.data.states(2:end,1),"r--")
        hold on
        plot(tspan(2:end),y(1,:),"b-")
        hold off
        xlabel('Time (s)')
        ylabel("x_1")
        title("Predicted vs. Real Dynamics")
        legend("Training Ground Truth", "Predicted")
        % subplot2
        subplot(4,2,3)
        plot(tspan(2:end),test_data.data.states(2:end,2),"r--")
        hold on
        plot(tspan(2:end),y(2,:),"b-")
        hold off
        xlabel('Time (s)')
        ylabel("x_2")
        title("Predicted vs. Real Dynamics")
        legend("Training Ground Truth", "Predicted")
        % subplot3
        subplot(4,2,4)
        plot(tspan(2:end),test_data.data.states(2:end,3),"r--")
        hold on
        plot(tspan(2:end),y(3,:),"b-")
        hold off
        xlabel('Time (s)')
        ylabel("x_3")
        subplot(4,2,5)
        plot(tspan(2:end),test_data.data.states(2:end,4),"r--")
        hold on
        plot(tspan(2:end),y(4,:),"b-")
        hold off
        xlabel('Time (s)')
        ylabel("x_4")
        subplot(4,2,6)
        plot(tspan(2:end),test_data.data.states(2:end,5),"r--")
        hold on
        plot(tspan(2:end),y(5,:),"b-")
        hold off
        xlabel('Time (s)')
        ylabel("x_5")
        subplot(4,2,7)
        plot(tspan(2:end),test_data.data.states(2:end,6),"r--")
        hold on
        plot(tspan(2:end),y(6,:),"b-")
        hold off
        xlabel('Time (s)')
        ylabel("x_6")
        drawnow
    end
end

%% Evaluate model
% tPred = 0.01:0.01:5;
% 
% x0Pred1 = test_data(1:6,1);     xTrue1 = test_data(1:6,2:10);
% x0Pred2 = test_data(1:6,101);   xTrue2 = test_data(1:6,102:110);
% x0Pred3 = test_data(1:6,6541);  xTrue3 = test_data(1:6,6542:6550);
% x0Pred4 = test_data(1:6,10501); xTrue4 = test_data(1:6,10502:10510);
% 
% xPred1 = dlode45(@odeModel,tPred,dlarray(x0Pred1),neuralOdeParameters,DataFormat="CB");
% xPred2 = dlode45(@odeModel,tPred,dlarray(x0Pred2),neuralOdeParameters,DataFormat="CB");
% xPred3 = dlode45(@odeModel,tPred,dlarray(x0Pred3),neuralOdeParameters,DataFormat="CB");
% xPred4 = dlode45(@odeModel,tPred,dlarray(x0Pred4),neuralOdeParameters,DataFormat="CB");
% % Visualize results
% figure
% subplot(2,2,1)
% plotTrueAndPredictedSolutions(xTrue1, xPred1, tPred);
% % subplot(2,2,2)
% plotTrueAndPredictedSolutions(xTrue2, xPred2, tPred);
% % subplot(2,2,3)
% plotTrueAndPredictedSolutions(xTrue3, xPred3, tPred);
% % subplot(2,2,4)
% plotTrueAndPredictedSolutions(xTrue4, xPred4, tPred);

%% Helper functions
function X = model(tspan,X0,neuralOdeParameters)
X = dlode45(@odeModel,tspan,X0,neuralOdeParameters,DataFormat="CB");
X = X(1:6,:,:);
end

% Linear model
% function y = odeModel(~,y,theta)
% x1 = y(2,:);
% x2 = y(3,:);
% x4 = y(5,:);
% x5 = y(6,:);
% y = theta.fc1.Weights*y([3,6,7,8],:) + theta.fc1.Bias;
% y = theta.fc2.Weights*y + theta.fc2.Bias;
% y = [x1;x2;y(1,:);x4;x5;y(2:4,:)];
% end

% Nonlinear model
function y = odeModel(~,y,theta)
x1 = y(2,:);
x2 = y(3,:);
x4 = y(5,:);
x5 = y(6,:);
y = tanh(theta.fc1.Weights*y([3,6,7,8],:) + theta.fc1.Bias);
y = theta.fc2.Weights*y + theta.fc2.Bias;
y = [x1;x2;y(1,:);x4;x5;y(2:4,:)];
end

% function [loss,gradients] = modelLoss(tspan,X0,neuralOdeParameters,targets)
% % Compute predictions.
% X = model(tspan,X0,neuralOdeParameters);
% % Compute L1 loss.
% loss = l1loss(X,targets,NormalizationFactor="all-elements",DataFormat="CBT");
% % Compute gradients.
% gradients = dlgradient(loss,neuralOdeParameters);
% end

function [loss,gradients] = modelLoss(tspan,X0,neuralOdeParameters,targets)
% Compute predictions.
X = model(tspan,X0,neuralOdeParameters);
% Compute L1 loss.
X = X([3,6],:,:);
targets = targets([3,6],:,:);
loss = l1loss(X,targets,NormalizationFactor="all-elements",DataFormat="CBT");
% Compute gradients.
gradients = dlgradient(loss,neuralOdeParameters);
end

% function [loss,gradients] = modelLoss(tspan,X0,neuralOdeParameters,targets,xmin,xmax)
% % Norm targets
% norm_targets = (targets - xmin)./(xmax-xmin);
% % Compute predictions.
% X = model(tspan,X0,neuralOdeParameters);
% norm_X = (X - xmin)./(xmax-xmin);
% % Compute L1 loss.
% loss = l2loss(norm_X,norm_targets,NormalizationFactor="all-elements",DataFormat="CBT");
% % Compute gradients.
% gradients = dlgradient(loss,neuralOdeParameters);
% end

% function [x0, targets] = createMiniBatch(numTimesteps,numTimesPerObs,miniBatchSize,X)
% % Create batches of trajectories.
% s = randperm(numTimesteps - numTimesPerObs, miniBatchSize).*randi(50,[1,miniBatchSize]);
% x0 = dlarray(X(:, s));
% targets = zeros([size(X,1)-2 miniBatchSize numTimesPerObs]);
% for i = 1:miniBatchSize
%     targets(:, i, 1:numTimesPerObs) = X(1:6, s(i) + 1:(s(i) + numTimesPerObs));
% end
% end
% 
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

%% Notes
% I think a 3rd-order neural ode may work (predict accelerations, compute
% the other onew from the system of equations)
% dx1 = x2;
% dx2 = x3;
% dx3 = f(x);
% dx4 = x5;
% dx5 = x6;
% dx6 = f2(x);
% Will a linear neural ODE learn these equations better?