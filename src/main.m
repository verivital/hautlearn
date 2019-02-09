%clear all;

% import data structures from Hyst
javaaddpath(['hyst', filesep, 'lib', filesep, 'Hyst.jar']);
import de.uni_freiburg.informatik.swt.spaceexboogieprinter.*;
import com.verivital.hyst.automaton.*;
import com.verivital.hyst.grammar.antlr.*;
import com.verivital.hyst.grammar.formula.*;
import com.verivital.hyst.importer.*;
import com.verivital.hyst.ir.*;
import com.verivital.hyst.junit.*;
import com.verivital.hyst.util.*;
import com.verivital.hyst.main.*;
import com.verivital.hyst.passes.*;
import com.verivital.hyst.printers.*;
import com.verivital.hyst.simulation.*;
import de.uni_freiburg.informatik.swt.sxhybridautomaton.*;
import de.uni_freiburg.informatik.swt.spaceexxmlprinter.*;
import de.uni_freiburg.informatik.swt.spaxeexxmlreader.*;


% create an empty hybrid automaton    
ha = com.verivital.hyst.ir.base.BaseComponent;

opt_learn = 0;
Ts = 0.1;
num_var = 4; num_ud = 0;
Ts = 0.1
if opt_learn
    addpath(['..', filesep, 'example', filesep, 'navigation', filesep]);
    addpath(['..', filesep, 'example', filesep, 'navigation', filesep, 'trainingdata1.1']);
    addpath(['.', filesep]);
    x = []; ud = []; 
    num =1;
    global lambda num_var num_ud Ts
    lambda = 0.000001;  
    num_var = 4; num_ud = 0;
    for i = 1:5
        load(['test', int2str(i),'.mat']);

        trace_temp = FnProcessData(xout, num_var, num_ud);
        chpoints = trace_temp.chpoints;
        if min(diff(chpoints))>=10
            trace(num) = trace_temp;
            x = [x; trace(num).x];
            ud = [ud; trace(num).ud];
            num = num+1; 
        end
    end

    trace = FnClusterSegs(trace, x, ud);
    for n =1:length(trace)
        trace(n).labels_trace = [trace(n).labels_trace;0];
    end
    %%
end
ode = FnEstODE(trace);

iter = 1000; % number of iterations 
threshDist = 0.01; % tolerance 
inNum = 5; %the least number of inlayers
[trace,label_guard] = FnLI(trace, iter, threshDist, inNum);
pta_trace = FnPTA(trace);


varNames = {};
for i = 1 : num_var
    varNames{i} = ['x', num2str(i)];
end

for i = 1 : length(ode)
    modesToFlows{i} = odeMatrixToString(ode{i}, varNames);
end

%for the terminal state "0"
ode0 =zeros(size(ode{1}));
modesToFlows{length(ode)+1} = odeMatrixToString(ode{i}, varNames);

numVar = length(varNames);

% add variables to ha
for i_var = 1:numVar
    ha.variables.add(java.lang.String(varNames(i_var)));
end

ids = [pta_trace(:).id1,pta_trace(:).id2];
labels = [pta_trace(:).label1,pta_trace(:).label2];
[uniq_ids, ia, ic] = unique(ids);
id2lables = labels(ia);

numLoc = length(uniq_ids);

for i_loc = 1:numLoc
    locName{i_loc} = java.lang.String(strcat('loc', num2str(i_loc)));
    invariant{i_loc} = java.lang.String('');
    if id2lables(i_loc)==0 
        flow{i_loc} = modesToFlows{length(ode)+1};
    else
        flow{i_loc} = modesToFlows{id2lables(i_loc)};
    end
    class(flow{i_loc})
    loc = ha.createMode(locName{i_loc},invariant{i_loc},flow{i_loc});
    locations(i_loc) = loc;
end

% for i_loc = 1:numLoc
%     %ati = com.verivital.hyst.importer.SpaceExImporter;
%     loc = ha.createMode(locName(i_loc),invariant(i_loc),flow(i_loc));
%     locations(i_loc) = loc;
% end

fromLocation = {};
toLocation= {};
fromId = [pta_trace(:).id1];
toId = [pta_trace(:).id2];
for i=1:length(pta_trace)
    fromLocation{end+1} = locations(fromId(i));
    toLocation{end+1} = locations(toId(i));
end
% fromLocation = {
% %locations(1);locations(2);locations(2);locations(3)
% };

