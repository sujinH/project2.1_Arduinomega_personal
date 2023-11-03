%caution : ctrl_freq ,< 10000
clear
Ctrl_freq = 5000;
PWM_freq = 50;
Tc = 1/Ctrl_freq;
n_step = Ctrl_freq/PWM_freq;
width_step = n_step/2;
