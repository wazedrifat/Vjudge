//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

int i,j,n,test,sum,ans,cnt,t,k,p[86028122];
bool f[86028122];

int main(	)
{
	int m=86028122;
	f[0]=f[1]=1;
	p[1]=2;
	
	for(i=4 ; i<=m ; i+=2)
	f[i]=1;
	
	for(i=3 ; i*i<=m ; i+=2)
	{
		if(f[i]==0)
		for(j=i*i ; j<=m ; j+=2*i)	f[j]=1;
	}
	
	for(i=3,j=2 ; i<=m ; i+=2)
	if(f[i]==0)	p[j++]=i;
	
	scanf("%d",&n);
	
	while(n--)
	{
		scanf("%d",&k);
		
		printf("%d\n",p[k]);
	}
	
}

