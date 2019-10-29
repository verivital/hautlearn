clear
mdl1 = 'automata_learning.slx';
mdl2 = 'HeatingSystem.slx';

T = 40; Ts = 0.1;
n = 10; num_var = 3; num_u = 1;
error_x = [];

aSet = [];
for i = 1:n
x1 = rand+14;
x2 = rand+14;
x3 = rand+14;
x_init = [x1;x2;x3];

%simulation
sim(mdl1);
sim(mdl2);

est_trace = FnProcessData2(est_xout, num_var, num_u);
trace = FnProcessData2(xout, num_var, num_u);
est_chp = est_trace.chpoints;
chp = trace.chpoints;
len_chp = min(length(est_chp), length(chp));

est_chp2 = est_chp(1:len_chp);
chp2 = chp(1:len_chp);

tau_max = max(abs(est_chp2-chp2));
e = [];
for j = 2:len_chp
    startj = chp(j-1);
    endj = chp(j);
    startj_est = est_chp(j-1);
    endj_est = est_chp(j);
    
    xs = trace.x(startj: endj,1:num_var);
    xs_est = est_trace.x(startj_est: endj_est,1:num_var);
    
    for h = 1:size(xs,1)
        start_temp = h-tau_max;
        end_temp = h+tau_max;
        if start_temp<1
            start_temp = 1;
        end
        if end_temp>size(xs_est,1)
            end_temp = size(xs_est,1);
        end

        xs_temp = xs(h,1:num_var)-xs_est(start_temp:end_temp,1:num_var);
        e_temp = min(diag(xs_temp*xs_temp'));
        e = [e, sqrt(e_temp)];
    end
    
    for h = 1:size(xs_est,1)
        start_temp = h-tau_max;
        end_temp = h+tau_max;
        if start_temp<1
            start_temp = 1;
        end
        if end_temp>size(xs,1)
            end_temp = size(xs,1);
        end
        xs_temp = xs_est(h,1:num_var)-xs(start_temp:end_temp,1:num_var);
        e_temp = min(diag(xs_temp*xs_temp'));
        e = [e, sqrt(e_temp)];
    end
end
    aSet = [aSet; T, len_chp, tau_max*Ts, max(e)];

end
max(aSet)


