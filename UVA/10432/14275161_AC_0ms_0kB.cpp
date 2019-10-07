#include<bits/stdc++.h>
using namespace std;

#define PI (double)2.0*acos(0.0)

double Area(double a, double b, double c)
{
	double s=(a+b+c)/2.0;
	return sqrt( s*(s-a)*(s-b)*(s-c) );
}

int main()
{
	double r, n;
	while(scanf("%lf %lf", &r, &n)!=EOF)
	{
		double x=r*r/2*sin(2.0*PI/n);
		printf("%.3lf\n", n*x);
	}
}
