function EstimateHA(data,params)
%ESTIMATEHA
%   Estimate hybrid automata from input/output traces
%
% EstimateHA(data, dyn, ...)
% data = data file (should contain timesteps)
% params = struct containing all user-defined parameters (linear vs nonlinear)
% 

% 1) Ensure data presents correct format and shape
data = load(data); % struct with fields 

% 2)  Check if dynamics is linear/nonlinear and process general params
dyns = params.dynamics;
% Cluster/process data
ub = params.ub; % upper and lower bounds to cluster traces (changepoint)
lb = params.lb;
% num_var % Get from data
windw

% Guards (LI)
eta = params.eta; % Number of iterations
lambda = params.lambda; % tolerance
gamma = params.gamma; % least number of inlayers

% 3) Check parameters are correct and correspond to the dynamics chosen

% 3a) Nonlinear
if strcmp(dyns,"nonlinear")
    try
        mu = params.mu;
    catch
        mu = 2; % Is there a way to actually choose this for each dynamic trace? 
    end
    try
        PolyDegree = params.PolyDegree; % optional (Default = 3)
    catch
        PolyDegree = 3;
    end
    try
        mdata = params.max_length; % optional (Default the data they provide? or set a limit in like 5000 points per trace?)
    catch
        mdata = 2401;
    end
    
% 3b) Linear
elseif strcmp(dyns, "linear")
    
else
    error('Wrong dynamics specified. Please, select nonlinear or linear.');
end


%% Helper Functions
    function dataP = load_data(data_files)
        for k = data_files
            data_temp = load(k);
            trace_temp = FnProcessData(data_temp.xout);
            trace(num) = trace_temp;  
            x = [x; trace(num).x];
            ud = [ud; trace(num).ud];
            num = num+1;
        end
    end

end

