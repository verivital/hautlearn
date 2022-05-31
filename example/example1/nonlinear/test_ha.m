% Test computed hybrid system
HA = ex1_nl;

% Set parameters
params.startLoc = 1;
params.tFinal = 50;

% Load testing data
testD = load('../trainingdata/run20.mat');
xtest = testD.xout;

params.x0 = xtest(1,1:2);

% Simulate system
[t,x,locs] = simulate(HA,params);
% Convert from cell to array
simHA = [];
simT = [];
simLoc = [];
for i=1:length(x)
    simHA = [simHA; x{i}];
    simT = [simT; t{i}];
    simLoc = [simLoc; locs{i}];
end

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
saveas(f,'test.png');
% This figure is okay, but hard to follow, with time and switches will be
% better

f2 = figure;
hold on;
plot(xtest(:,4),xtest(:,1),'r','DisplayName','Ground Truth');
plot(simT,simHA(:,1),'b','DisplayName','Estimated');
xlabel('Time (s)')
ylabel('x_1')
fontsize(gca,15,'points');
lgd = legend;
lgd.Location = 'Best';
saveas(f2,'test_1.png');

f3 = figure;
hold on;
plot(xtest(:,4),xtest(:,2),'r','DisplayName','Ground Truth');
plot(simT,simHA(:,2),'b','DisplayName','Estimated');
xlabel('Time (s)')
ylabel('x_2')
lgd = legend;
lgd.Location = 'Best';
fontsize(gca,15,'points');
saveas(f3,'test_2.png');


