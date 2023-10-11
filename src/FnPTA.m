% trace by trace
function pta_trace = FnPTA(trace)
num = 1;
seg_ids = [];
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
             seg_ids = [seg_ids; num];
        end
        pta_trace_temp.id2 = num+1; %destination state id 
        pta_trace_temp.times = 1; 
        pta_trace_set(num) = pta_trace_temp;
        num = num+1;
    end
end

pta_trace_new = get_pta_trace(1, seg_ids, pta_trace_set);
for n = 2:(length(seg_ids)-1)
    pta_trace2 = get_pta_trace(n, seg_ids, pta_trace_set);
    pta_trace_new = combine_pta(pta_trace_new, pta_trace2, pta_trace_set);
end
pta_trace = modify_pta(pta_trace_new);
end

function pta_trace_new = combine_pta(pta_trace1, pta_trace2, pta_trace_set)
    for n =1:length(pta_trace1)-1
        label1 = pta_trace1(n).label1;
        guard = pta_trace1(n).guard;
        label2 = pta_trace1(n).label2;
        % % get the transition after id2
        %guard_next = pta_trace_set(pta_trace1(n).id2).guard;
        %label2_next = pta_trace_set(pta_trace1(n).id2).label2;
        for i = 1:(length(pta_trace2)-1)
            ilabel1 = pta_trace2(i).label1;
            if isempty(ilabel1)
                continue
            end
            iguard = pta_trace2(i).guard;
            ilabel2 = pta_trace2(i).label2;
            %iguard_next = pta_trace_set(pta_trace2(i).id2).guard;
            %ilabel2_next = pta_trace_set(pta_trace2(i).id2).label2;
            
            if (label1==ilabel1)&(guard==iguard)&(label2==ilabel2) & checkFeasb(n, i, pta_trace1, pta_trace2)
                pta_trace1(n).times = pta_trace1(n).times+1;

                if n>1 & (pta_trace1(n-1).id2 ==pta_trace1(n).id1)
                    pta_trace1(n-1).id2 = min(pta_trace1(n).id1, pta_trace2(i).id1);
                end
                if n<length(pta_trace1) & (pta_trace1(n+1).id1==pta_trace1(n).id2)
                    pta_trace1(n+1).id1 = min(pta_trace1(n).id2, pta_trace2(i).id2);
                end
                pta_trace1(n).id1 = min(pta_trace1(n).id1, pta_trace2(i).id1);
                pta_trace1(n).id2 = min(pta_trace1(n).id2, pta_trace2(i).id2);

                if i>1 &(pta_trace2(i-1).id2 == pta_trace2(i).id1)
                    pta_trace2(i-1).id2 = min(pta_trace1(n).id1, pta_trace2(i).id1);
                end
                if i<length(pta_trace2) & (pta_trace2(i+1).id1 == pta_trace2(i).id2)
                    pta_trace2(i+1).id1 = min(pta_trace1(n).id2, pta_trace2(i).id2);   
                end
                pta_trace2(i).id1 = min(pta_trace1(n).id1, pta_trace2(i).id1);
                pta_trace2(i).id2 = min(pta_trace1(n).id2, pta_trace2(i).id2);
                
                pta_trace2 = FnEmptyPTA(pta_trace2,i);
            end
        end
    end
    
     pta_trace_new = mergeTrans(pta_trace1, pta_trace2);
    
    
end

function pta_trace = FnEmptyPTA(pta_trace, id)
    pta_trace(id).id1 = []; 
    pta_trace(id).guard = []; 
    pta_trace(id).id2 = []; 
    pta_trace(id).label1 = []; 
    pta_trace(id).label2 = []; 
    pta_trace(id).times = []; 
end

function pta_trace= get_pta_trace(n, seg_ids, pta_trace_set)
    startn = seg_ids(n);
    endn = seg_ids(n+1)-1;
    pta_trace = pta_trace_set(startn:endn);
end

