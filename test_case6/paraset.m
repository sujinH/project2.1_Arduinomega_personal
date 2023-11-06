clear all
close all
clc

R = 2.0;
L = 0.5;
Km = 0.1;
Kb = 0.1;
Kf = 0.2;
J = 0.02;

Kp = 5;
Ki = 0.01;

% h1 = tf(Km, [L,R]);
% h2 = tf(1, [J,Kf]);
% 
% dcm = ss(h2) * [h1,1];
% dcm = feedback(dcm,Kb,1,1);
% 
% step(dcm);