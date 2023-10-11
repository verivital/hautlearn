function [dx]=buck_cora_St1_FlowEq(x,u)

dx(1,1) = 3.8276105503507218408287826605374*x(1)*x(2) - 378.13736089322276257007615640759*x(2) - 2.3388397690791129512888346653199*x(1)^2.0 - 0.23033632526291766828840934522304*x(2)^2.0 - 269.92269695693909170586266554892*x(1) + 9043.472189641088;

dx(2,1) = 462.25607882021347450063331052661*x(1) - 27.273262040947063411522321985103*x(2) + 0.88541193964760234180744191689882*x(1)^2.0 - 1.0484905973404579082597365413676*x(2)^2.0 - 4.2869188126325425969298521522433*x(1)*x(2) - 32.133729229638845;
