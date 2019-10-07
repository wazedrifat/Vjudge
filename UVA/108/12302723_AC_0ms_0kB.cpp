//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input2.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,maxx,a[101][101],dp[101];

INT MS(	)
{
	INT	maxi=INT_MIN,s=0;
	
	for(int ii=0 ; ii<n ; ii++)
	{
		maxi=max(maxi,s+dp[ii]);
		s=max(0,s+dp[ii]);
	}
	
	return maxi;
}

int main(	)
{
//	READ
	
	cin>>n;
	
	for(i=0 ; i<n ; i++)
	for(j=0 ; j<n ; j++)
	cin>>a[i][j];
	
	for(i=0,maxx=INT_MIN ; i<n ; i++)
	{
	//	memset(dp,0,sizeof dp);
		for(j=0 ; j<n ; j++)	dp[j]=0;
		
		for(k=i ; k<n ; k++)
		{
			for(j=0 ; j<n ; j++)
			dp[j]+=a[k][j];
			
			maxx=max(maxx,MS());
			
		//	for(int ii=0 ; ii<n ; ii++)	cout<<dp[ii]<<" ";
		//	cout<<endl<<"i="<<i<<"  k="<<k<<"  MS="<<MS()<<endl;
		}
	}
	//co\ut<<endl;
	cout<<maxx<<endl;
}
