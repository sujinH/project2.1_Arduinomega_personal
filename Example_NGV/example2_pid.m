clear all
close all
clc

P1 = tf(3,[1 3 2 0]);
P2 = tf(7,[1 3 2 0]);

KP = 10;
KI = 1;
KD = 1;

Ppid = tf([KD KP KI],[1 0]);

%% unit feedback
G1u = P1/(1+P1);
G1u = feedback(P1,1);

G2u = P2/(1+P2);
G2u = feedback(P2,1);

%% PID
G1 = Ppid*P1/(1+Ppid*P1);
G1 = feedback(Ppid*P1,1);

G2 = Ppid*P2/(1+Ppid*P2);
G2 = feedback(Ppid*P2,1);

figure
subplot(211)
step(G1u)
subplot(212)
step(G1)

figure
subplot(211)
step(G2u)
subplot(212)
step(G2)

