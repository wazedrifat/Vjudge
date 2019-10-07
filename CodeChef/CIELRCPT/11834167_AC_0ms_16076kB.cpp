//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,n,test,sum,ans,cnt,t,k,p;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>test;
	while(test--)
	{
		cin>>k;
		
		cnt=0;
		t=2048;
		
		while(k)
		{
			cnt+=k/t;
			k%=t;
			t/=2;
		}
		
		cout<<cnt<<endl;
	}
	
}

