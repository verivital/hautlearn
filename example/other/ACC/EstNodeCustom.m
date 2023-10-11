function dlnet = EstNodeCustom(trace,hl,hs,neuralOdeSteps, batchsize)
% trace = data
% hl = number of hidden layers
% hs = number of neurons per layer
global Ts
% Trace data 
x = trace; %
% t = x(end,:);
% dt = t(2); % Time step size, should be the training data (can also do like t(2)-t(1)),
% x = x(1:end-1,:); % Use only the actual state values
numTimeSteps = round((length(x)-1)/10);

% 2) Define the Network
% hiddenSize = 30; % Could add this as an input
inputSize = size(x,1);
outputSize = inputSize;

neuralOdeLayers = [];
for nl=1:hl
    neuralOdeLayers = [ neuralOdeLayers
    fullyConnectedLayer(hs)
    tanhLayer
    ];
end
neuralOdeLayers = [neuralOdeLayers
    fullyConnectedLayer(outputSize)
    ];

neuralOdeInternalDlnetwork = dlnetwork(neuralOdeLayers,'Initialize',false);
% neuralOdeInternalDlnetwork.Learnables
% Define ode solver parameters
neuralOdeInternalTimesteps = neuralOdeSteps; % This is to learn the ODE, let's see how this would affect the learning
neuralOdeLayerName = 'neuralOde';
customNeuralOdeLayer = neuralOdeLayer(neuralOdeInternalDlnetwork,neuralOdeInternalTimesteps,Ts,neuralOdeLayerName);
% Initialize the network
dlnet = dlnetwork(customNeuralOdeLayer,'Initialize',false);
dlnet = initialize(dlnet, dlarray(ones(inputSize,1),'CB'));

% 3) Specify Training Options (ADAM)
% Is there a way to optimize the training for each trace?
gradDecay = 0.9;
sqGradDecay = 0.999;
learnRate = 0.0001;
numIter = 1000;
miniBatchSize = batchsize;
% lossHistory = [];
best_loss = 10000000;
track_train = 0;

% 4) Train Network Using Custom Training Loop
averageGrad = [];
averageSqGrad= [];
numTrainingTimesteps = numTimeSteps;

tt = tic;
for iter=1:numIter
    % Create batch 
    
    [dlx0, targets] = createMiniBatch(numTrainingTimesteps, neuralOdeInternalTimesteps, miniBatchSize, x);
    % Evaluate network and compute gradients 
    [grads,loss] = dlfeval(@modelGradients,dlnet,dlx0,targets);
    % Update network 
    [dlnet,averageGrad,averageSqGrad] = adamupdate(dlnet,grads,averageGrad,averageSqGrad,iter,...
        learnRate,gradDecay,sqGradDecay);
    currentLoss = extractdata(loss); % Store loss to check scores later?
    if currentLoss < best_loss
        best_loss = currentLoss;
        best_params = dlnet.Learnables;
        track_train = 0;
    else
        track_train = track_train + 1;
    end
    
    % Early-stop training
    if track_train >= 50
        disp("Too many steps without learning");
        break
    end
end
toc(tt);
disp(best_loss);
dlnet.Learnables = best_params;

% Add some early stop function? Like, if val score does not improve for X
% steps, stop and return best model
% Some validation steps and update weights only when the val score is
% better than than previous val score?

%% Helper Functions
% 6) Model Gradients Function

% This function takes a set of initial conditions, dlx0, and target 
% sequences, targets, and computes the loss and gradients with respect 
% to the parameters of the network.
function [gradients,loss] = modelGradients(dlnet, dlX0, targets)
    % Compute prediction of network
    dlX = forward(dlnet,dlX0);
    % Compute mean absolute error loss
    loss = sum(abs(dlX - targets), 'all') / numel(dlX);
    % Compute gradients
    gradients = dlgradient(loss,dlnet.Learnables);
end

% This function creates a batch of observations of the target dynamics.
function [dlX0, dlT] = createMiniBatch(numTimeSteps, numTimesPerObs, miniBatchSize, X)
    % Create batches of trajectories
%     s = randperm(numTimesteps - numTimesPerObs, miniBatchSize);
    s = randi(numTimeSteps-10*numTimesPerObs,1,miniBatchSize)*10+1; % Get initial point of change in a_ego 
    dlX0 = dlarray(X(:, s),'CB');
    dlT = zeros([size(dlX0,1) miniBatchSize numTimesPerObs]);
    for i = 1:miniBatchSize
        dlT(:, i, 1:numTimesPerObs) = X(:, s(i):(s(i) + numTimesPerObs - 1));
    end
end

end

