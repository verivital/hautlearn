function theta = sysID(W,h,pars)
% This is the script to perform the system identification routine using occupation kernels.
% h is the timestep (double) (1x1)
% W is the collection of trajectories (struct) with m trajectories of (num_var x time_length)
%% Load data
t = tic;
TrajectoryInfo = size(W);
TotalTrajectories = TrajectoryInfo(1);
LengthTrajectories = TrajectoryInfo(3);
n = TrajectoryInfo(2);
% Bounds and sampling for centers from data (W)
xmin = min(W,[],1);
xmin = min(xmin,[],3);
xmax = max(W,[],1);
xmax = max(xmax,[],3);
% How do we select the next two values?
dd = max(xmax - xmin);
hspacing = dd/10;
mu = mean(std(W,[],'all')); 

%% Select parameters
% Check for extra selection of learning parameters
if ~isstruct(pars)
    warning("Invalid or empty parameters (pars) value. Using default parameters.")
    pars = struct;
end
if isfield(pars,'usenoise')
    usenoise = pars.usenoise;
else
    usenoise = 0;
end
if isfield(pars,'movingaverage')
    movingaverage = pars.movingaverage;
else
    movingaverage = 0 ;
end
if isfield(pars,'usebasis')
    usebasis = pars.usebasis;
else
    usebasis = 1;
end
if isfield(pars, 'polydegree')
    polydegree = pars.polydegree;
else
    polydegree = 2;
end
if isfield(pars, 'usekernel')
    usekernel = pars.usekernel;
else
    usekernel = 1;
end
if isfield(pars, 'numericalintegration')
    numericalintegration = pars.numericalintegration;
else
    numericalintegration = 2;
end

%% Preprocess data
% Noise
if(usenoise == 1)
    noise = normrnd(0,magnitudeofnoise,TotalTrajectories,n,LengthTrajectories);
    W = W + noise;
end
% Moving Average
if(exist('movingaverage','var'))
    if(movingaverage > 0)
        bandedmatrix = toeplitz([ones(1,movingaverage),zeros(1,LengthTrajectories-movingaverage)],[1,zeros(1,LengthTrajectories-1)])';
        for i=1:TotalTrajectories
            HoldMatrix = zeros(n,LengthTrajectories);
            for j=1:n
                HoldMatrix(j,:) = W(i,j,:);
            end
            HoldMatrix = 1/movingaverage*HoldMatrix*bandedmatrix;
            W(i,:,:) = HoldMatrix;
        end
        W=W(:,:,movingaverage+1:end);
        LengthTrajectories = LengthTrajectories - movingaverage;
    end
end

% Time scale
TimeScale = h;

%% Dynamics Definition

% f = theta'*Y, where Y \in R^m
% Define Y_i(x)
% usebasis = 1;
if(usebasis == 1)
    % Generates a Monomial Basis with all monomials of dimension n up to degree polydegree
    % There's a slicker way to do this, but I also wanted to keep track of
    % the degree of the particular monomial, which is enumerated in
    % PowerChecker
    
