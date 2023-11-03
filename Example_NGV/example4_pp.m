clear all
close all
clc

X_ini = [10; 10];

p = [-1 -5];
A=[0 1;2 3];
B=[0;2];
C= [1 0];
D = 0;
K = acker(A,B,p);
eig(A-B*K)