clear all
close all
clc

P = tf(5,[1 10]);
KD = 0.1;
KP = 300;
KI = 1;
Ppid = tf([KD KP KI],[1 0]);

G = Ppid*P/(1+Ppid*P);
G1 = feedback(Ppid*P,1);
zero(G1)
pole(G1)

step(P)

figure
step(G1)