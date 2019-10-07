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

INT i,j,n,m,test,sum,cnt,t;
vector<INT>v;
vector<INT>::iterator it;

int main(	)
{
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(i=0 ; i<n ; i++)
		{
			cin>>m;
			v.push_back(m);
		}
		
		sort(v.begin(),v.end());
		
//		cout<<"vec=";
//		for(i=0 ; i<v.size() ; i++)	cout<<v[i]<<" ";
//		cout<<endl;
		
		cin>>n;
		
		for(i=0,sum=INT_MAX ; i<n ; i++)
		{
			cin>>m;
			
			if(sum==0)	continue;
			
			it=upper_bound(v.begin(),v.end(),m);
			if(it!=v.end())	sum=min(sum,abs(*it-m));
			
			if(it==v.begin())	continue;
			
			it--;
			sum=min(sum,abs(m-*it));
			
		//	cout<<*it1<<" "<<*it2<<" "<<endl;
		}
		
		v.clear();
		cout<<sum<<endl;
	}
}
