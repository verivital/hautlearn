

function [wb, inlayer, leftover] = FnEstLI(xchpoints, num,iter,threshDist,inNum)
    wb = [];
    inlayer = {};
    leftover = [];
    rel_index = 1:size(xchpoints,1); % to get the right index for the inlayers
    [bestParameters, bestInIdx] = ransac_demo(xchpoints, num, iter, threshDist, inNum);
    if bestInIdx ==0
        return
    end
    wb = bestParameters/bestParameters(end);
    inlayer = {rel_index(bestInIdx)};
    xchpoints(bestInIdx, :) = [];
    rel_index(bestInIdx) = [];
    
    while length(xchpoints)>=inNum
        [bestParameters, bestInIdx ]= ransac_demo(xchpoints, num, iter, threshDist, inNum);
        if bestParameters==0 
            break;
        end
        inlayer(end+1) = {rel_index(bestInIdx)};
        wb(:, end+1) = bestParameters/bestParameters(end);
        xchpoints(bestInIdx, :) = [];
        rel_index(bestInIdx) = [];
    end
    leftover = xchpoints;
end