#include <cstdio>
#include <cmath>

float x1 = 0,y1 = 0,x2 = 0,y2 = 0, x3 = 0, y3 = 0;
const float eps = 1e-6;

int main()
{
	fscanf(stdin,"%f%f%f%f%f%f", &x1,&y1,&x2,&y2,&x3,&y3);
	float distance12 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	float distance23 = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	float distance31 = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));



}