% toLocation = {
% %locations(2);locations(1);locations(3);locations(1)
% };

% add guards and resets in an order of transitions
for i = 1 : length(pta_trace)
    li_id = pta_trace(i).guard;
    v = label_guard{li_id};
    guard{i} = guardVectorToString(v, varNames);
end
% guard = {%'vc >= Vref+Vtol';'vc >= Vref-Vtol';'il <= 0';'vc >= Vref-Vtol'
%         };
reset = {%'vc=vc & il=il';'vc=vc & il=il';
         %'vc=vc & il=il';'vc=vc & il=il'
         };

numTran = length(fromLocation);
for i_tran = 1:numTran
    tran = ha.createTransition(fromLocation{i_tran}, toLocation{i_tran});
    tran.guard = com.verivital.hyst.grammar.formula.FormulaParser.parseGuard(guard{i_tran});
    
    %if (~isempty(reset(i_tran)))
    if (~isempty(reset))
    rstTmp = strsplit(char(reset(i_tran)),'&');
        for i_rst = 1: length(rstTmp)
            rstTmp_token = strsplit(char(rstTmp(i_rst)),'=');
            rstTmp_token_two = com.verivital.hyst.grammar.formula.Variable(char(rstTmp_token(2)));
            tran.reset.put(java.lang.String(rstTmp_token(1)),com.verivital.hyst.ir.base.ExpressionInterval(rstTmp_token_two));
        end
    end
end

% add a list of constants and their values
constantList = {
%'a00o'; 'a01o'; 'a10o'; 'a11o'; 'a00c'; 'a01c'; 'a10c'; 'a11c'; 'bounds'; 'T'; 'b0o'; 'b1o'; 'b0c'; 'b1c'; 'Vs'; 'tmax'; 'Vtol'; 'Vref';
};
constantValue = [
%-1.963e+02; -3.775e+02; 4.547e+02; -45.51; -2.718e+02; -3.775e+02; 4.547e+02; -45.51; 100; 2.0e-05; 0; 0; 3.775e+02; 0; 24; 0.02; 0.1; 12
];

if length(constantList) == length(constantValue)
    try
        for i_const = 1:length(constantList) 
            ha.constants.put(java.lang.String(constantList(i_const)),constantValue(i_const));
        end
    catch
    end
end

% add initial condition 
initalLoc = 'loc1'; % todo: check naming, first location in fromLocation is initial

initialExpression = 'loc(automata_learning) == loc1';
for i = 1 : length(varNames)
    initialExpression = strcat(initialExpression, ' & ', varNames{i}, ' == 0'); % todo: pick a reasonable initial condition
end
    
%generate configuration
config = com.verivital.hyst.ir.Configuration(ha);
config.init.put(initalLoc,com.verivital.hyst.grammar.formula.FormulaParser.parseInitialForbidden(initialExpression));

configValues = de.uni_freiburg.informatik.swt.sxhybridautomaton.SpaceExConfigValues;
configValues.scenario = 'supp';
configValues.outputFormat = 'GEN';

vars = ha.variables.toArray();
if numVar > 1
      jsa = javaArray('java.lang.String', numVar);
    for i = 1: ha.variables.size()
          jsa(i) = java.lang.String(vars(i));
    end 
end

file_name ='automata_learning'; % todo: suffix example name
config.settings.plotVariableNames = jsa;
config.settings.spaceExConfig = configValues;
printer = com.verivital.hyst.printers.SpaceExPrinter;
printer.setBaseName(file_name);
printer.setConfig(config);
printer.setBaseComponent(ha);
config.DO_VALIDATION = false;
doc = printer.convert(ha);

% Save the SpaceEx document and the configuration file 
xml_printer = de.uni_freiburg.informatik.swt.spaceexxmlprinter.SpaceExXMLPrinter(doc);
fileID = fopen([file_name,'.cfg'],'w');
fprintf(fileID,char(xml_printer.getCFGString(1)));
fclose(fileID);

fileID = fopen([file_name,'.xml'],'w');
fprintf(fileID,char(xml_printer.stringXML()));
fclose(fileID);

cd(['hyst', filesep, 'src', filesep, 'matlab']);
try
    SpaceExToStateflow(['..', filesep, '..', filesep, '..', filesep, 'automata_learning.xml']);
catch
end
cd(['..', filesep, '..', filesep, '..']);