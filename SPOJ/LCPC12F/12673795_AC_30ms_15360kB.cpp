//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define	INT			int
#define PII			pair<INT,INT>
#define FOR(A,B,C)	for(INT A=B ; A<=C ; A++)
#define SCN(N)		INT N;	scanf("%d",&N);
#define SN(N)		scanf("%d",&N);
#define PTC(A)		printf("%d. %lld\n",t,A);
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

vector<INT>v;
vector<INT>::iterator it1,it2;

int main(	)
{
//    READ
	SCN(test)

	FOR(t,1,test)
	{
		SCN(k)SCN(n)

		long long cnt=0;
		FOR(i,0,n-1)
		{
		    SCN(x)  PB(v,x)
		}

		sort(ALL(v));

  //      cout<<"ful=";   FOR(i,0,v.size()-1)    printf("%d ",v[i]);   cout<<endl;

		FOR(i,0,n-1)
		{
		    INT m=k-v[i];

		    it1=upper_bound(ALL(v),m);
		    it2=lower_bound(ALL(v),m);

	//	    cout<<"it1="<<it1-v.begin()<<" it2="<<it2-v.begin()<<" cnt1="<<cnt<<endl;

		    long long sum=it1-it2;

		    if(m+m==k && sum>0)  sum--;

            cnt+=sum;

	//	    cout<<"cnt2="<<cnt<<endl;
		}

        v.clear();

		PTC(cnt/2)
	}
}
