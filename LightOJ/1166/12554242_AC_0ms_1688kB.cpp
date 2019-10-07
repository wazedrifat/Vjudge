//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT	int
#define PII	pair<INT,INT>
#define FOR(A,B,C)	for(INT A=B ; A<=C ; A++)
#define SN(N)	INT N;	scanf("%d",&N);
#define PTC(A)	printf("Case %d: %d\n",t,A);
#define PT(A)	printf("%d\n",A);
#define ALL(V)	V.begin(),V.end()
#define MS(ARR,VAL) memset(ARR,VAL,sizeof ARR);
#define PB(VEC,VAL)	VEC.push_back(VAL);
#define MAX3(A,B,C)	max(A , max(B , C) )
#define MIN3(A,B,C)	min(A , min(B , C) )
#define PI	2.0*acos(0.0)
#define READ	freopen("input1.txt","r",stdin);
#define boost	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS	1e-9
#define UP(VEC,VAL)		upper_bound(VEC.begin(),VEC.end(),VAL)
#define LOW(VEC,VAL)	lower_bound(VEC.begin(),VEC.end(),VAL)

INT sum,cnt,a[101];

INT BS(INT ll, INT rr, INT xx)
{
    FOR(k,ll,rr)
    if(a[k]==xx)	return k;
    
    return -1;
}

int main(	)
{
	SN(test)
	
	FOR(t,1,test)
	{
		SN(n)
		
		FOR(i,0,n-1)	scanf("%d",&a[i]);
		
		cnt=0;
		
		FOR(i,0,n-1)
		{
			if(a[i]==i+1)	continue;
			
			INT k=BS(i,n-1,i+1);
			
			if(k!=i)	cnt++;
			
			a[k]=a[i];
			
//			cout<<"arr=";
//			FOR(j,0,n-1)	cout<<a[j]<<" ";
//			cout<<endl;			
//			cout<<"i="<<i<<" k="<<k<<" cnt="<<cnt<<endl;
		}
		
		PTC(cnt)
	}
}


