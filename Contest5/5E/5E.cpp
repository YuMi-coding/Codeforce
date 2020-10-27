#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>

#define USE_ONLINE_JUDGE

int main()
{
    #ifndef USE_ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    while(scanf("%lf%lf%lf%lf%lf",&a,&v,&l,&d,&w)!=EOF)
    {
        double maxAccelTime = v * 1.0 / a;
        double maxAccelDist = 0.5 * v * v / a;
        double ans = 0.0;
        #ifndef USE_ONLINE_JUDGE
            printf("maxAccelTime = %f, maxAccelDist = %f\n",maxAccelTime,maxAccelDist);
        #endif
        if(maxAccelDist > d)// Does not accelerate to top speed when reach the speed sign
        {
no_time_to_decel:
            double timeReachSign = sqrt(double(2.0 * d)/a);
            double speedReachSign = sqrt(double(2.0 * a * d));
            #ifndef USE_ONLINE_JUDGE
                printf("timeReachSign=%f,speedReachSign=%f\n",timeReachSign,speedReachSign);
            #endif
            if(speedReachSign < w) //Does not need to decelerate
            {
                if(l < maxAccelDist){ // No enough space for accelerating
                    ans = sqrt(double(2.0*l)/a);
                }
                else{
                    ans = maxAccelTime + (l - maxAccelDist)/double(v);
                }
            }
            else // Need to decelerate
            {
                double speedDifference = speedReachSign - w;
                double timeDecreaseSpeed = speedDifference / double(2 * a);
                #ifndef USE_ONLINE_JUDGE
                    printf("speedDifferene = %f,timeDecreaseSpeed = %f\n",speedDifference,timeDecreaseSpeed);
                #endif
                double timeAccel = sqrt((2*a*d+w*w)/(2*a*a));
                #ifndef USE_ONLINE_JUDGE
                    printf("timeAccel = %f\n",timeAccel);
                #endif
                double ansFirst = timeAccel + (timeAccel*a-w)/a;

                double ansSecond = 0; // To be filled in following
                double distanceRemain = l - d;
                double toTopSpeedDistance = (double(w) + double(v))/2 * (double(v) - double(w))/a;
                if(toTopSpeedDistance < distanceRemain)
                {// We can achieve top speed in the remaining distance
                    ansSecond = (distanceRemain-toTopSpeedDistance)/double(v) + (double(v) - double(w))/a;
                }
                else
                {// We cannot achieve top speed in the remaining distance
                    ansSecond = (sqrt(4.0 * double(w) * double(w) + 8 * a * distanceRemain) - 2.0*double(w))/(2*a);
                }
                #ifndef USE_ONLINE_JUDGE
                    printf("ansFirst = %f, ansSecond = %f\n", ansFirst, ansSecond);
                #endif
                ans = ansFirst + ansSecond;
            }
        }
        else // Accelerates to top speed when reach speed sign
        {
            if(v < w)
            {
                #ifndef USE_ONLINE_JUDGE
                    printf("v < w\n");
                #endif
                ans = (l - maxAccelDist) / v + maxAccelTime;
            }
            else
            {
                #ifndef USE_ONLINE_JUDGE
                    printf("v > w\n");
                #endif
                double speedDifference = v - w;
                double timeDecreaseSpeed = speedDifference / double(a);
                double distanceDecrease = v * timeDecreaseSpeed - 0.5 * a * timeDecreaseSpeed * timeDecreaseSpeed;
                double distanceNoChangeSpeed = d - maxAccelDist - distanceDecrease;
                #ifndef USE_ONLINE_JUDGE
                    printf("distanceDecrease = %f, distanceNoChangeSpeed = %f\n", distanceDecrease, distanceNoChangeSpeed);
                #endif

                if(distanceNoChangeSpeed < 0){// No enough space for decelerating
                    goto no_time_to_decel;
                }
                else{
                    ans = maxAccelTime + distanceNoChangeSpeed/v + timeDecreaseSpeed + timeDecreaseSpeed + (l-d-distanceDecrease)/v;
                }
            }
        }

        printf("%.6f\n",ans);
    }
    return 0;
}