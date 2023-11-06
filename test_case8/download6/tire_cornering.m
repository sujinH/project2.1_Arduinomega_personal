clear all
close all
clc

calpha = 34500;
mu = 0.85;
K = 18;
alpha = (0.1:0.01:10)*pi/180;

Fy1 = calpha*alpha;
Fy2 = calpha*mu/K*atan(K*alpha/mu);

plot(alpha,Fy1)
hold on
plot(alpha,Fy2)