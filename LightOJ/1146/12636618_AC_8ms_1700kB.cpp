//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define	INT			double
#define PII			pair<INT,INT>
#define FOR(A,B,C)	for(int A=B ; A<=C ; A++)
#define SCN(N)		INT N;	scanf("%lf",&N);
#define SN(N)		scanf("%lf",&N);
#define PTC(A)		printf("Case %d: %.7lf\n",t,A);
#define PT(A)		printf("%.7lf\n",A);
#define ALL(V)		V.begin(),V.end()
#define MS(ARR,VAL) memset(ARR,VAL,sizeof ARR);
#define PB(VEC,VAL)	VEC.push_back(VAL);
#define MAX3(A,B,C)	max(A , max(B , C) )
#define MIN3(A,B,C)	min(A , min(B , C) )
#define PI			2.0*acos(0.0)
#define READ		freopen("input1.txt","r",stdin);
#define boost		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS			1e-7

int cnt;
struct POINT{	INT x,y;	};

INT dis(POINT p1 , POINT p2)
{
	INT sx=p1.x-p2.x,sy=p1.y-p2.y;
	
	return sqrt(sx*sx+sy*sy);
}

int main(	)
{
//	READ
	int test;
	cin>>test;
	
	FOR(t,1,test)
	{
		POINT a,b,c,d;
		
		SN(a.x)SN(a.y)	SN(b.x)SN(b.y) 
		SN(c.x)SN(c.y)	SN(d.x)SN(d.y)
		
		INT s1=dis(a,c),s2,s3=dis(b,d),s4;
//		cout<<"s1="<<s1<<" s2="<<s2<<" s3="<<s3<<endl;
//		if(s1>s2)
//		{
//			swap(a.x,b.x);
//			swap(a.y,b.y);
//		}
		
		INT minn=s1<s3?	s1:s3 ;	cnt=50;
		while(cnt--)
		{
			POINT m1,m2,m3,m4;
			
			m1.x=(2*a.x+b.x)/3.0;
			m1.y=(2*a.y+b.y)/3.0;
			
			m2.x=(a.x+2*b.x)/3.0;
			m2.y=(a.y+2*b.y)/3.0;
			
			m3.x=(2*c.x+d.x)/3.0;
			m3.y=(2*c.y+d.y)/3.0;
			
			m4.x=(c.x+2*d.x)/3.0;
			m4.y=(c.y+2*d.y)/3.0;
			
			s1=dis(a,c);	s2=dis(b,d);
			s3=dis(m1,m3);	s4=dis(m2,m4);
			
		//	cout<<" s3="<<s3<<" s4="<<s4<<endl;
		//	if(minn>s1)	minn=s1;
		//	if(minn>s2)	minn=s2;
			if(minn>s3)	minn=s3;
			if(minn>s4)	minn=s4;
			
			if(s3>s4)
			{
				a=m1;
				c=m3;
			}
			else
			{
				b=m2;
				d=m4;
			}
		//	cout<<"minn="<<minn<<"\n";
		}
		PTC(minn)
	}
}