% if idj transition has the nid, it should be changed to idi 
function checkflag = checkFeasb(i, j, pta_trace1, pta_trace2)
    checkflag = false;
    if pta_trace1(i).id1 == pta_trace2(j).id1
        flag1 = true;
    else
        if pta_trace1(i).id1 < pta_trace2(j).id1
            pta_tran_temp1 = pta_trace2(j);
            pta_tran_temp1.id1 = pta_trace1(i).id1;
            if (j>1)& (pta_trace2(j-1).id2 == pta_trace2(j).id1)
                pta_tran_temp2 = pta_trace2(j-1);
                pta_tran_temp2.id2 = pta_trace1(i).id1;
            else
                pta_tran_temp2 = [];
            end
        elseif pta_trace1(i).id1 > pta_trace2(j).id1
            pta_tran_temp1 = pta_trace1(i);
            pta_tran_temp1.id1 = pta_trace2(j).id1;
            if (i>1) & (pta_trace1(i-1).id2==pta_trace1(1).id1)
                pta_tran_temp2 = pta_trace1(i-1);
                pta_tran_temp2.id2 = pta_trace2(j).id1;
            else
                pta_tran_temp2 = [];
            end
        end
        
        exitflag1 = validOneTransition(pta_tran_temp1, pta_trace1);
        exitflag2 = validOneTransition(pta_tran_temp1, pta_trace2);
        exitflag3 = validOneTransition(pta_tran_temp2, pta_trace1);
        exitflag4 = validOneTransition(pta_tran_temp2, pta_trace2); 
        flag1 = all([exitflag1,exitflag2,exitflag3,exitflag4]);
    end
    
    if pta_trace1(i).id2 == pta_trace2(j).id2
        flag2 = true;
    else
        if pta_trace1(i).id2 < pta_trace2(j).id2
            pta_tran_temp3 = pta_trace2(j);
            pta_tran_temp3.id2 = pta_trace1(i).id2; 
            if j<length(pta_trace2) & (pta_trace2(j+1).id1==pta_trace2(j).id2)
                pta_tran_temp4 = pta_trace2(j+1);
                pta_tran_temp4.id1 = pta_trace1(i).id2; 
            else
                pta_tran_temp4 = [];
            end
        elseif pta_trace1(i).id2 > pta_trace2(j).id2
            pta_tran_temp3 = pta_trace1(i);
            pta_tran_temp3.id2 = pta_trace2(j).id2;
            if (i<length(pta_trace1)) & (pta_trace1(i+1).id1==pta_trace1(i).id2)
                pta_tran_temp4 = pta_trace1(i+1);
                pta_tran_temp4.id1 = pta_trace2(j).id2;
            else
                pta_tran_temp4 = [];
            end
        end
        exitflag5 = validOneTransition(pta_tran_temp3, pta_trace1);
        exitflag6 = validOneTransition(pta_tran_temp3, pta_trace2);
        exitflag7 = validOneTransition(pta_tran_temp4, pta_trace1);
        exitflag8 = validOneTransition(pta_tran_temp4, pta_trace2);
        flag2 = all([exitflag5,exitflag6,exitflag7,exitflag8]);
    end
 
    if flag1 & flag2
        checkflag = true;
    end
end

function exitflag = validOneTransition(pta_temp, pta_trace)
    exitflag = true;
    if isempty(pta_temp)
        return
    end
    if pta_temp.id1 == pta_temp.id2
        exitflag = false;
        return
    end
    for i = 1:length(pta_trace)
        if (pta_trace(i).id1==pta_temp.id1)&(pta_trace(i).id2==pta_temp.id2)&(pta_trace(i).guard~=pta_temp.guard)
            exitflag = false;
            return 
        end 
        if (pta_trace(i).id1==pta_temp.id1)&(pta_trace(i).label1~=pta_temp.label1)
            exitflag = false;
            return 
        end
        if(pta_trace(i).id2==pta_temp.id2)&(pta_trace(i).label2~=pta_temp.label2)
            exitflag = false;
            return 
        end
    end
end

function pta_trace_new = mergeTrans(pta_trace1, pta_trace2)
    pta_trace_new = [pta_trace1,pta_trace2];
    
    for i = 1:(length(pta_trace_new)-1)
        if isempty(pta_trace_new(i).label1)
            continue
        end
        ilabel1 = pta_trace_new(i).label1;
        iguard = pta_trace_new(i).guard;
        ilabel2 = pta_trace_new(i).label2;
        iid1 = pta_trace_new(i).id1;
        iid2 = pta_trace_new(i).id2;
        for j = (i+1):length(pta_trace_new)
            if isempty(pta_trace_new(j).label1)
                continue
            end
            jlabel1 = pta_trace_new(j).label1;
            jguard = pta_trace_new(j).guard;
            jlabel2 = pta_trace_new(j).label2;
            jid1 = pta_trace_new(j).id1;
            jid2 = pta_trace_new(j).id2;
            
            if (ilabel1==jlabel1)&(iguard==jguard)&(ilabel2==jlabel2)&(iid1==jid1)
                if ~ismember(jid2, [pta_trace_new.id1])
                    pta_trace_new = FnEmptyPTA(pta_trace_new, j);
                    pta_trace_new(i).times = pta_trace_new(i).times+1;
                end
            end
        end
    end
    
    pta_trace_new = clear_empty_trans(pta_trace_new);

