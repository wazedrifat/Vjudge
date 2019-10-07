//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT long long int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define MIN3(A,B,C) min(A , min(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,maxx,d;

int main(	)
{
	cin>>n>>d;
	
	PII a[n];
	
	for(i=0 ; i<n ; i++)
	cin>>a[i].first>>a[i].second;
	
	sort(a,a+n);
	
	i=0;	j=0;
	while(j<n)
	{
		while(a[j].first-a[i].first<d)
		sum+=a[j++].second;
		
		maxx=max(maxx,sum);
		
		sum-=a[i++].second;
	}
	
	cout<<maxx<<endl;
}
