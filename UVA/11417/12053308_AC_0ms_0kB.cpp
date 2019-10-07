//wazed rifat

#include<bits/stdc++.h>
using namespace std;

int i,j,n,test,sum,ans,cnt,t,k,a[501][501];

int main(	)
{
	for(i=1 ; i<500 ; i++ )
	for(j=i+1 ; j<=500 ; j++)
	a[i][j]=a[j][i]=__gcd(i,j);
	
	while(scanf("%d",&n) && n!=0)
	{		
		for(i=1,sum=0 ; i<n ; i++)
		for(j=i+1 ; j<=n ; j++)
		sum+=a[i][j];
		
		printf("%d\n",sum);
	}
	
}

