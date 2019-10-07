//wazed rifat

#include<bits/stdc++.h>
using namespace std;

int i,j,sum,cnt,t,g,a,b,l,n,k;
vector<int>p;
bool f[1000000];

int main(	)
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
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&a,&b);
		
		if(a!=b)
		g=__gcd(a,b);
		else
		g=a;
		
		if(g==1)
		{
			printf("1\n");
			
			continue;
		}
		
		if(f[g]==0 && g%2==1)
		{
			printf("2\n");
			
			continue;
		}
		
		for(i=0,sum=1 ; i<l && p[i]<=g; i++)
		{
			cnt=1;
			
			while(g%p[i]==0)
			{
				g/=p[i];
				
				cnt++;
			}
			
			sum*=cnt;
		}
		
		printf("%d\n",sum);
		
	}
	
}


