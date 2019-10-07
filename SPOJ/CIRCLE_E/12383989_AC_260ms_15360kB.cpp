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

INT r1,r2,r3,r,a,a1,a2,a3,l,h,sum;
int t,i;

INT area(INT a , INT b , INT c)
{
	INT s=(a+b+c)/2.0;
	
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(	)
{
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%lf%lf%lf",&r1,&r2,&r3);
		
		a=area(r1+r2,r2+r3,r3+r1);
		
		l=0;
		h=MIN3(r1,r2,r3);
		i=10000;
		
		while(i--)
		{
			r=l/2.0+h/2.0;
			a1=area(r1+r2,r2+r,r+r1);
			a2=area(r2+r3,r3+r,r+r2);
			a3=area(r3+r1,r1+r,r+r3);
			sum=a1+a2+a3;
			
		//	cout<<"sum="<<sum<<"  a="<<a<<"  r="<<r<<endl;
			
			if(sum<a)	l=r;
			else	h=r;
		}
	//	cout<<endl;
		printf("%.6f\n",r);
	}
}
