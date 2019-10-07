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

INT n,m,i,j,a[2001],cnt,sum;
vector<INT>v;
vector<INT>::iterator it;

int main(	)
{
//	READ
	
	while(scanf("%d",&n) && n)
	{
		for(i=0 ; i<n ; i++)
		{
			cin>>m;
			v.push_back(m);
		}
		
		sort(v.begin(),v.end());
		
	//	cout<<"vec=";
	//	for(i=0 ; i<v.size() ; i++)
	//	cout<<v[i]<<" ";
	//	cout<<endl;
		
		for(i=0,cnt=0 ; i<n-2 ; i++)
		for(j=i+1 ; j<n-1 ; j++)
		{
			sum=v[i]+v[j];
			
			cnt+=v.end()-upper_bound(v.begin()+j,v.end(),sum);
			
	//		it=upper_bound(v.begin()+j+1,v.end(),sum);
	//		cout<<"sum="<<sum<<" it="<<*it<<endl;
	//		cout<<"i="<<i<<" j="<<j<<" cnt="<<cnt<<endl;
		}
		
		v.clear();
	//	cout<<"answer=";
		cout<<cnt<<endl;
	}
}
