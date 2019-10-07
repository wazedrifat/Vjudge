//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int
#define PI 2.0*acos(0.0)
#define PII pair<int,int>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

LLI i,j,n,m,test,sum,cnt,t,ps;
bool f[1000001];
vector<int>p;

void sieve(int m)
{
	f[0]=f[1]=1;
	
	p.push_back(2);
	
	for(i=4 ; i<=m ; i+=2)
	f[i]=1;
	
	for(i=3 ; i*i<=m ; i+=2)
	if(f[i]==0)
	{
		p.push_back(i);
		
		for(j=i*i,t=i ; j<=m ; j+=2*i)	f[j]=1;
	}
	
	for(i=t+2 ; i<=m ; i+=2)
	if(f[i]==0)	p.push_back(i);
	
	ps=p.size();
}

int main(	)
{
	sieve(1000000);
	
	while(cin>>n && n)
	{
		for(i=0,cnt=0,m=n ; i<ps && n>1 && p[i]<=n ; i++)
		{
			if(f[n]==0)
			{
				cnt++;
				break;
			}
			if(n%p[i]==0)
			{
				cnt++;
				
				while(n%p[i]==0)	n/=p[i];
			}
		}
		
		cout<<m<<" : "<<cnt<<endl;
	}
	
}

