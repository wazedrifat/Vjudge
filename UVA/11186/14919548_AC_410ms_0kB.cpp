#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-12
#define NEX(x) ((x+1)%n)
#define PRV(x) ((x-1+n)%n)
#define RAD(x) ((x/180.0)*PI)
#define DEG(x) ((x*180)/M_PI)
const double PI=2.0*acos(0.0);

inline int dcmp (double x) { return x < -EPS ? -1 : (x > EPS); }
//inline int dcmp (int x) { return (x>0) - (x<0); }

class PT {
public:
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    double Magnitude() {return sqrt(x*x+y*y);}

    bool operator == (const PT& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
    bool operator != (const PT& u) const { return !(*this == u); }
    bool operator < (const PT& u) const { return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0); }
    bool operator > (const PT& u) const { return u < *this; }
    bool operator <= (const PT& u) const { return *this < u || *this == u; }
    bool operator >= (const PT& u) const { return *this > u || *this == u; }
    PT operator + (const PT& u) const { return PT(x + u.x, y + u.y); }
    PT operator - (const PT& u) const { return PT(x - u.x, y - u.y); }
    PT operator * (const double u) const { return PT(x * u, y * u); }
    PT operator / (const double u) const { return PT(x / u, y / u); }
    double operator * (const PT& u) const { return x*u.y - y*u.x; }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double dist(PT p, PT q)   { return sqrt(dist2(p,q)); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
double dis(PT p, PT q)
{
	return sqrt( (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y) );
}
ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}

int n, r;
PT p[500];

double area(PT p1, PT p2, PT p3)
{
	return 0.5 * fabs( p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p2.x*p1.y - p3.x*p2.y - p1.x*p3.y );
	double a=dis(p1, p2), b=dis(p2, p3), c=dis(p3, p1);
	double s=a+b+c;
	s/=2.0;
	s=s*(s-a)*(s-b)*(s-c);
	return sqrt(s);
}

int main()
{
//	freopen("input.txt", "r", stdin);

//	p[0]=PT(0.0, 0.0);
	while(scanf("%d %d", &n, &r) && (n||r) )
	{
		for(int i=0 ; i<n ; i++)
		{
			double t;
			scanf("%lf", &t);
			t/=180.0;
			t*=PI;

			p[i]=PT(r*cos(t), r*sin(t) );
		}
		
		double sum=0;
		for(int i=0 ; i<n ; i++)
		for(int j=i+1 ; j<n ; j++)
		for(int k=j+1 ; k<n ; k++)
			sum+=area(p[i], p[j], p[k]);

		printf("%.0lf\n", sum);
	}
}

