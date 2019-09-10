#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>

// #define USE_ONLINE_JUDGE
double a,v,l,w,d;

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
            printf("%f %f\n",maxAccelTime,maxAccelDist);
        #endif
        if(maxAccelDist > d)// Does not accelerate to top speed when reach the speed sign
        {
            double timeReachSign = sqrt(double(2.0 * d)/a);
            double speedReachSign = sqrt(double(2.0 * a * d));
            #ifndef USE_ONLINE_JUDGE
                printf("timeReachSign=%f,speedReachSign=%f\n",timeReachSign,speedReachSign);
            #endif
            if(speedReachSign < w) //Does not need to decelerate
            {
                ans = maxAccelTime + (l - maxAccelDist)/double(v);
            }
            else // Need to decelerate
            {
                double speedDifference = speedReachSign - w;
                double timeDecreaseSpeed = speedDifference / double(2 * a);
                #ifndef USE_ONLINE_JUDGE
                    printf("speedDifferene = %f,timeDecreaseSpeed = %f\n",speedDifference,timeDecreaseSpeed);
                #endif
                double ansFirst = double(w) / double(a) + 2 * timeDecreaseSpeed;
                double ansSecond = (sqrt(4.0 * (w) * (w) + 8 * a * (l - d)) - 2.0*w)/(2*a);
                ans = ansFirst + ansSecond;
            }
        }
        else // Accelerates to top speed when reach speed sign
        {
            if(v < w)
            {
                ans = (l - maxAccelDist) / v + maxAccelTime;
            }
            else
            {
                double speedDifference = v - w;
                double timeDecreaseSpeed = speedDifference / double(2 * a);
                double distanceDecrease = v * timeDecreaseSpeed - 0.5 * a * timeDecreaseSpeed * timeDecreaseSpeed;
                double distanceNoChangeSpeed = d - maxAccelDist - distanceDecrease;

                ans = maxAccelTime + distanceNoChangeSpeed/v + timeDecreaseSpeed + timeDecreaseSpeed + (l-d-distanceDecrease)/v;
            }
        }

        printf("%.6f\n",ans);
    }
    return 0;
}