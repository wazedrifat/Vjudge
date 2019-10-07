//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,n,test,sum,ans,cnt,t,k;
bool f[10000000],f1[10000000];
vector<int>p;
map<int,int>mapp;

void sieve(int m)
{
	f[0]=f[1]=1;
	
	p.push_back(2);
	mapp[2]=1;
	
	for(i=4 ; i<=m ; i+=2)
	f[i]=1;
	
	for(i=3 ; i*i<=m ; i+=2)
	{
		if(f[i]==0)
		for(j=i*i ; j<=m ; j+=2*i)	f[j]=1;
	}
	
	for(i=3,j=2 ; i<=m ; i+=2)
	if(f[i]==0)
	{
		p.push_back(i);
		mapp[i]=j++;
	}
}

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);

	sieve(100000);
	
	cin>>i>>j;
	
	n=mapp[i];
	
//	cout<<n<<endl;
	
	if(j==p[n])
	cout<<"YES";
	else
	cout<<"NO";
}

