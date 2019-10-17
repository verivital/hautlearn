x10 = 15;
x20 = 15;
x30 = 15;
C_signal=10;
sim('con_ESTHeatingSystem')
sim('HeatingSystem')
for i=1:3
    subplot(3,1,i)
    hold on
    error = xout(:,i) - est_xout(:,i);
    errorAbs = abs(error);
    traceError = vecnorm(error,2,2);
    e_mseT = norm(traceError);
    e_mse = norm(error);
    
    plot(xout(:,i), 'r')
    plot(est_xout(:,i), 'b')
%     plot( xout(:,i) + errorAbs, '-.k');
%     plot( xout(:,i) - errorAbs, '-.k');
end
