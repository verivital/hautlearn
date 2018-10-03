 function [bestParameters, bestInIdx] = ransac_demo(chdata, alldata, n,iter,threshDist,inNum)
 
 chdata = chdata';
 number = size(chdata,2); % Total number of changepoints
 bestInNum = 0; % Best fitting line with largest number of inliers
 bestParameters=zeros(n,1); % parameters for best fitting line
 bestInIdx = 0;
 for i=1:iter
 % Randomly select num points
     if number<n
         break;
     end
     idx = randperm(number,n); sample = chdata(:,idx);   
     
    % Compute the distances between all points with the fitting line 
    sample_ones = [sample; ones(1,n)];
    [U,S,V] = svd(sample_ones);
    wb0 = U(:,n+1);
    b0 = wb0(n+1);
    w0 = wb0(1:n);
    distance = (w0'*chdata+repmat(b0,1,number))/norm(w0);
   
    % Compute the inliers with distances smaller than the threshold
    inlierIdx = find(abs(distance)<=threshDist);
    inlierNum = length(inlierIdx);
 
    samples = chdata(:,inlierIdx);
    samples = [samples; ones(1,length(samples))];
    [U,S,V] = svd(samples);
    wb0 = U(:,n+1);
    b0 = wb0(n+1);
    w0 = wb0(1:n);
    distance = (w0'*chdata+repmat(b0,1,number))/norm(w0);
    inlierIdx = find(abs(distance)<=threshDist);
    inlierNum = length(inlierIdx);
    %  Update the number of inliers and fitting model if better model is found
    if inlierNum>=inNum && inlierNum>bestInNum  
        samples = chdata(:,inlierIdx);
        samples = [samples; ones(1,length(samples))];
        [U,S,V] = svd(samples);
        wb0 = U(:,n+1);
        b0 = wb0(n+1);
        w0 = wb0(1:n);

        bestInNum = inlierNum;
        bestParameters = [w0;b0];
        bestInIdx = inlierIdx;
    end
  end
 end
 



