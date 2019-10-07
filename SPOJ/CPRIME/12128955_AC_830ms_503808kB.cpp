//wazed rifat

#include<bits/stdc++.h>
using namespace std;

int i,j,n,test,sum,ans,cnt,t,ps,c;
double k,x;
bool f[100000001];
vector<int>p;
int mapp[100000001];
vector<int>::iterator it;

void sieve(int m)
{
	f[0]=f[1]=1;
	mapp[0]=mapp[1]=0;
	
	p.push_back(2);
	mapp[2]=1.0;
	
	for(i=3,c=2 ; i*i<=m ; i+=2)
	{
		if(f[i]==0)
		{
			t=i;
			
			p.push_back(i);
			mapp[i]=c++;
			
			for(j=i*i ; j<=m ; j+=2*i)	f[j]=1;
		}
	}
	
	for(i=t+2 ; i<=m ; i+=2)
	if(f[i]==0)
	{
		p.push_back(i);
		mapp[i]=c++;
	}
}

int main(	)
{
	sieve(100000000);
	
	while(scanf("%d",&n) && n>0)
	{
		it=upper_bound(p.begin(),p.end(),n);	it--;
		
		k=(double)mapp[*it];
		x=n/log(n);
		
		printf("%.1lf\n",100.0*fabs(k-x)/k);

	}
	
}