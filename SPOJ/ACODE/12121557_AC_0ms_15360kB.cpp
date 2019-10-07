//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT long long int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,l,dp[50010];
string s;

int main(	)
{
	while(cin>>s && s[0]!='0')
	{
		for(i=1,l=s.length(),dp[0]=1 ; i<l ; i++)
		{	
			dp[i]=0;
			
			n=(s[i-1]-'0')*10+s[i]-'0';
			
			if(n>=10 && n<=26)
			{
				if(i>=2)
				dp[i]=dp[i-2];
				else
				dp[i]=1;
			}
			
			if(s[i]!='0')
			dp[i]+=dp[i-1];
			
		//	printf("dp[%lld]=%lld ",i,dp[i]);
		}
		
		//cout<<endl;
		printf("%lld\n",dp[l-1]);
	}
}

