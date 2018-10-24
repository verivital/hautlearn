function FnHyst2State(xml_file)
currentFolder = pwd;
addpath('..\..\src\hyst\src\matlab')
SpaceExToStateflow([currentFolder,'\',xml_file]);
end
