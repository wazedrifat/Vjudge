//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define	INT			int
#define PII			pair<INT,INT>
#define FOR(A,B,C)	for(INT A=B ; A<=C ; A++)
#define SCN(N)		INT N;	scanf("%d",&N);
#define SN(N)		scanf("%d",&N);
#define PTC(A)		printf("Case %d: %d\n",t,A);
#define PT(A)		printf("%d\n",A);
#define ALL(V)		V.begin(),V.end()
#define PB(VEC,VAL)	VEC.push_back(VAL);
#define MAX3(A,B,C)	max(A , max(B , C) )
#define MIN3(A,B,C)	min(A , min(B , C) )
#define PI			2.0*acos(0.0)
#define READ		freopen("input1.txt","r",stdin);
#define boost		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS			1e-9

INT a[300001];

INT MS(INT n , INT m)
{
	INT	maxi=INT_MIN,s=0,l=0;
	PII p;	p.first=0;	p.second=0;	
	
	FOR(i,0,n-1)
	{
		cin>>a[i];
		
		s+=a[i];
		
		while(p.first<=i && s>m)
		{
			s-=a[l];
			l++;			
		}
		
		if(s<=m && maxi<=s)
		{
			maxi=s;	
			p.first=l;
			p.second=i;
		}
		
		if(s<0)
		{
			s=0;
			l=i+1;
		}
	}
	
	return maxi;
}

int main(	)
{
	SCN(n)SCN(m)
	
	PT(MS(n,m))
}



