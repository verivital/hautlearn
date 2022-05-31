%% Train neural ODE with new function from 2022a
% Load data
data_traces = 50;
tlen = data_traces*1000;
xTrain = zeros(9,data_traces,1000); % states, traces, tspan
yTrain = zeros(9,data_traces,1000);
for td = 1:data_traces
    datafile = "../ACC/data/trace"+string(td)+".mat";
    data_train = load(datafile);
    data = data_train.data_mat;
    xTrain(:,td,:) = data(:,1:end-1);
    yTrain(:,td,:) = data(:,2:end);
end
test_data = load('../ACC/data/trace20.mat');
% tspan = test_data.data.tspan;
tspan = 0:0.1:0.1; % only one control period
% test_data = test_data.data_mat;

%% Define Model
% neuralOdeTimesteps = 20;
% dt = 0.01;
% timesteps = (0:neuralOdeTimesteps)*dt;
timesteps = tspan;
% Initialize parameters structure
neuralOdeParameters = struct;
% stateSize = size(X0,1);
stateSize = 6; % inputs to controller (v_set, t_gap, v_ego, d_rel, v_rel) (a_ego)
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
learnRate = 0.002;
numIter = 10000;
miniBatchSize = 10;
plotFrequency = 50; % No need to plot for this
f = figure;
f.Position(3) = 2*f.Position(3);

subplot(2,2,1)
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
X = dlarray(reshape(xTrain([7,8,2,1,4,6],:,:),[6,tlen])); %var6 = a_ego
targets = reshape(yTrain(6,:,:),[1 tlen]);
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
    subplot(2,2,1)
    currentLoss = double(loss);
    addpoints(lineLossTrain,iter,currentLoss);
    D = duration(0,0,toc(start),Format="hh:mm:ss");
    title("Elapsed: " + string(D)+" -- Loss = "+string(extractdata(currentLoss)))
    drawnow
    
    % Plot predicted vs. real dynamics
%     if mod(iter,plotFrequency) == 0  || iter == 1
%         y = dlode45(@odeModel,tspan,dlarray(test_data.data_mat.initial),neuralOdeParameters,DataFormat="CB");
%         y = reshape(y(1:6,1,:),[6, 200]);
%         % subplot1
%         subplot(2,2,2)
%         plot(test_data.data.states(2:end,1),test_data.data.states(2:end,4),"r--")
%         hold on
%         plot(y(1,:),y(4,:),"b-")
%         hold off
%         xlabel("x(1)")
%         ylabel("x(4)")
%         title("Predicted vs. Real Dynamics")
%         legend("Training Ground Truth", "Predicted")
%     end
end

%% Evaluate model
% tPred = 0.01:0.01:5;

% x0Pred1 = test_data(1:6,1);     xTrue1 = test_data(1:6,2:10);
% x0Pred2 = test_data(1:6,101);   xTrue2 = test_data(1:6,102:110);
% x0Pred3 = test_data(1:6,6541);  xTrue3 = test_data(1:6,6542:6550);
% x0Pred4 = test_data(1:6,10501); xTrue4 = test_data(1:6,10502:10510);

% xPred1 = dlode45(@odeModel,tPred,dlarray(x0Pred1),neuralOdeParameters,DataFormat="CB");
% xPred2 = dlode45(@odeModel,tPred,dlarray(x0Pred2),neuralOdeParameters,DataFormat="CB");
% xPred3 = dlode45(@odeModel,tPred,dlarray(x0Pred3),neuralOdeParameters,DataFormat="CB");
% xPred4 = dlode45(@odeModel,tPred,dlarray(x0Pred4),neuralOdeParameters,DataFormat="CB");
% Visualize results
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
tmp = (X0(6,:)+0.5)./2.5;
X0(6,:) = tmp;
X = dlode45(@odeModel,tspan,X0,neuralOdeParameters,DataFormat="CB");
X = X(6,:).*2.5-0.5;
% X = X(6,:,:);
end

% Linear model
function y = odeModel(~,y,theta)
y = tanh(theta.fc1.Weights*y + theta.fc1.Bias);
y = tanh(theta.fc2.Weights*y + theta.fc2.Bias);
% y = theta.fc2.Weights*y + theta.fc2.Bias;
end

% Nonlinear model
% function y = odeModel(~,y,theta)
% y = theta.fc1.Weights*y + theta.fc1.Bias;
% y = tanh(theta.fc2.Weights*y + theta.fc2.Bias);
% end

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
% Compute L2 loss.
% X = X([3,6],:,:);
% targets = targets([3,6],:,:);
loss = l2loss(X,targets,NormalizationFactor="all-elements",DataFormat="CBT");
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
% function plotTrueAndPredictedSolutions(xTrue,xPred,tPred)
% xPred = squeeze(xPred);
% err = mean(abs(xTrue - xPred), "all");
% figure;
% subplot(3,2,1);
% title("Ground Truth Dynamics")
% plot(tPred(1:end-1), xTrue(1,:),"r--",tPred(1:end-1), xPred(1,:),"b-",LineWidth=1) % Relative distance
% ylabel("x_1")
% subplot(3,2,2);
% plot(tPred(1:end-1), xTrue(2,:),"r--",tPred(1:end-1), xPred(2,:),"b-",LineWidth=1) % Ego speed
% ylabel("x_2") 
% subplot(3,2,3);
% plot(tPred(1:end-1), xTrue(3,:),"r--",tPred(1:end-1), xPred(3,:),"b-",LineWidth=1) % Lead spped
% ylabel("x_3") 
% subplot(3,2,4); % Relative speed
% plot(tPred(1:end-1), xTrue(4,:),"r--",tPred(1:end-1), xPred(4,:),"b-",LineWidth=1)
% ylabel("x_4") 
% subplot(3,2,5);
% plot(tPred(1:end-1), xTrue(5,:),"r--",tPred(1:end-1), xPred(5,:),"b-",LineWidth=1) % Lead acceleration
% ylabel("x_5")
% subplot(3,2,6);
% plot(tPred(1:end-1), xTrue(6,:),"r--",tPred(1:end-1), xPred(6,:),"b-",LineWidth=1) % Ego acceleration
% ylabel("x_6") 
% title("Absolute Error = " + num2str(err,"%.4f"))
% xlabel("x_1")
% ylabel("x_2")
% legend("Ground Truth","Predicted")
% end

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