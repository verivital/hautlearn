function FnHyst2State(xml_file)
currentFolder = pwd;
addpath(['..', filesep, '..', filesep, 'src', filesep, 'hyst', filesep, 'src', filesep, 'matlab'])
SpaceExToStateflow([currentFolder, filesep, xml_file]);
end
