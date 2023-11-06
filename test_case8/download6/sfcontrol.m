close all
clear all
% Longitudinal vehicle speed (m/s)
Vx=30;
% Determination of feedback gain via pole placement
[A,B,C,D] = lat_dyn(Vx);
% Eignevalues of A-B1K
P = [-5-3*j -5+3*j -7 -10];
% Feedback matrix K such that the eigenvalues of the matrix
% A-B1K are at the desired locations specified in the vector P

%% pole place
% K = place(A,B(:,1),P);

%% LQR
Q = diag([1,1,1,1]);
R = diag(1);
[X,L,K] = care(A,B(:,1),Q,R);
% Closed-loop system with the state feedback controller
Ac = A-B(:,1)*K;
Bc = B(:,2);
Cc = eye(4);
Dc = 0;
sys = ss(Ac,Bc,Cc,Dc);
t = 0:0.01:20;
R = 1000;
% Define Desired yaw rate as a step input
T = floor(length(t)/20);
u = [zeros(1,T) (Vx/R)*ones(1,length(t)-T)]';
[y,t,x] = lsim(sys,u,t);

figure(101)
% set(gcf,'numbertitle','off','name','Results')
subplot(221)
plot(t,x(:,1),'linewidth',2)
grid on;hold on;
xlabel('Time [sec]')
ylabel('e_1 [m]')
xlim([0 20])
subplot(222)
plot(t,x(:,2),'linewidth',2)
grid on;hold on;
xlabel('Time [sec]')
ylabel('e_1/dt [m/sec]')
xlim([0 20])
subplot(223)
plot(t,x(:,3)*180/pi,'linewidth',2)
grid on;hold on;
xlabel('Time [sec]')
ylabel('e_2 [deg]')
xlim([0 20])
subplot(224)
plot(t,x(:,4)*180/pi,'linewidth',2)
grid on;hold on;
xlabel('Time [sec]')
ylabel('e_2/dt [deg/sec]')
xlim([0 20])
