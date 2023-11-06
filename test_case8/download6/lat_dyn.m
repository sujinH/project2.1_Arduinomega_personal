function [A,B,C,D] = lat_dyn(V)
% V - longitudinal velocity (m/s)

m = 1573;
Iz = 2873;
lf = 1.1;
lr = 1.58;
Cf = 80000;
Cr = 80000;
Vx = V;
I_psi = Iz;
a22 = -(2*Cf+2*Cr)/(m*Vx);
a23 = 2*(Cf+Cr)/m;
a24 = - (2*Cf*lf - 2*Cr*lr)/(m*Vx);
a42 = -(2*lf*Cf-2*lr*Cr)/(I_psi*Vx);
a43 = 2*(lf*Cf-lr*Cr)/I_psi;
a44 = -(2*lf*lf*Cf+2*lr*lr*Cr)/(I_psi*Vx);
b21 = 2*Cf/m;
b41 = 2*lf*Cf/I_psi;
b22 = -Vx -2*(lf*Cf-lr*Cr)/(m*Vx);
b42 = -2*(lf*lf*Cf+lr*lr*Cr)/(I_psi*Vx);

A_lat = [0 1 0 0;
0 a22 a23 a24;
0 0 0 1;
0 a42 a43 a44;];

B1_lat = [0 b21 0 b41]'; % Steering angle input

B2_lat = [0 b22 0 b42]'; % psi_des_dot input

C_lat = eye(4);
D1_lat = zeros(4,1);
D2_lat = zeros(4,1);
A = A_lat;
B = [B1_lat B2_lat];
C = C_lat;
D = [D1_lat D2_lat];