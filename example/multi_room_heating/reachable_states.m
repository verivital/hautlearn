md11 = 'ESTHeatingSystem.slx';
mdl2 = 'HeatingSystem.slx';

num = 500; T = 100;
% est_X1 = []; est_X2 = []; est_X3 = [];
% X1 = []; X2 = []; X3 = [];
for i = 1:num
    %set init
    x1 = rand+14;
    x2 = rand+14;
    x3 = rand+14;
    x_init = [x1;x2;x3];

    %Run the simulation.
    sim(md11)
    est_X1 = [est_X1,est_xout(:,1)];
    est_X2 = [est_X2,est_xout(:,2)];
    est_X3 = [est_X3,est_xout(:,3)];
    
    sim(mdl2)
    X1 = [X1,xout(:,1)];
    X2 = [X2,xout(:,2)];
    X3 = [X3,xout(:,3)];
end

%%
v = [14,14;
    14,15;
    15,14;
    15,15];
pv = Polyhedron(v);
plot(pv,'color','g','edgecolor','k','alpha',1,'edgealpha',1)



