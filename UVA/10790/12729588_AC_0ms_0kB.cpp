//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define	INT			long long int
#define PII			pair<INT,INT>
#define FOR(A,B,C)	for(int A=B ; A<=C ; A++)
#define SI(N)		INT N;	scanf("%d",&N);
#define SD(N)		double N;	scanf("%lf",&N);
#define SC(N)		scanf("%d",&N)
#define PTC(A)		printf("Case %lld: %lld\n",t++,A);
#define PT(A)		printf("%d\n",A);
#define ALL(V)		V.begin(),V.end()
#define MS(ARR,VAL) memset(ARR,VAL,sizeof ARR);
#define PB(VEC,VAL)	VEC.push_back(VAL);
#define MAX3(A,B,C)	max(A , max(B , C) )
#define MIN3(A,B,C)	min(A , min(B , C) )
#define PI			2.0*acos(0.0)
#define READ		freopen("input1.txt","r",stdin);
#define boost		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS			1e-9

INT sum,cnt;

int main(	)
{
	INT a,b,t=1;
	
	while(cin>>a>>b && ( a || b) )
	{
		INT sum=( (a*(a-1))/2 ) * ( (b*(b-1))/2 );
		PTC(sum)
	}
}

