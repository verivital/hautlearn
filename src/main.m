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

var = {'il';'vc'; };%Removed  ;
extraVar = {'rci1'; 'rcv1'; 'rci2'; 'rcv2'; 'rb1'; 'roi1'; 'rov1'; 'roi2'; 'rov2'; 'rdv2'};
numVar = length(var);

% add invariants and flows in an order of locations that are charging,
% discharging, discontinuous, respectively
invariant = {
%                [' il > 0 & vc >= 0-bounds & vc <= Vref+Vtol ',...
%                '& rci1 >=', num2str(rci1_lb), ' & rci1 <=', num2str(rci1_ub),' & rcv1 >=', num2str(rcv1_lb), ' & rcv1 <=', num2str(rcv1_ub),...
%                '& rb1 >=', num2str(rb1_lb), ' & rb1 <=', num2str(rb1_ub), ' & rci2 >=', num2str(rci2_lb), ' & rci2 <=', num2str(rci2_ub), ' & rcv2 >=', num2str(rcv2_lb), ' & rcv2 <=', num2str(rcv2_ub)];
%                [' vc >= Vref-Vtol & vc <= bounds & il > 0 ',...
%                '& roi1 >=', num2str(roi1_lb), ' & roi1 <=', num2str(roi1_ub),' & rov1 >=', num2str(rov1_lb), ' & rov1 <=', num2str(rov1_ub),...
%                '& roi2 >=', num2str(roi2_lb), ' & roi2 <=', num2str(roi2_ub), ' & rov2 >=', num2str(rov2_lb), ' & rov2 <=', num2str(rov2_ub)];
%                ['vc >= Vref-Vtol & vc <= bounds & il <= 0 & rdv2 >=', num2str(rdv2_lb), ' & rdv2 <=', num2str(rdv2_ub)];  
            };       

flow  = {
%            'il = (a00c * il + rci1) + (a01c * vc + rcv1) + (b0c * Vs + rb1) & vc = (a10c * il + rci2) + (a11c * vc + rcv2) + (b1c * Vs)';
%            'il = (a00o * il + roi1) + (a01o * vc + rov1) + b0o * Vs & vc = (a10o * il + roi2) + (a11o * vc + rov2) + b1o * Vs';
%            'il = 0 & vc = (a11o * vc + rdv2) + b1o * Vs';   
        };

% add variables to ha
for i_var = 1:numVar
    ha.variables.add(java.lang.String(var(i_var)));
end

locName ={%'charging','discharging','discontinuous'
};

numLoc = length(locName);

for i_loc = 1:numLoc
    loc = ha.createMode(locName(i_loc),invariant(i_loc),flow(i_loc));
    locations(i_loc) = loc;
end

fromLocation = {
%locations(1);locations(2);locations(2);locations(3)
};
toLocation = {
%locations(2);locations(1);locations(3);locations(1)
};

% add guards and resets in an order of transitions
guard = {%'vc >= Vref+Vtol';'vc >= Vref-Vtol';'il <= 0';'vc >= Vref-Vtol'
        };
reset = {%'vc=vc & il=il';'vc=vc & il=il';
         %'vc=vc & il=il';'vc=vc & il=il'
         };

numTran = length(fromLocation);
for i_tran = 1:numTran
    tran = ha.createTransition(fromLocation{i_tran}, toLocation{i_tran});
    tran.guard = com.verivital.hyst.grammar.formula.FormulaParser.parseGuard(guard(i_tran));
    
    if (~isempty(reset(i_tran)))
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

for i_var = 1:length(extraVar)
    ha.variables.add(java.lang.String(extraVar(i_var)));
end

% add initial condition 
initalLoc = '';
initialExpression = '';%'il == 0 & vc == 0 & rci1==0 & rcv1==0 & rci2==0 & rcv2==0 & rb1==0 & roi1==0 & rov1==0 & roi2==0 & rov2==0 & rdv2==0 & a00o == -1.963e+02 & a01o == -3.775e+02 & a10o == 4.547e+02 & a11o == -45.51 & a00c == -2.718e+02 & a01c == -3.775e+02 & a10c == 4.547e+02 & a11c == -45.51 & bounds == 100 & T == 2.0e-05 & b0o == 0 & b1o == 0 & b0c == 3.775e+02 & b1c == 0 & Vs == 24 & tmax == 0.02 & Vtol == 0.1 & Vref == 12';

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