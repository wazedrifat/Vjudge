//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f;

INT fn(INT num)
{
	INT cnt1=0,cnt2=0;
	
	for(k=5 ; num>=k ; k*=5)
	cnt1+=num/k;
	
	for(k=2 ; num>=k ; k*=2)
	cnt2+=num/k;
	
	return min(cnt1,cnt2);
}

int main(	)
{
	cin>>test;
	
	for(t=1 ; t<=test ; t++)
	{
		cin>>n;
		
		i=1; j=100000000;
		
		while(i<=j)
		{
			m=(i+j)>>1;
			sum=fn(m*5);
			
			if(sum==n)	break;
			else if(sum>n)	j=m-1;
			else	i=m+1;
		}
		
	//	cout<<m<<" * "<<5<<" = "<<m*5<<endl;
		if(i<=j && sum==n)
		printf("Case %d: %d\n",t,m*5);
		else
		printf("Case %d: impossible\n",t);
	}
}
