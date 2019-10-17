mdl1 = 'automata_learning.slx';
mdl2 = 'buck_dcm_vs1.slx';


n = 20;
error_x = [];
for i = 1:n
x1 = rand*2-1;
x2 = rand*2-1;
x0 = [x1;x2];

%simulation
T = 0.02; Ts = 0.00005;
sim(mdl1);
T = 0.02; Ts = 0.00005;
sim(mdl2);
est_trace = FnProcessData(est_xout, 2, 0);
trace = FnProcessData(xout, 2, 0);
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

