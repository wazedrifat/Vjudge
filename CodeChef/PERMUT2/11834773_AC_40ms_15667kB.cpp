//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

int n=1,t,f=0,i,a[100000];

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	while(n)
	{
		cin>>n;
		
		if(n==0)
		return 0;
		
		for(i=0 ; i<n ; i++)
		cin>>a[i];
		
		for(i=0,f=0 ; i<n&&f==0 ; i++)
		if(a[a[i]-1]!=i+1)
		{
//			printf("i=%d	a[i]=%d	a[a[i]]=%d\n",i,a[i],a[a[i]-1]);
			
			cout<<"not ambiguous"<<endl;
			
			f=1;
			
			break;
		}
		
		if(f==0)
		cout<<"ambiguous"<<endl;
	}
	
}