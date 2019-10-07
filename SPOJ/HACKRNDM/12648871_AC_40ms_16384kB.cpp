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
	SCN(n)SCN(k)

	INT a[n];

	INT cnt=0;
	FOR(i,0,n-1)
	{
		SN(a[i])

	//	f[ a[i] ]=1;
	}

//	FOR(i,0,n-1)	cout<<a[i]<<" ";
//	cout<<endl;

	sort(a,a+n);

    //FOR(i,0,n-1)	cout<<a[i]<<" ";
  //  cout<<endl;

	for(INT i=0 ; i<n ; i++)
	{
		if(binary_search(a,a+n,a[i]+k))	cnt++;
	}

	PT(cnt)
}



