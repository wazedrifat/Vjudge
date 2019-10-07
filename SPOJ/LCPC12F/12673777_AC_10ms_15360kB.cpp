//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define	INT			int
#define PII			pair<INT,INT>
#define FOR(A,B,C)	for(INT A=B ; A<=C ; A++)
#define SCN(N)		INT N;	scanf("%d",&N);
#define SN(N)		scanf("%d",&N);
#define PTC(A)		printf("%d. %d\n",t,A);
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

int main(	)
{
  // READ
	SCN(test)

    long long a[2001];
	FOR(t,1,test)
	{
		SCN(k)SCN(n)

        FOR(i,0,2000)   a[i]=0;

		long long cnt=0;
		FOR(i,0,n-1)
		{
		    SCN(x)
            
            if(k-x<0)   continue;
            
		    cnt+=a[k-x];
		    a[x]++;
		}

		printf("%d. %lld",t,cnt);

		if(t<test)  printf("\n");
	}
}
