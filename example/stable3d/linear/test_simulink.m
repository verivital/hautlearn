% Compare the original model to the estimated one using Simulink
close_system('automata_learning',0); % To avoid confusion with other simulations, 0 is in case the model does not exists, it does not generate warning
% We use a constant step to measure the mse
x0=2.5; y0=-2.5; z0 = 1.2;% Have to change the estimated model to have these as the initial states.
out = sim('../stable3d.slx','StartTime','0','StopTime','10','FixedStep','0.01');
out_est = sim('output_slsf_models/automata_learning.mdl','StartTime','0','StopTime','10','FixedStep','0.01');
xtest = [out.x, out.y, out.z];
simHA = [out_est.ScopeData.signals(1).values, out_est.ScopeData.signals(2).values, out_est.ScopeData.signals(3).values];
simT = out.tout;

% Compute mse
dif = simHA-xtest;
dif = dif.^2;
MSE = mean(dif,"all");

% Visualize Simulations
f = figure;
hold on;
plot(xtest(:,1),xtest(:,2),'r','DisplayName','Ground Truth');
plot(simHA(:,1),simHA(:,2),'b','DisplayName','Estimated');
xlabel('x_1')
ylabel('x_2')
fontsize(gca,15,'points');
lgd = legend;
lgd.Location = 'Best';
saveas(f,'test_12.png');

f = figure;
hold on;
plot(xtest(:,1),xtest(:,3),'r','DisplayName','Ground Truth');
plot(simHA(:,1),simHA(:,3),'b','DisplayName','Estimated');
xlabel('x_1')
ylabel('x_3')
fontsize(gca,15,'points');
lgd = legend;
lgd.Location = 'Best';
saveas(f,'test_13.png');

f = figure;
hold on;
plot(xtest(:,2),xtest(:,3),'r','DisplayName','Ground Truth');
plot(simHA(:,2),simHA(:,3),'b','DisplayName','Estimated');
xlabel('x_1')
ylabel('x_2')
fontsize(gca,15,'points');
lgd = legend;
lgd.Location = 'Best';
saveas(f,'test_23.png');
% This figure is okay, but hard to follow, with time and switches will be
% better

f2 = figure;
hold on;
plot(simT,xtest(:,1),'r','DisplayName','Ground Truth');
plot(simT,simHA(:,1),'b','DisplayName','Estimated');
xlabel('Time (s)')
ylabel('x_1')
fontsize(gca,15,'points');
lgd = legend;
lgd.Location = 'Best';
saveas(f2,'test_1.png'); 

f3 = figure;
hold on;
plot(simT,xtest(:,2),'r','DisplayName','Ground Truth');
plot(simT,simHA(:,2),'b','DisplayName','Estimated');
xlabel('Time (s)')
ylabel('x_2')
lgd = legend;
lgd.Location = 'Best';
fontsize(gca,15,'points');
saveas(f3,'test_2.png');

f3 = figure;
hold on;
plot(simT,xtest(:,3),'r','DisplayName','Ground Truth');
plot(simT,simHA(:,3),'b','DisplayName','Estimated');
xlabel('Time (s)')
ylabel('x_3')
lgd = legend;
lgd.Location = 'Best';
fontsize(gca,15,'points');
saveas(f3,'test_3.png');