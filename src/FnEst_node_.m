function dlnet = FnEst_node_(trace)
global Ts nL hS act_function
% Trace data 
xTrain = trace; %
X0 = squeeze(xTrain(:,:,1));
numTimeSteps = size(xTrain,3);
tf = numTimeSteps*Ts;
timesteps = Ts:Ts:tf;

%% Define Model
% Initialize parameters structure
neuralOdeParameters = {};
stateSize = size(X0,1);
hiddenSize = hS;
% Create input layer parameters
sz = [hiddenSize stateSize];
neuralOdeParameters{1} = initializeGlorot(sz, hiddenSize, stateSize);
neuralOdeParameters{2} = initializeZeros([hiddenSize 1]);
% Create hidden layers
if nL < 0
    error("Number of hidden layers must be greater than or equal to 0")
else
    sz = [hiddenSize hiddenSize];
    for ijk=2:1:nL+1
        neuralOdeParameters{2*ijk-1} = initializeGlorot(sz, hiddenSize, hiddenSize);
        neuralOdeParameters{2*ijk} = initializeZeros([hiddenSize 1]);
    end
end
% Create output layer
sz = [stateSize hiddenSize];
neuralOdeParameters{2*nL+3} = initializeGlorot(sz, stateSize, hiddenSize);
neuralOdeParameters{2*nL+4} = initializeZeros([stateSize 1]);

%% Specify training options

gradDecay = 0.9;
sqGradDecay = 0.999;
learnRate = 0.001;
numIter = 10000;
X0 = dlarray(X0);
targets = xTrain(:,:,2:end);

%% Train model
best_loss = 10000000;
track_train = 0;
averageGrad = [];
averageSqGrad = [];

tt = tic;
for iter=1:numIter    
    % Evaluate network and compute gradients 
    [loss,gradients] = dlfeval(@modelLoss,timesteps,X0,neuralOdeParameters,targets);
    % Update network 
    [neuralOdeParameters,averageGrad,averageSqGrad] = adamupdate(neuralOdeParameters,gradients,averageGrad,averageSqGrad,iter,...
        learnRate,gradDecay,sqGradDecay);
    currentLoss = extractdata(loss); % Store loss 
    if currentLoss < best_loss
        best_loss = currentLoss;
        best_params = neuralOdeParameters;
        track_train = 0;
    else
        track_train = track_train + 1;
    end
    
    % Early-stop training
    if track_train >= 100
        disp("Early-stop training");
        break
    end
end
toc(tt);
dlnet = best_params;

%% Helper Functions
function X = model(tspan,X0,neuralOdeParameters)
    X = dlode45(@odeModel,tspan,X0,neuralOdeParameters, DataFormat="CB");
end

function y = odeModel(~,y,theta)
% Add hidden layers
for ij = 1:nL+1
    y = theta{2*ij-1}*y + theta{2*ij};
    if strcmpi(act_function, "linear")
        continue
    elseif strcmpi(act_function,"tanh")
        y = tanh(y);
    elseif strcmpi(act_function, "sigmoid")
        y = sigmoid(y);
    else
        error("Wrong layer type")
    end
end
y = theta{end-1}*y + theta{end};
end

function [loss,gradients] = modelLoss(tspan,X0,neuralOdeParameters,targets)
    % Compute predictions.
    X = model(tspan,X0,neuralOdeParameters);
    % Compute L1 loss.
    loss = l1loss(X,targets,NormalizationFactor="all-elements",DataFormat="CBT");
    % Compute gradients.
    gradients = dlgradient(loss,neuralOdeParameters);
end

end

