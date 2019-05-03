# hautlearn
This framework contains functions as follows:\
FnClusterSegs(): clusters trace segments\
FnEstODE(): estimates ordinary differential equations from the clustered trace segments\
FnLI(): estimates linear inequalities for changepoints in the traces\
FnPTA(): generates state transitions with guard conditions\
FnGenerateHyst(): generates a hybrid automation in Hyst data structure\
The Hyst data structure is converted to a Stateflow data structure by calling SpaceExToStateflow() from the hyst package

The entire process can be run by calling FnMain()

Run ```git submodule update --init --recursive``` to pull hyst
