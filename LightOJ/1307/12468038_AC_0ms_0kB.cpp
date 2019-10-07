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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f;
vector<INT>v;

int main(	)
{
//	READ
	
	cin>>test;
	
	for(t=1 ; t<=test ; t++)
	{
		cin>>n;
		
		for(i=0 ; i<n ; i++)
		{
			cin>>m;
			v.push_back(m);
		}
		
		sort(v.begin(),v.end());
		
		for(i=0,cnt=0 ; i<n ; i++)
		for(j=i+1 ; j<n ; j++)
		{
			sum=lower_bound(v.begin()+j+1,v.end(),v[i]+v[j])-v.begin();
			sum-=j+1;
			cnt+=sum;
			
		//	cout<<" cnt="<<cnt<<" it="<<sum<<" plus="<<v[i]+v[j]<<" it1="<<lower_bound(v.begin()+j+1,v.end(),v[i]+v[j])-v.begin()<<endl;
		}
		
		v.clear();
		
		printf("Case %d: %d\n",t,cnt);
	}
}
