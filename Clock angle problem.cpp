#include<iostream>
#include <stdlib.h>
using namespace std;

int calcAngle(double h, double m)
{
    if (h <0 || m < 0 || h >12 || m > 60)
        cout<<"Wrong Input";

    if (h == 12) h = 0;
    if (m == 60) {m = 0,h++;}
    int hour_angle = 0.5 * (h*60 + m);
    int minute_angle = 6*m;
    int angle = abs(hour_angle - minute_angle);
    angle = min(360-angle, angle);
    return angle;
}
int main()
{
    cout<<calcAngle(9,60);
}
