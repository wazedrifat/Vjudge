//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define MIN3(A,B,C) min(A , min(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,d,r;
vector<INT>v,v1;

bool comp (INT aa , INT bb)
{
	if(aa>=bb)	return 1;
	else return 0;
}

int main(	)
{
//	READ
	while(cin>>n>>d>>r && (n || d || r) )
	{
		for(i=0 ; i<n ; i++)	
		{
			cin>>m;
			v.push_back(m);
		}
		
		for(i=0 ; i<n ; i++)	
		{
			cin>>m;
			v1.push_back(m);
		}
		
		sort(v.begin(),v.end());
		sort(v1.begin(),v1.end(),comp);
		
		for(i=0,sum=0 ; i<n ; i++)
		{
			if(v[i]+v1[i]>d)
			sum+=(v[i]+v1[i]-d)*r;
		}
		
		v.clear();	v1.clear();
		
		cout<<sum<<endl;
	}
}