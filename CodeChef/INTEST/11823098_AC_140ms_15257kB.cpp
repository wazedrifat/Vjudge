//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,n,test,sum,ans,cnt,t,k,x;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>n>>k;
	
	for(i=0 ; i<n ; i++)
	{
		cin>>x;
		
		if(x%k==0)	cnt++;
	}
	
	cout<<cnt;
	
}

