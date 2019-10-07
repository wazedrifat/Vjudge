//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,l,k,minn,a[20001];

int main(	)
{
	cin>>t;
	
	while(t--)
	{
		cin>>n>>k;
		
		for(i=0 ; i<n ; i++)
		cin>>a[i];
		
		sort(a,a+n);
		
		for(i=0,minn=1e9 ; i<n ; i++)
		{
			if(i+1>=k)
			minn=min(minn,a[i]-a[i+1-k]);
			
			if(i+k-1<n)
			minn=min(minn,a[i+k-1]-a[i]);
		}
		
		cout<<minn<<endl;
	}
}
