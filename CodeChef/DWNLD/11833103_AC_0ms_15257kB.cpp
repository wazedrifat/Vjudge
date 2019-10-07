//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,n,test,sum,ans,cnt,t,k,ti,d;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>test;
	
	while(test--)
	{
		cin>>n>>k;
		
		sum=0;
		ti=0;
		while(n--)
		{
			cin>>t>>d;
			
			ti+=t;
			
			if(ti<=k)
			continue;
			else if(ti-t<k&&ti>k)
			sum+=(ti-k)*d;
			else
			sum+=t*d;
			
		}
		
		cout<<sum<<endl;
		
	}
	
}

