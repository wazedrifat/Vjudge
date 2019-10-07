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

TYP i,j,n,m,test,sum,cnt,t,ps,l,wt,dp[1001][31];
struct rifat
{
	TYP pr,w;
}a[1001];

TYP fn( TYP pos , TYP tot )
{
	TYP pr1,pr2;
	
	if(pos>=n)	return 0;
	
	if(dp[pos][tot]!=-1)	return dp[pos][tot];
	
//	printf("pos=%lld  pr1=%lld  pr2=%lld  ,tot=%lld\n",pos,pr1,pr2,tot);
	
	if(a[pos].w+tot<=wt)
		pr1=a[pos].pr+fn( pos+1 , tot+ a[pos].w );
	else pr1=0;
	
	pr2= fn( pos+1 , tot );
	
//	printf("pos=%lld  pr1=%lld  pr2=%lld  ,tot=%lld\n",pos,pr1,pr2,tot);
	
	dp[pos][tot]=max( pr1 , pr2 );
	
	return dp[pos][tot];
}

int main(	)
{
//	READ
	
	scanf("%lld",&t);
	
	while(t--)
	{
		scanf("%lld",&n);
		
		for(i=0 ; i<n ; i++)
			scanf("%lld%lld",&a[i].pr,&a[i].w);
			
		scanf("%lld",&m);
		
		for(i=0,sum=0 ; i<m ; i++)
		{
			scanf("%lld",&wt);
			
			memset(dp , -1 , sizeof dp);
			
//			printf("%lld\n",fn(0,0));
			
			sum+=fn(0,0);
		}
		
		printf("%lld\n",sum);
	}
}
