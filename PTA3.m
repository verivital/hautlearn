

tran_n_event = [trans(:,1:2), zeros(length(trans),1)];
% 3 -> 2 event1
idx = LI(1).inlayer(1);
idx = cell2mat(idx);
tran_n_event(idx, 3) = 1;

% 3->2 event6
idx = LI(1).inlayer(2);
idx = cell2mat(idx);
tran_n_event(idx, 3) = 6;

% 2->1 event5
idx = LI(2).inlayer;
idx = cell2mat(idx);
tran_n_event(idx, 3) = 5;

% 1->0 event1
idx = LI(3).inlayer;
idx = cell2mat(idx);
tran_n_event(idx, 3) = 1;

% 3->1 event5
idx = LI(4).inlayer(1);
idx = cell2mat(idx);
tran_n_event(idx, 3) = 5;

% 3->1 event8
idx = LI(4).inlayer(2);
idx = cell2mat(idx);
tran_n_event(idx, 3) = 8;

% 1->2 event1
idx = LI(5).inlayer;
idx = cell2mat(idx);
tran_n_event(idx, 3) = 1;

% 2->0 event5
idx = LI(6).inlayer;
idx = cell2mat(idx);
tran_n_event(idx, 3) = 5;


t = 1;
for i = 1:length(trace)
    brench(i).trans = [trace(i).labels, 0];
    events = [];
    for j = 1:length(trace(i).chpoints)-1
        events = [events, tran_n_event(t,3)];
        t = t+1;
    end
    brench(i).events = events;
end