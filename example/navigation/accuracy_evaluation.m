mdl1 = 'ESTNavigation.slx';
mdl2 = 'Navigation.slx';

T = 1.8;
n = 20;
error_x = [];
for i = 1:n
x1 = rand*0.1+0.5;
x2 = rand*0.1+0.5;
x3 = rand*0.1+1.4;
x4 = rand*0.1+1.4;
x_init = [x1;x2;x3;x4];

%simulation
sim(mdl1);
sim(mdl2);
est_trace = FnProcessData(est_xout, 4, 0);
trace = FnProcessData(xout, 4, 0);
est_chp = est_trace.chpoints;
chp = trace.chpoints;
len_chp = min(length(est_chp), length(chp));
for j = 2:len_chp
    est_startj = est_chp(j-1);
    est_endj = est_chp(j);
    est_len = est_endj- est_startj + 1;
    est_x = trace.x(est_startj:est_endj,:);
    
    startj = chp(j-1);
    endj = chp(j);
    len = endj- startj + 1;
    x = trace.x(startj:endj,:);
    
    if est_len > len
        est_x = est_x(1:(len/est_len):end,:);
    else
        x = x(1:(est_len/len):end,:);
    end
    
    min_len = min(size(est_x,1), size(x,1));
    est_x = est_x(1:min_len,:);
    x = x(1:min_len,:);
    error_temp = est_x-x;
    error_x = [error_x;error_temp];
end
end
mean(error_x)
std(error_x)

