//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,test,sum,ans,cnt,t,k;
map<LLI,LLI>m;

LLI func(LLI n)
{
	if(n<=4)	return n;
	
	if(m[n]!=0)
	k=1;
	else if(n/2+n/3+n/4>=n)
	m[n]=max(func(n/2)+func(n/3)+func(n/4),ans);
	else
	m[n]=n;
	
	return m[n];
}

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	while(scanf("%lld",&t)!=EOF)
	{
		map<LLI,LLI>m;
		
		cout<<func(t)<<endl;
	}
	
}

