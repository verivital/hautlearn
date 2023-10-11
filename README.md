# Automata-Learning
This framework contains functions as follows:
- FnClusterSegs: clusters trace segments
- FnEstODE: estimates ordinary differential equations from the clustered trace segments
- FnLI: estimates linear inequalities for changepoints in the traces
- FnPTA: generates state transitions with guard conditions
- FnGenerateHyst: generates a hybrid automation in Hyst data structure
- FnHyst2State: converts Hyst data structure to Stateflow data structure

# Run examples
Run the main function in each example to generate the "automata_learning.mdl" which will be in the "output_slsf_models" folder

# Requirements
control_toolbox
map_toolbox
matlab
simulink
stateflow
symbolic_toolbox