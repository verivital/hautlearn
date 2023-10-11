%% Train neural ODE with new function from 2022a
% x0 = [2; 0];
% A = [-0.1 -1; 1 -0.1];
% trueModel = @(t,y) A*y;
% 
% numTimeSteps = 2000;
% T = 15;
% odeOptions = odeset(RelTol=1.e-7);
% t = linspace(0, T, numTimeSteps);
% [~, xTrain] = ode45(trueModel, t, x0, odeOptions);
% xTrain = xTrain';
% % Visualize data
% figure
% plot(xTrain(1,:),xTrain(2,:))
% title("Ground Truth Dynamics") 
% xlabel("x(1)") 
% ylabel("x(2)")
% grid on;
dataX = readNPY("../../../sonode/experiments/damped_oscillators/data/z.npy");
dataX0 = readNPY("../../../sonode/experiments/damped_oscillators/data/z0.npy");
t = readNPY("../../../sonode/experiments/damped_oscillators/data/samp_ts.npy");
numTimeSteps = length(t);
% xTrain = reshape(dataX,[],1);
%% Define Model
neuralOdeTimesteps = 100;
dt = t(2);
% timesteps = (0:neuralOdeTimesteps)*dt;
timesteps = t;
% Initialize parameters structure
neuralOdeParameters = struct;
% stateSize = size(xTrain,1);
stateSize = 2;
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
numIter = 1000;
miniBatchSize = 200;
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
numTrainingTimesteps = numTimeSteps;
trainingTimesteps = 1:numTrainingTimesteps;
plottingTimesteps = 2:numTimeSteps;

start = tic;
% Create fix batch like in python (torchdiffeq)
cutoff = 30;
xx = dataX(:,1:30)';
xx = reshape(xx,[1 30 100]);
vx = dataX(:,31:60)';
vx = reshape(vx,[1 30 100]);
xx0 = dataX0(1:30,1)';
vx0 = dataX0(31:60,1)';
dataX0 = [xx0;vx0];
dataX = [xx;vx];
targets = dataX(:,:,2:end);
% dataX0 = reshape(dataX0,[2,30]);
X = dlarray(dataX0)';
trueX = reshape(dataX(:,1,:),[2,100]);


for iter = 1:numIter
    
    % Create batch 
%     [X, targets] = createMiniBatch(numTrainingTimesteps, neuralOdeTimesteps, miniBatchSize, xTrain);
    
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
    if mod(iter,plotFrequency) == 0  || iter == 1
        subplot(1,2,2)

        % Use ode45 to compute the solution 
        y = dlode45(@odeModel,t,X(1,:)',neuralOdeParameters,DataFormat="CB");
        y = reshape(y,[2,99]);
        plot(trueX(1,:),trueX(2,:),"r--")
        
        hold on
        plot(y(1,:),y(2,:),"b-")
        hold off

        xlabel("x(1)")
        ylabel("x(2)")
        title("Predicted vs. Real Dynamics")
        legend("Training Ground Truth", "Predicted")

        drawnow
    end
end

%% Evaluate model
% tPred = t;
% 
% x0Pred1 = sqrt([2;2]);
% x0Pred2 = [-1;-1.5];
% x0Pred3 = [0;2];
% x0Pred4 = [-2;0];
% 
% [~, xTrue1] = ode45(trueModel, tPred, x0Pred1, odeOptions);
% [~, xTrue2] = ode45(trueModel, tPred, x0Pred2, odeOptions);
% [~, xTrue3] = ode45(trueModel, tPred, x0Pred3, odeOptions);
% [~, xTrue4] = ode45(trueModel, tPred, x0Pred4, odeOptions);
% 
% xPred1 = dlode45(@odeModel,tPred,dlarray(x0Pred1),neuralOdeParameters,DataFormat="CB");
% xPred2 = dlode45(@odeModel,tPred,dlarray(x0Pred2),neuralOdeParameters,DataFormat="CB");
% xPred3 = dlode45(@odeModel,tPred,dlarray(x0Pred3),neuralOdeParameters,DataFormat="CB");
% xPred4 = dlode45(@odeModel,tPred,dlarray(x0Pred4),neuralOdeParameters,DataFormat="CB");
% % Visualize results
% figure
% subplot(2,2,1)
% plotTrueAndPredictedSolutions(xTrue1, xPred1);
% subplot(2,2,2)
% plotTrueAndPredictedSolutions(xTrue2, xPred2);
% subplot(2,2,3)
% plotTrueAndPredictedSolutions(xTrue3, xPred3);
% subplot(2,2,4)
% plotTrueAndPredictedSolutions(xTrue4, xPred4);

%% Helper functions
function X = model(tspan,X0,neuralOdeParameters)
X = dlode45(@odeModel,tspan,X0,neuralOdeParameters,DataFormat="CB");
end

function y = odeModel(~,y,theta)
y = tanh(theta.fc1.Weights*y + theta.fc1.Bias);
y = theta.fc2.Weights*y + theta.fc2.Bias;
end

function [loss,gradients] = modelLoss(tspan,X0,neuralOdeParameters,targets)
% Compute predictions.
X0 = X0';
X = model(tspan,X0,neuralOdeParameters);
% Compute L1 loss.
loss = l1loss(X,targets,NormalizationFactor="all-elements",DataFormat="CBT");
% Compute gradients.
gradients = dlgradient(loss,neuralOdeParameters);
end

% function [x0, targets] = createMiniBatch(numTimesteps,numTimesPerObs,miniBatchSize,X)
% % Create batches of trajectories.
% s = randperm(numTimesteps - numTimesPerObs, miniBatchSize);
% x0 = dlarray(X(:, s));
% targets = zeros([size(X,1) miniBatchSize numTimesPerObs]);
% for i = 1:miniBatchSize
%     targets(:, i, 1:numTimesPerObs) = X(:, s(i) + 1:(s(i) + numTimesPerObs));
% end
% end

function plotTrueAndPredictedSolutions(xTrue,xPred)
xPred = squeeze(xPred)';
err = mean(abs(xTrue(2:end,:) - xPred), "all");
plot(xTrue(:,1),xTrue(:,2),"r--",xPred(:,1),xPred(:,2),"b-",LineWidth=1)
title("Absolute Error = " + num2str(err,"%.4f"))
xlabel("x(1)")
ylabel("x(2)")
xlim([-2 3])
ylim([-2 3])
legend("Ground Truth","Predicted")
end