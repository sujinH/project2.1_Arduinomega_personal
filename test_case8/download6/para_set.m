clear all
close all
clc

% global m lf lr Cf Cr Izz 
global m lf lr Cf Cr Izz mu K

m = 1765;
Izz = 4828;
lf = 1.4;
lr = 1.7;
Cf = 39500;
Cr = 38500;
mu = 0.85;
K = 18;

vx_ini = 30;
vy_ini = 0;
yawrate_ini = 0;
X_ini = 0;
Y_ini = 0;
yaw_ini = 0;

delta_ref = 10*pi/180;

Tc = 0.01;

%% lonlat
tau = 0.8;
V_ref = 30;
Kp = 1;
Ki = 0.01;
