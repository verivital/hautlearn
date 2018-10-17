% this function takes a matrix A, which is an element of the ode list
% variable returned by other parts of the automata learning
function [out] = guardVectorToString(V,varNames)
    x = [];
    
    n = length(varNames); % state space dimensionality
    
    for i = 1 : n
        x = [x; sym(varNames{i})];
    end
    
    Vr = V(1:n,:)'; % this matrix that ode returns is not just the A matrix, it has some extra parts so the dimensionality is greater than n
    

    tmp = string((vpa(Vr * x, 4))); % round to 4 decimals; TODO: make this a config option
    odeStrConjunction = '';
    for i = 1 : size(V,2)
        if V(end,i)==-1
            odeStr = strcat(tmp(i),'+1<0');
        else
             odeStr = strcat(tmp(i),'+1>0');
        end
        
        if i > 1
            odeStrConjunction = strcat(odeStrConjunction, ' && ');
        end
        odeStrConjunction = strcat(odeStrConjunction, ' ', odeStr);
        tmp(i) = java.lang.String(odeStr);
    end
    %out = tmp;
    out = odeStrConjunction;
end