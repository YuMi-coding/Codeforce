#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXN 10
//#define INPUT_REDIRECTION
#define EPS 10e-5

struct Circle
{
	double x,y,r;
}c[MAXN];

double ang[3];
const int dy[4]={-1,0,0,1};
const int dx[4]={0,-1,1,0};

double square(double x)
{
	return x*x;
}

double dist(double x,double y,double xx,double yy)
{
	return sqrt(square(x-xx)+square(y-yy));
}

double eval(double x,double y)
{
	for(int i=0;i<3;++i)
        ang[i] = dist(x,y,c[i].x,c[i].y)/c[i].r;
	double val = 0;
	for(int i=0;i<3;++i)
        val += square(ang[i]-ang[(i+1)%3]);
	return val;
}

int main()
{
#ifdef INPUT_REDIRECTION
	freopen("in.in","r",stdin);
#endif
	double x = 0,y = 0;
	for(int i = 0;i < 3;++i)
	{
		scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
		x += c[i].x / 3;
        y += c[i].y / 3;
	}

	double err  = eval(x,y);
	double step = 1;
	
    for(int time_=1;time_<=1e5;++time_)
	{
		bool flag = 0;
		double X,Y;
		for(int i = 0;i < 4;++i)
		{
			double xx = x + dx[i]*step;
            double yy = y + dy[i]*step;
			double val = eval(xx,yy);
			if(val<err)
			{
				err  = val;
				flag = 1;
				X    = xx;
                Y    = yy;
			}
		}
		if(flag)
        {
            x = X;
            y = Y;
        }
		else 
            step/=2;
	}
	if(err<1e-6)
        printf("%.5f %.5f\n",x,y);
	return 0;
}

/*double x[MAXN];
double y[MAXN];
double r[MAXN];

void input()
{
    for(int i = 1; i<=3;i++)
    {
        fscanf(stdin,"%lf%lf%lf",&x[i],&y[i],&r[i]);
    }
}

void process()
{
    double det = (y[2]-y[3])*(x[1]-x[2])-(y[2]-y[1])*(x[3]-x[2]);
    if(det < 0)
        det = - det;
    if (det < EPS)
        return ;
    else{
        double det_x =  det;
        double det_y = -det;

        double y_0   = y[1] + (y[2]-y[1])*r[1]/(r[1]+r[2]);
        double x_0   = x[1] + (x[2]-x[1])*r[1]/(r[1]+r[2]);
        double y_0p  = y[3] + (y[2]-y[3])*r[3]/(r[3]+r[2]);
        double x_0p  = x[3] + (x[2]-x[3])*r[3]/(r[3]+r[2]);
        
        double x_ = -(y[2]-y[3])*(y[2]-y[1])*y_0  + 
                     (y[2]-y[3])*(y[2]-y[1])*y_0p + 
                     (y[2]-y[3])*(x[1]-x[2])*x_0  + 
                     (y[2]-y[1])*(x[3]-x[2])*x_0p ;

        double y_ = -(x[2]-x[3])*(x[2]-x[1])*x_0  + 
                     (x[2]-x[3])*(x[2]-x[1])*x_0p + 
                     (x[3]-x[2])*(y[2]-y[1])*y_0  - 
                     (x[1]-x[2])*(y[2]-y[3])*y_0p ;

        x_ = x_ / det_x;
        y_ = y_ / det_y;

        fprintf(stdout,"%.5f %.5f\n",x_,y_);
    }


}

int main()
{
#ifdef INPUT_REDIRECTION
	freopen("in.in","r",stdin);
#endif
    input();
    process();

    return 0;
}
*/
