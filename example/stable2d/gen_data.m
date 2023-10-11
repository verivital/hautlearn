%% Generate Data from hybrid model example1
rng(5);
N = 25; % number of simulations
X0 = 0.2*rand(N,2);
for i=1:N
    x0 = 0.9 + X0(i,1);
    y0 = -1.1 + X0(i,2);
    out = sim("stable2d.slx");
    xout = [out.x, out.y, out.mode, out.tout];
    save("trainingdata/run"+num2str(i)+".mat","xout");
end