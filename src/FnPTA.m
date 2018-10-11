function pta_trace = FnPTA(trace)
num = 1;
for n = 1:length(trace)
    labels_trace = trace(n).labels_trace;
    guard_trace = trace(n).guard_trace;
    for i = 1:length(labels_trace)-1
        pta_trace_temp.s1 = num; %source state id
        pta_trace_temp.guard = guard_trace(i); %guard condition
        pta_trace_temp.s2 = num+1; %destination state id 
        pta_trace_temp.label1 = labels_trace(i);
        pta_trace_temp.label2 = labels_trace(i+1);
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
    if isempty(pta_trace(n).s1)
        continue;
    end
    
    label1 = pta_trace(n).label1;
    guard = pta_trace(n).guard;
    label2 = pta_trace(n).label2;
    
    % get the transition after s2
    guard_next = pta_trace(pta_trace(n).s2).guard;
    label2_next = pta_trace(pta_trace(n).s2).label2;
    
    for i =(n+1):length(pta_trace)

        ilabel1 = pta_trace(i).label1;
        iguard = pta_trace(i).guard;
        ilabel2 = pta_trace(i).label2;

        if (label1==ilabel1)&(guard==iguard)&(label2==ilabel2)
            if i == 261
                yy =1;
            end
            % if it is the last one, we choose to merge the transition
            if i == length(pta_trace)
                pta_trace(n).times = pta_trace(n).times+1;
                pta_trace = FnEmptyPTA(pta_trace,i);
                if pta_trace(i).s1 == pta_trace(i-1).s2
                    pta_trace(i-1).s2 = pta_trace(n).s1;
                end
            else 
                iguard_next = pta_trace(pta_trace(i).s2).guard;
                ilabel2_next = pta_trace(pta_trace(i).s2).label2;
                % check if it can cause non-deterministic after the s2
                if (iguard_next==guard_next)&(ilabel2_next~=label2_next)
                    continue;
                else
                    pta_trace(n).times = pta_trace(n).times+1;
                    % check if the upper transition is connected to the
                    % lower one 
                    if (pta_trace(i).s2 == pta_trace(i+1).s1)&...
                            (pta_trace(i).label2 == pta_trace(i+1).label1)
                        pta_trace(i+1).s1 = pta_trace(n).s2;
                    end
                    % check if the upper transition is connected to the
                    % lower one 
                    if (pta_trace(i).s1 == pta_trace(i-1).s2)&...
                            (pta_trace(i).label1 == pta_trace(i-1).label2)
                        pta_trace(i-1).s2 = pta_trace(n).s1;
                    end
                    % choose the minimum s2 before deleting the other one
                    pta_trace(n).s2 = min(pta_trace(n).s2, pta_trace(i).s2);
                    pta_trace = FnEmptyPTA(pta_trace,i);
                end    
            end
        end
    end
end

id_empty =[];
for n = 1:length(pta_trace)
    if isempty(pta_trace(n).s1)
        id_empty(end+1,:) = n;
    end
end
pta_trace(id_empty) = [];