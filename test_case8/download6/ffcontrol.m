clear all

m = 1573; Iz = 2873;
lf = 1.1; lr = 1.58;
Cf = 80000; Cr = 80000;
L = (lf+lr);
R = 1000;
Vx=30;
% Determination of feedback gain via pole placement
[A,B,C,D] = lat_dyn(Vx);
% Eignevalues of A-B1K
P = [-5-3*j -5+3*j -7 -10];
% P = [-5-3*j -5+3*j -7 -10];
% Feedback matrix K such that the eigenvalues of the matrix
% A-B1K are at the desired locations specified in the vector P
K = place(A,B(:,1),P);



% Calculation of feedforward steering angle
ay = Vx^2/R;
Kv = lr*m/(2*Cf*L)-lf*m/(2*Cr*L);
delta_ff = L/R+Kv*ay-K(3)*(lr/R-lf/(2*Cr)*m*ay/L);
% Steady State Errors
e1ss = (-(1/K(1))*(m*Vx^2)/(R*L)*(lr/(2*Cf)-lf/(2*Cr)+lf/(2*Cr)*K(3))-(1/(K(1)*R))*(L-lr*K(3)))*100
e2ss = (1/(2*R*Cr*L)*(-2*Cr*lf*lr-2*Cr*lr^2+lf*m*Vx^2))*180/pi
Ac = A-B(:,1)* K;
Bc = B;
Cc = eye(4);
Dc = 0;
sys = ss(Ac,Bc,Cc,Dc);
t = 0:0.01:20;
% Define Input vector, u
T = floor(length(t)/20);
u = [zeros(1,T) delta_ff*ones(1,length(t)-T);
zeros(1,T) (Vx/R)*ones(1,length(t)-T)]';
[y,t,x] = lsim(sys,u,t);




figure(101)
set(gcf,'numbertitle','off','name','Results')
subplot(2,2,1)
plot(t,x(:,1),'r--','linewidth',2)
grid on
xlabel('Time [sec]')
ylabel('e_1 [cm]')
xlim([0 20])
subplot(2,2,2)
plot(t,x(:,2),'r--','linewidth',2)
grid on
xlabel('Time [sec]')
ylabel('de_1/dt [cm/sec]')
xlim([0 20])
set(legend('SF','SF+FF'),'fontsize', 10,'fontweight','bold');
subplot(2,2,3)
plot(t,x(:,3)*180/pi,'r--','linewidth',2)
grid on
xlabel('Time [sec]')
ylabel('e_2 [deg]')
xlim([0 20])
subplot(2,2,4)
plot(t,x(:,4)*180/pi,'r--','linewidth',2)
grid on
xlabel('Time [sec]')
ylabel('de_2/dt [deg/sec]')
xlim([0 20])