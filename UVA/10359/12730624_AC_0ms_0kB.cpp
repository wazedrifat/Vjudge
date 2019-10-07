//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define	INT			int
#define PII			pair<INT,INT>
#define FOR(A,B,C)	for(int A=B ; A<=C ; A++)
#define SI(N)		INT N;	scanf("%d",&N);
#define SD(N)		double N;	scanf("%lf",&N);
#define SC(N)		scanf("%d",&N)
#define PTC(A)		printf("Case %lld: %lld\n",t++,A);
#define PT(A)		printf("%lld\n",A);
#define ALL(V)		V.begin(),V.end()
#define MS(ARR,VAL) memset(ARR,VAL,sizeof ARR);
#define PB(VEC,VAL)	VEC.push_back(VAL);
#define MAX3(A,B,C)	max(A , max(B , C) )
#define MIN3(A,B,C)	min(A , min(B , C) )
#define PI			2.0*acos(0.0)
#define READ		freopen("input1.txt","r",stdin);
#define boost		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS			1e-9

string dp[300];

string sum(string s1, string s2, string s3)
{
	string s="";
	INT l1=s1.length(),l2=s2.length(),l3=s3.length();
	INT l=MAX3(l1,l2,l3);
	
	reverse(ALL(s1));	reverse(ALL(s2));	reverse(ALL(s3));
	
	FOR(i,1,l-l1)	s1+='0';
	FOR(i,1,l-l2)	s2+='0';
	FOR(i,1,l-l3)	s3+='0';
	
//	cout<<"s1="<<s1<<"	s2="<<s2<<"	s3="<<s3<<endl;
	
	INT cr=0;
	FOR(i,0,l-1)
	{
		INT a=s1[i]-'0',b=s2[i]-'0',c=s3[i]-'0';
		
		INT sum=a+b+c+cr;
		
		s+=(sum%10)+'0';
		sum/=10;
		
		cr=sum%10;
	}
	if(cr)	s+=cr+'0';
	
	reverse(ALL(s));
	
//	cout<<"s="<<s<<endl;

	return s;
}

int main(	)
{
	INT n;
	
	dp[0]="1";	dp[1]="1";	dp[2]="3";
	FOR(i,3,250)
	{
		dp[i]=sum( dp[i-1],dp[i-2],dp[i-2] );
//		cout<<"i="<<i<<"	dp[i]="<<dp[i]<<endl;
	}
	
	while(scanf("%d",&n)!=EOF)
	cout<<dp[n]<<endl;
}

