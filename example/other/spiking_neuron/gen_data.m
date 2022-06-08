%% Generate Data from hybrid model example1
% Example1 has just 2 variables and two modes
rng(5);
N = 25; % number of simulations
x0 = 0.1*rand(N,2);
% h = 0.05; % Fixed in the simulink model
for i=1:N
    v0 = x0(i,1)-63;
    u0 = x0(i,2);
    out = sim("spiking_neuron.slx");
    xout = [out.v_out, out.u_out, out.tout];
    save("trainingdata/run"+num2str(i)+".mat","xout");
end