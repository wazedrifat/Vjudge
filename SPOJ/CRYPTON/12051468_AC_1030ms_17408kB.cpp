//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,sum,t,g,a,b,l,n,k;
vector<LLI>p;
bool f[1000000],m;
char s[200];

void sieve(	)
{
	n=1000000;
	
	p.push_back(2);
	
	for(i=3 ; i*i<=n ; i+=2)
	{
		if(f[i]==0)
		for(j=i*i ; j<=n ; j+=2*i)	f[j]=1;
	}
	
	for(i=3 ; i<=n ; i+=2)
	if(f[i]==0)		p.push_back(i);
	
	l=p.size();
}

bool div()
{
	for(j=0,sum=0 ; j<k ; j++)
	sum=( sum%p[i] )*10+s[j]-'0';
	
	sum=( sum%p[i] )*10;
	
	if(sum==0)	return 1;
	else return 0;
}

int main(	)
{
	sieve( );
	
	while( scanf("%s",&s) && scanf("%lld",&a)!=0 )
	{
		
		if(a==0)
		return 0;
		
		k=strlen(s);
		
		for(i=0,m=0 ; i<l && p[i]<a && m==0 ; i++)
		{
			if( div() )
			{
				m=1;
				
				printf("BAD %lld\n",p[i]);
				
				break;
			}
		}
		
		if(m==0)
		printf("GOOD\n");
		
	}
	
}


