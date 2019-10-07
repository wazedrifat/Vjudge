//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT double
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define MIN3(A,B,C) min(A , min(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,sum,ps,l,h,k,f,x,y,c;
int t,test,cnt;

struct POINT{	INT xx,yy;	};
struct EQUATION{	INT aa,bb,cc;	}e1,e2;

EQUATION convert_to_equation(POINT p1 , POINT p2)
{
	EQUATION temp;
	
	temp.aa=p2.yy-p1.yy;
	temp.bb=p1.xx-p2.xx;
	temp.cc=p1.yy*(p2.xx-p1.xx)+p1.xx*(p1.yy-p2.yy);
	
	return temp;
}

POINT sol_2_equation(EQUATION eq1 , EQUATION eq2)
{
	POINT temp;
	
	INT value=eq1.aa*eq2.bb-eq2.aa*eq1.bb;
	
	POINT pp;
	
	pp.xx=0;	pp.yy=0;
	
	//if(value==0)	return pp;
	
	temp.xx=(eq1.bb*eq2.cc-eq2.bb*eq1.cc)/value;
	temp.yy=(eq1.cc*eq2.aa-eq2.cc*eq1.aa)/value;
	
	return temp;
}

int main(	)
{
//	READ
	
	cin>>test;
	
	for(t=1 ; t<=test ; t++)
	{
		cin>>x>>y>>c;
		
		l=0;	cnt=10000;
		
		if(x>y)	h=x;
		else	h=y;
		
		while(cnt--)
		{
			n=l/2.0+h/2.0;
			
		//	cout<<"n="<<n<<"	";
			
			POINT p1,p2;
		
			p1.xx=0;	p1.yy=0;
			p2.xx=n;	p2.yy=sqrt(y*y-n*n);
			e1=convert_to_equation(p1,p2);
			
			p1.xx=0;	p1.yy=sqrt(x*x-n*n);
			p2.xx=n;	p2.yy=0;
			e2=convert_to_equation(p1,p2);
			
			POINT p=sol_2_equation(e1,e2);
			
		//	cout<<"point p=("<<p.xx<<","<<p.yy<<")"<<endl;
			
			if(p.yy>c)	l=n;
			else	h=n;
		}
		
		printf("Case %d: %.7f\n",t,n);
	}
}

