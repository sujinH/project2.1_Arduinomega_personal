function output = global_motion(vx,vy,yaw)
%GLOBAL_MOTIO  �� �Լ��� ��� ���� ��ġ
%   �ڼ��� ���� ��ġ
X_dot = vx*cos(yaw) - vy*sin(yaw);
Y_dot = vx*sin(yaw) + vy*cos(yaw);
output = [X_dot,Y_dot];
end