%     if(~exist('polydegree','var'))
%         polydegree = 2; %Default to quadratic systems
%     end
    checkpowers = (2.^(0:polydegree))';
    for i=2:n
        checkpowers = reshape(checkpowers*2.^(0:polydegree),[],1); %x assumed to be column vector
    end
    checkpowers = log2(checkpowers);
    
    collectprimes = primes(2^n);
    setpowers = (collectprimes(1).^(0:polydegree))';
    for i=2:n
        setpowers = reshape(setpowers*collectprimes(i).^(0:polydegree),[],1); %x assumed to be column vector
    end
    
    setpowers = setpowers(checkpowers <= polydegree);
    
    powermatrixsize = size(setpowers);
    
    powermatrix = zeros(powermatrixsize(1),n);
    
    for i=1:powermatrixsize(1)
        factorvector = factor(setpowers(i));
        for j = 1:n
            primepower = sum(factorvector == collectprimes(j));
            powermatrix(i,j) = primepower;
        end
    end
    Y = @(x) kron(eye(n),prod(((ones(powermatrixsize(1),n)*diag(x)).^powermatrix)')');
    PowerChecker = kron(eye(n),powermatrix);    
end

NumberOfBasis = size(Y(zeros(n,1)));
NumberOfBasis = NumberOfBasis(1);

%% Kernel Definition

% Kernel Functions
% usekernel = 1;
if(usekernel == 1)
    %Gaussian Kernel Function
    %mu = 10; %mu = 1/2 for example2trajs
    K = @(x,y) exp( -1/mu * norm(x-y)^2 );
    
    % Liouville Operators Acting on Kernels
    % A_f K = nabla K * A_f. Need this for f = Yi
    % x,y should be column vectors.
    
    % For the gaussian in particular
    AK = @(x,y) (-2/mu*(x-y)'*K(x,y)*Y(x)')';

else
    %Exponential Dot Product Kernel
    mu = 1/(mu^4);
    K = @(x,y) exp( mu*x'*y );
    AK = @(x,y) (mu*y'*K(x,y)*Y(x)')';
end

%% Select Centers for the constriant kernels
% Code only allows for 2D and 3D data for now

% 2D data
if(n==2)
    x1 = xmin(1):hspacing:xmax(1);
    x2 = xmin(2):hspacing:xmax(2);
    [Xcenters,Ycenters] = meshgrid(x1,x2);

    % Compute Constraint Matrix
    ConstraintMatrix = zeros(length(x1)*length(x2)*TotalTrajectories,NumberOfBasis);
    if(numericalintegration == 2 && mod(LengthTrajectories,2) == 0)
        LengthTrajectories = LengthTrajectories - 1;
        W = W(:,:,1:end-1);
    end
    indexing = 1;
    for i = 1:length(x1)
        for j = 1:length(x2)
            % Kernel Function selected corresponding to center i,j.
            for l=1:TotalTrajectories
                % Trajectory l selected.
                    % Numerical Integration
                    if(numericalintegration == 0)
                        %Right Hand Rule
                        sum1 = zeros(NumberOfBasis,1);
                        for s=1:LengthTrajectories
                            nextone = AK(W(l,:,s)',[Xcenters(j,i);Ycenters(j,i)]);
                            sum1 = sum1 + nextone;
                        end
                        sum1 = sum1*TimeScale;
                    elseif(numericalintegration == 1)
                        %Trapezoid Rule
                        sum1 = zeros(NumberOfBasis,1);
                        lastone = AK(W(l,:,1)',[Xcenters(j,i);Ycenters(j,i)]);
                        for s=2:LengthTrajectories
                            nextone = AK(W(l,:,s)',[Xcenters(j,i);Ycenters(j,i)]);
                            sum1 = sum1 + 1/2*lastone + 1/2*nextone;
                            lastone=nextone;
                        end
                        sum1 = sum1*TimeScale;
                    else
                        %Simpsons Rule
                        sum1 = zeros(NumberOfBasis,1);
                            lastone = AK(W(l,:,1)',[Xcenters(j,i);Ycenters(j,i)]);
                            for s=1:(LengthTrajectories-1)/2
                                firstone = lastone;
                                middleone = AK(W(l,:,2*s)',[Xcenters(j,i);Ycenters(j,i)]);
                                lastone = AK(W(l,:,2*s+1)',[Xcenters(j,i);Ycenters(j,i)]);
                                sum1 = sum1 + firstone + 4*middleone + lastone;
                            end
                            sum1 = sum1*TimeScale/3;
                    end
                    ConstraintMatrix(indexing,:) = sum1';
                    indexing = indexing+1;
            end
        end
    end

    EqualityConstraint = zeros(length(x1)*length(x2)*TotalTrajectories,1);
    indexing = 1;
    for i = 1:length(x1)
        for j = 1:length(x2)
            for l=1:TotalTrajectories
                EqualityConstraint(indexing) = K([Xcenters(j,i);Ycenters(j,i)],W(l,:,end)')-K([Xcenters(j,i);Ycenters(j,i)],W(l,:,1)');
                indexing=indexing+1;
            end
        end
    end
% 3D data
elseif(n==3)
    x1 = xmin(1):hspacing:xmax(1);
    x2 = xmin(2):hspacing:xmax(2);
    x3 = xmin(3):hspacing:xmax(3);
    [Xcenters,Ycenters,Zcenters] = meshgrid(x1,x2,x3);

    % Compute Constraint Matrix
    ConstraintMatrix = zeros(length(x1)*length(x2)*length(x3)*TotalTrajectories,NumberOfBasis);
    if(numericalintegration == 2 && mod(LengthTrajectories,2) == 0)
        LengthTrajectories = LengthTrajectories - 1;
        W = W(:,:,1:end-1);
    end
    indexing = 1;
    for i = 1:length(x1)
        for j = 1:length(x2)
            for ii = 1:length(x3)
            % Kernel Function selected corresponding to center i,j.
                for l=1:TotalTrajectories
                    % Trajectory l selected.
                        % Numerical Integration
                        if(numericalintegration == 0)
                            %Right Hand Rule
                            sum1 = zeros(NumberOfBasis,1);
                            for s=1:LengthTrajectories
                                nextone = AK(W(l,:,s)',[Xcenters(j,i,ii);Ycenters(j,i,ii);Zcenters(j,i,ii)]);
                                sum1 = sum1 + nextone;
                            end
                            sum1 = sum1*TimeScale;
                        elseif(numericalintegration == 1)
                            %Trapezoid Rule
                            sum1 = zeros(NumberOfBasis,1);
                            lastone = AK(W(l,:,1)',[Xcenters(j,i,ii);Ycenters(j,i,ii);Zcenters(j,i,ii)]);
                            for s=2:LengthTrajectories
                                nextone = AK(W(l,:,s)',[Xcenters(j,i,ii);Ycenters(j,i,ii);Zcenters(j,i,ii)]);
                                sum1 = sum1 + 1/2*lastone + 1/2*nextone;
                                lastone=nextone;
                            end
                            sum1 = sum1*TimeScale;
                        else
                            %Simpsons Rule
                            sum1 = zeros(NumberOfBasis,1);
                            lastone = AK(W(l,:,1)',[Xcenters(j,i,ii);Ycenters(j,i,ii);Zcenters(j,i,ii)]);
                            for s=1:(LengthTrajectories-1)/2
                                firstone = lastone;
                                middleone = AK(W(l,:,2*s)',[Xcenters(j,i,ii);Ycenters(j,i,ii);Zcenters(j,i,ii)]);
                                lastone = AK(W(l,:,2*s+1)',[Xcenters(j,i,ii);Ycenters(j,i,ii);Zcenters(j,i,ii)]);
                                sum1 = sum1 + firstone + 4*middleone + lastone;
                            end
                            sum1 = sum1*TimeScale/3;
                        end
                        
                        ConstraintMatrix(indexing,:) = sum1';
                        indexing = indexing+1;
                end
            end
        end
    end
    EqualityConstraint = zeros(length(x1)*length(x2)*length(x3)*TotalTrajectories,1);
    indexing = 1;
    for i = 1:length(x1)
        for j = 1:length(x2)
            for s = 1:length(x3)
                for l=1:TotalTrajectories
                    EqualityConstraint(indexing) = K([Xcenters(j,i,s);Ycenters(j,i,s);Zcenters(j,i,s)],W(l,:,end)')-K([Xcenters(j,i,s);Ycenters(j,i,s);Zcenters(j,i,s)],W(l,:,1)');
                    indexing=indexing+1;
                end
            end
        end
    end
end

%% Determine theta
theta = inv(ConstraintMatrix'*ConstraintMatrix)*ConstraintMatrix'*EqualityConstraint;
toc(t);

end

