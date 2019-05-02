function [vx, vy, x, y, chpoints1, chpoints2] = FnLoadData(xout)
    x = xout(:,1);
    y = xout(:,2);
    vx = xout(:,3);
    vy = xout(:,4);

    [points1t, chpoints1] = changepoint(vx);
    [points2t, chpoints2] = changepoint(vy);
end