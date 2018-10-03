

function [wb, inlayer] = LinearInequality(chdata, alldata, num,iter,threshDist,inNum)
    wb = [];
    inlayer = {};
    rel_index = 1:size(chdata,1); % to get the right index for the inlayers
    [bestParameters, bestInIdx] = ransac_demo(chdata, alldata, num, iter, threshDist, inNum);
    wb = bestParameters/bestParameters(end);
    inlayer = {rel_index(bestInIdx)};
    chdata(bestInIdx, :) = [];
    rel_index(bestInIdx) = [];
    
    while length(chdata)>=5
        [bestParameters, bestInIdx ]= ransac_demo(chdata, alldata, num, iter, threshDist, inNum);
        if bestParameters==0 
            break;
        end
        inlayer(end+1) = {rel_index(bestInIdx)};
        wb(:, end+1) = bestParameters/bestParameters(end);
        chdata(bestInIdx, :) = [];
        rel_index(bestInIdx) = [];
    end
end