%%
figure
hold on
%%
fid_inferred = fopen('r_inferred_x3_x4.gen'); 
Vs_inferred = load('r_inferred_x3_x4.gen');
newline = sprintf('\n');
line = fgets(fid_inferred);
n = 1; ids_inferred = [1];
while ischar(line)
    if strcmp(newline, line)
       ids_inferred = [ids_inferred;n];
    else
        n = n+1;
    end
    line = fgets(fid_inferred);
end

for i = 2:length(ids_inferred)
    v = Vs_inferred(ids_inferred(i-1):(ids_inferred(i)-1),:);
    pv = Polyhedron(v);
    plot(pv,'color','r','edgecolor','r','alpha',1,'edgealpha',1)
end


%%
fid_original = fopen('r_original_x3_x4.gen'); 
Vs_original = load('r_original_x3_x4.gen');
newline = sprintf('\n');
line = fgets(fid_original);
n = 1; ids_original = [1];
while ischar(line)
    if strcmp(newline, line)
       ids_original = [ids_original;n];
    else
        n = n+1;
    end
    line = fgets(fid_original);
end

for i = 2:length(ids_original)
    v = Vs_original(ids_original(i-1):(ids_original(i)-1),:);
    pv = Polyhedron(v);
    plot(pv,'color','b','edgecolor','b','alpha',1,'edgealpha',1)
end



%%
v = [0.4,1.4;0.4,1.5;0.5,1.4;0.5,1.5];
pv = Polyhedron(v);
plot(pv,'color','g','edgecolor','k','alpha',1,'edgealpha',1)
