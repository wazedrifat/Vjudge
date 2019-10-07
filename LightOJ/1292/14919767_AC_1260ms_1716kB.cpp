#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-12
#define NEX(x) ((x+1)%n)
#define PRV(x) ((x-1+n)%n)
#define RAD(x) ((x*M_PI)/180)
#define DEG(x) ((x*180)/M_PI)
#define PII pair<int, int> 

const double PI=acos(-1.0);

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

ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}

istream &operator>>(istream &is, PT &p) {
    is >> p.x >> p.y;
    return is;
}

PT a[800];
map<PII, int>m;

//void check(int i)
//{
//	cout<<"i="<<i<<" : ";
//	for(auto w : m)
//		cout<<"( "<<w.first.second<<"/"<<w.first.first<<"="<<w.second<<")	";
//	cout<<endl;
//}

int main()
{
	int test;
	scanf("%d", &test);
	
	for(int t=1 ; t<=test ; t++)
	{
		int n;
		cin>>n;
		
		for(int i=0 ; i<n ; i++)
		cin>>a[i];
		
		if(n<3)
		{
			cout<<"Case "<<t<<": "<<n<<endl;
			continue;
		}
		
		int maxi=1;
		for(int i=0 ; i<n ; i++)
		{
			m.clear();
			for(int j=i+1 ; j<n ; j++)
			{
				PII p=PII(a[i].x-a[j].x, a[i].y-a[j].y);
				int g=__gcd(p.first, p.second);
				p.first/=g;
				p.second/=g;
				
				map<PII, int>::iterator it=m.find(p);
				
				if(it==m.end())
					m[p]=1;
				else
				{
					it->second++;
					maxi=max(maxi, it->second);
				}
			}
			
//			check(i);
			
		}
		
		cout<<"Case "<<t<<": "<<maxi+1<<endl;
	}
}