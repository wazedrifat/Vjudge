//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,n,t,k,a,b,f[1000001],fac[11][1000001];
vector<LLI>p;

void sieve(LLI m)
{
	f[0]=f[1]=0;
	
	for(i=2 ; i<=m ; i+=2)
	f[i]++;
	
	for(i=3 ; i<=m ; i+=2)
	{
		if(f[i]==0)
		for(j=i,k=i ; j<=m ; j+=i)	f[j]++;
	}
}

int main(	)
{
//	freopen("input1.txt","r",stdin);
	
	sieve(1000000);
	
	for(i=1 ; i<=1000000 ; i++)
	{
		for(j=1 ; j<=10 ; j++)
		{
			if(f[i]==j)	fac[j][i]=fac[j][i-1]+1;
			else	fac[j][i]=fac[j][i-1];
		}
	}
	
	cin>>t;
	
	while(t--)
	{
		cin>>a>>b>>n;
		
		if(n==0 && a==1)	printf("1\n");
		else
		printf("%d\n",fac[n][b]-fac[n][a-1]);
	}
	
}