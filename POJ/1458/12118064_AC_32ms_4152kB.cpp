//wazed rifat

//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

#define TYP int
#define PI 2.0*acos(0.0)
#define PII pair<TYP,TYP>
#define READ freopen("input.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

TYP i,j,n,m,test,sum,cnt,t,ps,l1,l2,dp[1000][1000];
char s1[1000],s2[1000];

int main(	)
{
//	READ 
	
	while(scanf("%s",&s1)!=EOF && scanf("%s",&s2) )
	{
	//	cout<<s1<<"  "<<s2<<endl;
		
		memset(dp , 0 , sizeof dp);
		
		for(i=0,l1=strlen(s1) ; i<l1 ; i++)
		{
			for(j=0,l2=strlen(s2) ; j<l2 ; j++)
			{
				if(s1[i]==s2[j])
				dp[i+1][j+1]=dp[i][j]+1;
				else
				dp[i+1][j+1]=max( dp[i+1][j] , dp[i][j+1] );
			}
		}
		
		cout<<dp[l1][l2]<<endl;;
	}
}

