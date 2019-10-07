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

TYP BM(TYP B,TYP E)	
{
	if(E==0) return 1;
	if(E%2==0)
	{
		TYP ret=BM(B,E/2);
		return ((ret%Mod)*(ret%Mod))%Mod;
	}
	else return ((B%Mod)*(BM(B,E-1)%Mod))%Mod;

}

int main(	)
{
	scanf("%lld",&t);
	
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		
		printf("%lld\n",BM(n,m));
	}
}

