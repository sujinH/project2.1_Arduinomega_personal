clear all
close all
clc


tau1 = 0.8;
tau2 = 0.2;

A1 = [0 1;0 -1/tau1];
B1 = [0;1/tau1];
C1 = [1 0];
D1 = 0;

A2 = [0 1;0 -1/tau2];
B2 = [0;1/tau2];
C2 = [1 0];
D2 = 0;

TF1=ss(A1,B1,C1,D1);
TF2=ss(A2,B2,C2,D2);

t=0:0.1:6;

figure
subplot(211)
impulse(TF1,t)

subplot(212)
impulse(TF2,t)
