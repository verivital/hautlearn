%% Generate Data from hybrid model example1
rng(5);
N = 25; % number of simulations
X0 = rand(N,3);
for i=1:N
    x0 = 5.5 + X0(i,1);
    y0 = -5.5 - X0(i,2);
    z0 = 3.1 + X0(i,3);
    out = sim("stable3d.slx");
    xout = [out.x, out.y, out.z, out.mode, out.tout];
    save("trainingdata/run"+num2str(i)+".mat","xout");
end