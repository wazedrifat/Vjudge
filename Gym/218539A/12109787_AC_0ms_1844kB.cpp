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

TYP i,j,n,m,test,sum,cnt,t,ps,l,Mod=1000000007;

int main(	)
{
	scanf("%lld",&t);
	
	while(t--)
	{
		scanf("%lld",&n);
		
		n%=1000000007;
		
		if(!n)	n++;
		
		printf("%lld\n",n);
	}
}

