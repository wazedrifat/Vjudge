//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define TYP long long int
#define U unsigned int
#define PI 2.0*acos(0.0)
#define PII pair<int,int>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

TYP i,j,n,m,test,sum,cnt,t,ps,l,maxx,a[10005];

int main(	)
{
//	READ
	
	cin>>test;
	
	for(t=1 ; t<=test ; t++)
	{
		scanf("%lld",&n);
		
		for(i=0 ; i<n ; i++)
		{
			scanf("%lld",&a[i]);
			
			if(i==0)	continue;
			else if(i==1)	a[1]=max(a[0],a[1]);
			else
			a[i]=max(a[i-1] , a[i]+a[i-2]);
		}
		
//		for(i=0 ; i<n ; i++)
//		cout<<a[i]<<" ";
//		cout<<endl;
		
		printf("Case %lld: %lld\n",t,a[n-1]);
		
		memset(a,0,sizeof a);
	}
}