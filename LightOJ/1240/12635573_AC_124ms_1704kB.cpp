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

INT sum,cnt;
struct POINT{	INT xx,yy,zz;	};

INT dis(POINT p1 , POINT p2)
{
	INT sx=p1.xx-p2.xx,sy=p1.yy-p2.yy,sz=p1.zz-p2.zz;
	
	return sqrt(sx*sx+sy*sy+sz*sz);
}

int main(	)
{
	int test;
	cin>>test;
	
	FOR(t,1,test)
	{
		POINT l,r,p;
		
		SN(l.xx)SN(l.yy)SN(l.zz)
		SN(r.xx)SN(r.yy)SN(r.zz) 
		SN(p.xx)SN(p.yy)SN(p.zz)
		
		INT s1=dis(l,p),s2=dis(r,p);
//		cout<<"l to p="<<dis(l,p)<<" r to p="<<dis(r,p)<<endl;
		if(s1>s2)
		{
//			cout<<"0";
			swap(l.xx,r.xx);
			swap(l.yy,r.yy);
			swap(l.zz,r.zz);
		}
//		cout<<"1\n";
		INT minn=s1<s2?	s1:s2 ;	cnt=100;
		while(cnt--)
		{
	//		cout<<"l to p="<<dis(l,p)<<" r to p="<<dis(r,p)<<endl;
			POINT m1,m2;
			
			m1.xx=(2*l.xx+r.xx)/3.0;
			m1.yy=(2*l.yy+r.yy)/3.0;
			m1.zz=(2*l.zz+r.zz)/3.0;
			
			m2.xx=(l.xx+2*r.xx)/3.0;
			m2.yy=(l.yy+2*r.yy)/3.0;
			m2.zz=(l.zz+2*r.zz)/3.0;
			
			s1=dis(m1,p);	s2=dis(m2,p);
			if(minn>s1+EPS)	minn=s1;
			if(minn>s2+EPS)	minn=s2;
			if(minn>dis(l,p)+EPS)	minn=dis(l,p);
			if(minn>dis(r,p)+EPS)	minn=dis(r,p);
			
			if(s1>s2+EPS)	l=m1;
			else	r=m2;
		//	cout<<"minn="<<minn<<"\n";
		}
		PTC(minn)
	}
}



