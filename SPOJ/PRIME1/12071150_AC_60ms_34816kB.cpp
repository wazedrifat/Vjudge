//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int
#define PI 2.0*acos(0.0)
#define PII pair<int,int>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

LLI i,j,n,m,test,sum,cnt,t,ps,a,b;
bool f[10000001],f1[10000005];
vector<LLI>p;

void sieve(LLI m)
{
	f[0]=f[1]=1;
	
	p.push_back(2);
	
	for(i=4 ; i<=m ; i+=2)
	f[i]=1;
	
	for(i=3 ; i*i<=m ; i+=2)
	if(f[i]==0)
	{
		p.push_back(i);
		
		t=i;
		
		for(j=i*i ; j<=m ; j+=2*i)	f[j]=1;
	}
	
	for(i=t+2 ; i<=m ; i+=2)
	if(f[i]==0)	p.push_back(i);
	
	ps=p.size();
}

int main(	)
{
	sieve(10000000);
	
	scanf("%lld",&t);
	
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		
		if(b<=10000000)
		{
			for(i=a ; i<=b ; i++)
			if(f[i]==0)	printf("%lld\n",i);
		
			printf("\n");
			
			continue;
		}
		
		if(a==1)	a++;
		
		for(i=0 ; i<=b-a+5 ; i++)	f1[i]=0;
		
		for(i=0 ; i<ps && p[i]<=b ; i++)
		{
			j=(a/p[i])*p[i];
				
			if(j<a)	j+=p[i];
			
			for( ; j<=b ; j+=p[i])
			f1[j-a]=1;
		}
		
		for(i=a ; i<=b ; i++)
		if(f1[i-a]==0)	printf("%lld\n",i);
		
		printf("\n");
		
	}
}

