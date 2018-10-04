% Compare results from the estimated model and the original model

clc
%addpath('C:\Users\Xiaodong\Dropbox\automata learning\hybrid system learning\RSC\matlab')

%load temperature data generated from the estimated model
[tt, x1, x2, x3, x, chpoints1, chpoints2, chpoints3] = FnLoadData(TempHeatEST);
xEST = x;

%load temperature data generated from the original model
[tt, x1, x2, x3, x, chpoints1, chpoints2, chpoints3] = FnLoadData(TempHeat);
xGDT = x;

fig = figure

t = (0:length(x)-1)/10;
subplot(3,1,1)
plot(t, xEST(:,1), 'r');
hold on 
plot(t, xGDT(:,1), 'b')
hold off
grid on
ylabel('^o/degree')
legend('Estimated X_1', 'Ground Truth X_1')

subplot(3,1,2)
plot(t, xEST(:,2), 'r');
hold on 
plot(t, xGDT(:,2), 'b')
hold off
grid on
ylabel('^o/degree')
legend('Estimated X_2', 'Ground Truth X_2')

subplot(3,1,3)
plot(t, xEST(:,3), 'r');
hold on 
plot(t, xGDT(:,3), 'b')
hold off
grid on
xlabel('Time/s')
ylabel('degree/^o')
legend('Estimated X_3', 'Ground Truth X_3')

%print(fig, '-dpng', '-r1000')