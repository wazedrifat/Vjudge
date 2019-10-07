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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,a,b,q;
vector<INT>v;

int main(	)
{
//	READ
	scanf("%d",&test);
	
	for(t=1 ; t<=test ; t++)
	{
		scanf("%d%d",&n,&q);
		
		for(i=0 ; i<n ; i++)
		{
			scanf("%d",&k);
			v.push_back(k);
		}
		
		printf("Case %d:\n",t);
		
		for(i=0 ; i<q ; i++)
		{
			scanf("%d%d",&a,&b);
			
			sum=upper_bound(v.begin(),v.end(),b)-lower_bound(v.begin(),v.end(),a);;
			printf("%d\n",sum);
		}
		
		v.clear();
	}
	
}
