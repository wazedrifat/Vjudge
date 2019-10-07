//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,n,test,sum,ans,cnt,t,k,a,b,r;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>a>>b;
	
	n=t=a-b;
	k=0;
	cnt=-1;
	
	if(n==0)
	{
		cout<<1;
		
		return 0;
	}
	
	while(n)
	{
		r=n%10;
		n/=10;
		
		cnt++;
	}
	
	if(r<9)
	cout<<t+(LLI)pow(10,cnt);
	else
	cout<<t-(LLI)pow(10,cnt);
	
}

