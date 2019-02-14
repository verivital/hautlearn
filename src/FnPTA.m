function pta_trace = FnPTA(trace)
num = 1;
for n = 1:length(trace)
    labels_trace = trace(n).labels_trace;
    guard_trace = trace(n).guard_trace;
    for i = 1:length(labels_trace)-1
        pta_trace_temp.label1 = labels_trace(i);
        pta_trace_temp.guard = guard_trace(i); %guard condition
        pta_trace_temp.label2 = labels_trace(i+1);
        pta_trace_temp.id1 = num; %source state id
        if i ==1 % the first segment are all assigned with 1
             pta_trace_temp.id1 = 1; 
        end
        pta_trace_temp.id2 = num+1; %destination state id 
        pta_trace_temp.times = 1; 
        pta_trace(num) = pta_trace_temp;
        num = num+1;
    end
end

num = 1;

for n =1:length(pta_trace)-1
    if n == 262
        yy = 1;
    end
    if isempty(pta_trace(n).id1)
        continue;
    end
    
    label1 = pta_trace(n).label1;
    guard = pta_trace(n).guard;
    label2 = pta_trace(n).label2;
    
    % get the transition after id2
    guard_next = pta_trace(pta_trace(n).id2).guard;
    label2_next = pta_trace(pta_trace(n).id2).label2;
    
    for i =(n+1):length(pta_trace)
        if i == 157
            yy=1;
        end
        ilabel1 = pta_trace(i).label1;
        iguard = pta_trace(i).guard;
        ilabel2 = pta_trace(i).label2;

        if (label1==ilabel1)&(guard==iguard)&(label2==ilabel2)
            % if it is the last one, we choose to merge the transition
            if i == length(pta_trace)
                pta_trace(n).times = pta_trace(n).times+1;
                pta_trace = FnEmptyPTA(pta_trace,i);
                if pta_trace(i).id1 == pta_trace(i-1).id2
                    pta_trace(i-1).id2 = pta_trace(n).id1;
                end
            else 
                iguard_next = pta_trace(pta_trace(i).id2).guard;
                ilabel2_next = pta_trace(pta_trace(i).id2).label2;
                % check if it can cause non-deterministic after the id2
                if (iguard_next==guard_next)&(ilabel2_next~=label2_next)
                    continue;
                else
                    pta_trace(n).times = pta_trace(n).times+1;
                    if pta_trace(i).id2 > pta_trace(n).id2
                        % check if the current transition is connected to the
                        % lower one 
                        if (pta_trace(i).id2 == pta_trace(i+1).id1)&...
                                (pta_trace(i).label2 == pta_trace(i+1).label1)
                            pta_trace(i+1).id1 = pta_trace(n).id2;
                        end
                    elseif pta_trace(i).id2 < pta_trace(n).id2
                        if (pta_trace(n).id2 == pta_trace(n+1).id1)&...
                                (pta_trace(n).label2 == pta_trace(n+1).label1)
                            pta_trace(n+1).id1 = pta_trace(i).id2;
                        end
                        pta_trace(n).id2 = pta_trace(i).id2;
                    end
                    
                    if pta_trace(i).id1>pta_trace(n).id1
                        % check if the current transition is connected to the
                        % upper one 
                        if (pta_trace(i).id1 == pta_trace(i-1).id2)&...
                                (pta_trace(i).label1 == pta_trace(i-1).label2)
                            pta_trace(i-1).id2 = pta_trace(n).id1;
                        end
                    elseif pta_trace(i).id1<pta_trace(n).id1
                        nid = pta_trace(n).id1;
                        for j = 1:length(pta_trace)
                            if pta_trace(j).id1 ==  nid
                                pta_trace(j).id1 = pta_trace(i).id1;
                            end
                            if pta_trace(j).id2 ==  nid
                                pta_trace(j).id2 = pta_trace(i).id1;
                            end
                        end
                        pta_trace(n).id1 = pta_trace(i).id1;
                    end
                    % choose the minimum id2 before deleting the other one
                    %pta_trace(n).id2 = min(pta_trace(n).id2, pta_trace(i).id2);
                    pta_trace = FnEmptyPTA(pta_trace,i);
                end    
            end
        end
    end
end

id_empty =[];
for n = 1:length(pta_trace)
    if isempty(pta_trace(n).id1)
        id_empty(end+1,:) = n;
    end
    if pta_trace(n).guard ==0
        id_empty(end+1,:) = n;
    end
end
pta_trace(id_empty) = [];
%mapping ids to new ones
ids = [];
for i = 1:length(pta_trace)
    ids(end+1) = pta_trace(i).id1;
    ids(end+1) = pta_trace(i).id2;
end
[uniq_ids, ia,ic ]= unique(ids);

num=1;
for i = 1:length(pta_trace)
    pta_trace(i).id1 = ic(num);
    num = num+1;
    pta_trace(i).id2 = ic(num);
    num = num+1;
end
end

function pta_trace = FnEmptyPTA(pta_trace, id)
pta_trace(id).id1 = []; 
pta_trace(id).guard = []; 
pta_trace(id).id2 = []; 
pta_trace(id).label1 = []; 
pta_trace(id).label2 = []; 
pta_trace(id).times = []; 
end