end

function pta_trace_new = clear_empty_trans(pta_trace_new)

    id_empty = [];
    for n = 1:length(pta_trace_new)
        if isempty(pta_trace_new(n).label1)||(pta_trace_new(n).guard==0)
            id_empty = [id_empty;n];
        end
        if (pta_trace_new(n).label1 == pta_trace_new(n).label2)
            id_empty = [id_empty;n];
        end
    end
    pta_trace_new(id_empty) = [];
end

function pta_trace = modify_pta(pta_trace)
    for n = 1:(length(pta_trace)-1)
        if isempty(pta_trace(n).id1)
            continue;
        end
        label1 = pta_trace(n).label1;
        guard = pta_trace(n).guard;
        label2 = pta_trace(n).label2;
        for i =(n+1):length(pta_trace)
            ilabel1 = pta_trace(i).label1;
            if isempty(ilabel1)
                continue
            end
            iguard = pta_trace(i).guard;
            ilabel2 = pta_trace(i).label2;
            if (label1==ilabel1)&(guard==iguard)&(label2==ilabel2) & checkFeasb2(n, i, pta_trace)
                pta_trace(n).times = pta_trace(n).times+pta_trace(i).times;
                if pta_trace(i).id2 > pta_trace(n).id2
                    if (i<length(pta_trace))&(~isempty(pta_trace(i+1).id1)) & (pta_trace(i+1).id1==pta_trace(i).id2)
                        pta_trace(i+1).id1 = pta_trace(n).id2;
                    end
                    pta_trace(i).id2 = pta_trace(n).id2;
                else
                    if (n<length(pta_trace))&(~isempty(pta_trace(n+1).id1)) & (pta_trace(n+1).id1==pta_trace(n).id2)
                        pta_trace(n+1).id1 = pta_trace(i).id2;
                    end  
                    pta_trace(n).id2 = pta_trace(i).id2;
                end
                
                if pta_trace(i).id1>pta_trace(n).id1
                    if (i>1)&(~isempty( pta_trace(i-1).id2))&(pta_trace(i-1).id2==pta_trace(i).id1)
                        pta_trace(i-1).id2 = pta_trace(n).id1;
                    end
                    pta_trace(i).id1 = pta_trace(n).id1;
                else
                    nid = pta_trace(n).id1;
                    for j = 1:length(pta_trace)
                        flag = checkFeasb_id(pta_trace(i).id1, j, nid, pta_trace);
                        if flag & pta_trace(j).id1== nid
                            pta_trace(j).id1 = pta_trace(i).id1;
                        elseif flag & pta_trace(j).id2== nid
                            pta_trace(j).id2 = pta_trace(i).id1;
                        end
                    end
                    pta_trace(n).id1 = pta_trace(i).id1;
                end 
                
                pta_trace = FnEmptyPTA(pta_trace,i);
                
%                 if n>1 & (pta_trace(n-1).id2 ==pta_trace(n).id1)
%                     pta_trace(n-1).id2 = min(pta_trace(n).id1, pta_trace(i).id1);
%                 end
%                 if n<length(pta_trace) & (pta_trace(n+1).id1==pta_trace(n).id2)
%                     pta_trace(n+1).id1 = min(pta_trace(n).id2, pta_trace(i).id2);
%                 end
%                 pta_trace(n).id1 = min(pta_trace(n).id1, pta_trace(i).id1);
%                 pta_trace(n).id2 = min(pta_trace(n).id2, pta_trace(i).id2);
% 
%                 if i>1 &(pta_trace(i-1).id2 == pta_trace(i).id1)
%                     pta_trace(i-1).id2 = min(pta_trace(n).id1, pta_trace(i).id1);
%                 end
%                 if i<length(pta_trace) & (pta_trace(i+1).id1 == pta_trace(i).id2)
%                     pta_trace(i+1).id1 = min(pta_trace(n).id2, pta_trace(i).id2);   
%                 end
%                 pta_trace(i).id1 = min(pta_trace(n).id1, pta_trace(i).id1);
%                 pta_trace(i).id2 = min(pta_trace(n).id2, pta_trace(i).id2);
%                 
%                 pta_trace = FnEmptyPTA(pta_trace,i);
            end
        end
    end
    pta_trace = clear_empty_trans(pta_trace);
    pta_trace = mapping_id(pta_trace);
end

