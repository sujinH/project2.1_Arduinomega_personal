function output = vehicle_motion_nonlinear(vx,vy,yawrate,delta)
%VEHICLE_MOTION 이 함수의 요약 설명 위치
%   자세한 설명 위치

% global lf lr m Cf Cr Izz 
global lf lr m Cf Cr Izz mu K 

alpha_f = atan2(vy + lf*yawrate,vx) - delta;
alpha_r = atan2(vy - lr*yawrate,vx);

% %% linear
% Fyf = -2*Cf * alpha_f;
% Fyr = -2*Cr * alpha_r;

%% nonlinear
Fyf = -2*Cf*mu/K*atan(K*alpha_f/mu);
Fyr = -2*Cr*mu/K*atan(K*alpha_r/mu);


vx_dot = 0;
vy_dot = 1/m*(Fyf+Fyr)-vx*yawrate;
yawrate_dot = 1/Izz*(lf*Fyf-lr*Fyr);

output = [vx_dot,vy_dot,yawrate_dot];
end

