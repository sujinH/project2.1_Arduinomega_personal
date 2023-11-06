function output = global_motion(vx,vy,yaw)
%GLOBAL_MOTIO  이 함수의 요약 설명 위치
%   자세한 설명 위치
X_dot = vx*cos(yaw) - vy*sin(yaw);
Y_dot = vx*sin(yaw) + vy*cos(yaw);
output = [X_dot,Y_dot];
end

