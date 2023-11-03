function z = test_cal(u1,u2)
%  y1 = u1+u2
%  y2 = u1 - u2
% y1가 y2의 값을

y1 = u1 + u2;
y2 = u1 - u2;


    if y1 > 1
        z1 = 1;
    else
        z1 = 0;
    end
    
    if y2 < -1
        z2 = -1;
    else
        z2 = 0;
    end

    z = [z1;z2];
end

