//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

LLI i,j,n,g,l,t;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>t;
	
	while(t--)
	{
		cin>>g>>l;
		
		if(g==l)
		{
			printf("%d %d\n",g,l);
			
			continue;
		}
		else if(l%g)
		{
			printf("-1\n");
			
			continue;
		}
		
		printf("%d %d\n",g,l);
	}
	
}

