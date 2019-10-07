//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define	INT			long long int
#define PII			pair<double,double>
#define FOR(A,B,C)	for(INT A=B ; A<=C ; A++)
#define SI(N)		INT N;	scanf("%d",&N);
#define SD(N)		double N;	scanf("%lf",&N);
#define SC(N)		scanf("%d",&N);
#define PTC(A)		printf("Case %d: %d\n",t,A);
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

INT sol(INT a, INT b, INT c)
{
	double sum=sqrt(b*b-4*a*c);
	
	double r=(-b+sum)/(2.0*a);
	
//	cout<<"r="<<r<<endl;
	
	return ceil(r);
}

int main(	)
{
	INT n,t=1;
	while(scanf("%lld",&n) && n)
	{
		INT s=sol(1,-3,-2*n);
		
		printf("Case %lld: %lld\n",t++,s);
	}
}

