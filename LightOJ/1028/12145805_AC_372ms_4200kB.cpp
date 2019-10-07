//wazed rifat

#include<bits/stdc++.h>
#include<string>
using namespace std;

#define INT long long int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<TYP,TYP>
#define READ freopen("input1.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

INT i,n,test,sum,cnt,t,ps;
bool f[1000001];
vector<INT>p;

void sieve(INT m)
{
	f[0]=f[1]=1;
	
	p.push_back(2);
	
	for(INT ii=4 ; ii<=m ; ii+=2)	f[ii]=1;
	
	for(INT ii=3 ; ii*ii<=m ; ii+=2)
	if(f[ii]==0)
	for(INT jj=ii*ii ; jj<=m ; jj+=2*ii)	f[jj]=1;
	
	for(INT ii=3 ; ii<=m ; ii+=2)
	if(f[ii]==0)	p.push_back(ii);
	
	ps=p.size();
}

int main(	)
{
	sieve(1000000);
	
	scanf("%lld",&test);
	
	for(t=1 ; t<=test ; t++)
	{
		scanf("%lld",&n);
		
		for(i=0,sum=1 ; p[i]*p[i]<=n && i<ps ; i++)
		{
			for(cnt=0 ; n%p[i]==0 ; cnt++)	n/=p[i];
			
			sum*=(cnt+1);
		}
		
		if(n>1)	sum*=2;
		
		printf("Case %lld: %lld\n",t,sum-1);
	}
}

