%% Generate Data from hybrid model example1
rng(5);
N = 25; % number of simulations
x0 = rand(N,4);
% Some initial states are fixed
z0 = 0;
a10 = pi/4;
a20 = 3*pi/4;
for i=1:N
    x10 = x0(i,1);
    x20 = 10+x0(i,2);
    y10 = x0(i,3);
    y20 = x0(i,4);
    out = sim("avoidance.slx");
    xout = [out.x1, out.x2, out.y1, out.y2, out.a1, out.a2, out.z, out.mode, out.tout];
    save("trainingdata/run"+num2str(i)+".mat","xout");
end