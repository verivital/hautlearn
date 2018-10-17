% this function takes a matrix A, which is an element of the ode list
% variable returned by other parts of the automata learning
function [out] = odeMatrixToString(A,varNames)
    x = [];
    
    n = length(varNames); % state space dimensionality
    
    for i = 1 : n
        x = [x; sym(varNames{i})];
    end
    
    Ar = A(1:n,1:n); % this matrix that ode returns is not just the A matrix, it has some extra parts so the dimensionality is greater than n
    
    % TODO: add in the B part of however the input affects things, e.g.,
    % the extra rows/columns of the ode matrix
    n_extra = length(A);
    Br = A(1:n,n_extra);
    
    tmp = string(vpa(Ar * x + Br, 4)); % round to 4 decimals; TODO: make this a config option
    odeStrConjunction = '';
    for i = 1 : n
        odeStr = strcat(varNames(i), ''' == ', tmp(i));
        if i > 1
            odeStrConjunction = strcat(odeStrConjunction, ' & ');
        end
        odeStrConjunction = strcat(odeStrConjunction, ' ', odeStr);
        tmp(i) = java.lang.String(odeStr);
    end
    %out = tmp;
    out = odeStrConjunction;
end