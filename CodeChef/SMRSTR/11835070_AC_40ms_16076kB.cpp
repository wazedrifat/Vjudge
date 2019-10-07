//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,n,test,sum,ans,cnt,t,k,q;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n>>q;
		
		for(i=0,sum=1 ; i<n ; i++)
		{
			cin>>k;
			
			if(sum>0)
			sum*=k;
			if(sum>1000000000)
			sum=0;
		}
		
		for(i=0 ; i<q ; i++)
		{
			cin>>k;
			
			if(sum==0)
			cout<<0<<" ";
			else cout<<k/sum<<" ";
		}
		
		cout<<endl;
	}
	
}