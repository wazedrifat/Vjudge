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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,a[101];
vector<INT>v;

int main(	)
{
	cin>>n;
	
	for(i=0 ; i<n ; i++)	cin>>a[i];
	
	for(i=0 ; i<n ; i++)
	if(a[i])
	for(j=0 ; j<n ; j++)
	for(k=0 ; k<n ; k++)
	v.push_back( (a[j]+a[k])*a[i] );
	
	sort(v.begin(),v.end());
	
//	for(i=0 ; i<v.size() ; i++)	cout<<v[i]<<"  ";
//	cout<<endl;
	
	for(i=0,cnt=0 ; i<n ; i++)
	for(j=0 ; j<n ; j++)
	for(k=0 ; k<n ; k++)
	cnt+=upper_bound(v.begin(),v.end(),(a[i]*a[j])+a[k])-lower_bound(v.begin(),v.end(),(a[i]*a[j])+a[k]);
	
	cout<<cnt;
}