function checkflag = checkFeasb2(i, j, pta_trace)
    checkflag = false;
    if pta_trace(i).id1 == pta_trace(j).id1
        flag1 = true;
    else
        if pta_trace(i).id1 < pta_trace(j).id1
            pta_tran_temp1 = pta_trace(j);
            pta_tran_temp1.id1 = pta_trace(i).id1;
            if (j>1)& (pta_trace(j-1).id2 == pta_trace(j).id1)
                pta_tran_temp2 = pta_trace(j-1);
                pta_tran_temp2.id2 = pta_trace(i).id1;
            else
                pta_tran_temp2 = [];
            end
        elseif pta_trace(i).id1 > pta_trace(j).id1
            pta_tran_temp1 = pta_trace(i);
            pta_tran_temp1.id1 = pta_trace(j).id1;
            if (i>1) & (pta_trace(i-1).id2==pta_trace(1).id1)
                pta_tran_temp2 = pta_trace(i-1);
                pta_tran_temp2.id2 = pta_trace(j).id1;
            else
                pta_tran_temp2 = [];
            end
        end
        
        exitflag1 = validOneTransition(pta_tran_temp1, pta_trace);
        exitflag2 = validOneTransition(pta_tran_temp1, pta_trace);
        exitflag3 = validOneTransition(pta_tran_temp2, pta_trace);
        exitflag4 = validOneTransition(pta_tran_temp2, pta_trace); 
        flag1 = all([exitflag1,exitflag2,exitflag3,exitflag4]);
    end
    
    if pta_trace(i).id2 == pta_trace(j).id2
        flag2 = true;
    else
        if pta_trace(i).id2 < pta_trace(j).id2
            pta_tran_temp3 = pta_trace(j);
            pta_tran_temp3.id2 = pta_trace(i).id2; 
            if j<length(pta_trace) & (pta_trace(j+1).id1==pta_trace(j).id2)
                pta_tran_temp4 = pta_trace(j+1);
                pta_tran_temp4.id1 = pta_trace(i).id2; 
            else
                pta_tran_temp4 = [];
            end
        elseif pta_trace(i).id2 > pta_trace(j).id2
            pta_tran_temp3 = pta_trace(i);
            pta_tran_temp3.id2 = pta_trace(j).id2;
            if (i<length(pta_trace)) & (pta_trace(i+1).id1==pta_trace(i).id2)
                pta_tran_temp4 = pta_trace(i+1);
                pta_tran_temp4.id1 = pta_trace(j).id2;
            else
                pta_tran_temp4 = [];
            end
        end
        exitflag5 = validOneTransition(pta_tran_temp3, pta_trace);
        exitflag6 = validOneTransition(pta_tran_temp3, pta_trace);
        exitflag7 = validOneTransition(pta_tran_temp4, pta_trace);
        exitflag8 = validOneTransition(pta_tran_temp4, pta_trace);
        flag2 = all([exitflag5,exitflag6,exitflag7,exitflag8]);
    end
 
    if flag1 & flag2
        checkflag = true;
    end
end

% if idj transition has the nid, it should be changed to idi 
function checkflag = checkFeasb_id(idi, j, nid, pta_trace)
    checkflag = false;
    if nid == 1 
        return;
    end
    pta_temp = pta_trace(j);
    if pta_temp.id1 == nid
        exitflag = [];
        pta_temp.id1 = idi;
        exitflag = validOneTransition(pta_temp, pta_trace);
        if (j-1)>0 & pta_trace(j-1).id2==nid
            pta_temp2 = pta_trace(j-1);
            exitflag = [exitflag,validOneTransition(pta_temp2, pta_trace)];
        end
        if all(exitflag)
            checkflag = true;
            return;
        end
    elseif  pta_temp.id2 == nid
        exitflag = [];
        pta_temp.id2 = idi;
        exitflag = validOneTransition(pta_temp, pta_trace);
        if (j+1)<=length(pta_trace) & pta_trace(j+1).id1==nid
            pta_temp2 = pta_trace(j+1);
            exitflag = [exitflag,validOneTransition(pta_temp2, pta_trace)];
        end
        if all(exitflag)
            checkflag = true;
            return;
        end
    end   
end

function pta_trace = mapping_id(pta_trace)  
    times = [pta_trace.times];
    pta_trace(find(times/mean(times)<=0.1)) = [];
    ids = [];
    for i = 1:length(pta_trace)
        ids(end+1) = pta_trace(i).id1;
        ids(end+1) = pta_trace(i).id2;
    end
    [~,~,ic]= unique(ids);

    num=1;
    for i = 1:length(pta_trace)
        pta_trace(i).id1 = ic(num);
        num = num+1;
        pta_trace(i).id2 = ic(num);
        num = num+1;
    end
end
