//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX3(A,B,C) max(A , max(B , C) )
#define MIN3(A,B,C) min(A , min(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define UP(VEC,VAL)		upper_bound(VEC.begin(),VEC.end(),VAL)
#define LOW(VEC,VAL)	lower_bound(VEC.begin(),VEC.end(),VAL)

const int mx=4001;
INT i,j,n,cnt,t,k,a[mx],b[mx],c[mx],d[mx];
vector<INT>m;

int main(	)
{
	scanf("%d",&t);
	
	while(t--)
	{
		m.clear();
		
		scanf("%lld",&n);
		
		for(i=0 ; i<n ; i++)
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
		
		for(i=0,k=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
		m.push_back(a[i]+b[j]);
		
		sort(m.begin(),m.end());
		
		for(i=0,cnt=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
		cnt+=UP(m,-c[i]-d[j])-LOW(m,-c[i]-d[j]);
		
		printf("%d\n",cnt);
		
		if(t)	printf("\n");
	}
}
