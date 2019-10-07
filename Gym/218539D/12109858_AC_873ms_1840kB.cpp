//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define TYP unsigned long long int
#define U unsigned int
#define PI 2.0*acos(0.0)
#define PII pair<int,int>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

TYP i,j,n,m,test,sum,cnt,t,ps,l;

int main(	)
{
	scanf("%llu",&t);
	
	while(t--)
	{
		scanf("%llu",&n);
		
		for(i=0,sum=0 ; i<n ; i++)
		{
			cin>>m;
			
			m%=1000000007;
			sum+=m;
			sum%=1000000007;
		}
		
		printf("%llu\n",sum%1000000007);
	}
}

