%Neil Ashtekar
%Program to graph Mohr's circle given sigma_x, sigma_x, tau_xy

% Purpose: plot ALL THREE mohr's circles, find max-in plane shear, absolute max shear stress
% Inputs: sigma_x, sigma_x, tau_xy  =>  sx, sy, txy
% Processing:
% DRAWING CIRCLES
% - ask for inputs
% - find center: average sigmas
% - find radius: distance between two points
%     - two points: (sx, txy), (sy, -txy)
%     - r = sqrt((sx - sy)^2 + (2*txy)^2)/2
% - find distance between max x value and origin
%     - use this as diameter for next circle
%     - divide this distance by 2 to get radius
%     - graph a circle with this radius, centered at ((max x)/2 , 0)
%     - repeat this process: once for (center + radius), once for
%     (center-radius)
% 
% CALCULATIONS 
% - absolute max shear stress: maximum y value or largest circle (same as
% radius of largest circle
%     - must be greatest y value of ALL circles: use if statements to confirm 
% - max in-plane shear stress: max y value of the FIRST CIRCLE drawn (in
% the same plane as the two data points given and initially graphed)

% FIRST CIRCLE
sx = input('\nEnter the value of stress in the x-direction: \n');

sy = input('\nEnter the value of stress in the y-direction: \n');

txy = input('\nEnter the value of the shear stress: \n');

xc = (sx + sy)/2; %center on x-axis

r = sqrt((sx - sy)^2 + (2*txy)^2)/2; %dist formula between the two pts 

angle = 0:.001:2*pi; %angles for full circle 

x = r*cos(angle); %radius times sin or cos of angle gives circle graph
y = r*sin(angle);

plot(xc+x, y); %plot coordinates: add center pt to x
hold on

            % xaxisline = 0;
            % plot(axisline);
            % hold on

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%SECOND CIRCLE

xc2 = (xc+r) / 2;
r2 = abs(xc2);

x2 = r2*cos(angle);
y2 = r2*sin(angle);

plot(xc2+x2, y2);
hold on

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%THIRD CIRCLE

xc3 = (xc-r) / 2;
r3 = abs(xc3);

x3 = r3*cos(angle);
y3 = r3*sin(angle);

plot(xc3+x3, y3);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%TO FIND MAX ABSOLUTE SHEAR STRESS, MAX IN-PLANE SHEAR STRESS

t1 = max(abs(y));
t2 = max(abs(y2));
t3 = max(abs(y3));

%to find ABSOLUTE MAX shear stress: tmax
if t1 >= t2 && t1 >= t3
    tmax = t1;
end

if t2 >= t1 && t2 >= t3
    tmax = t2;
end

if t3 >= t2 && t3 >= t1
    tmax = t3;
end

iptmax = t1; %max IN-PLANE shear stress: iptmax 

fprintf('\nThe maximum in-plane shear stress is %1.2f and the absolute max shear stress is %1.2f. \n', iptmax, tmax)
