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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f;
vector<INT>v;
vector<INT>::iterator it,it1;

int main(	)
{
	cin>>n;
	
	for(i=0 ; i<n ; i++)
	{
		cin>>k;
		v.push_back(k);
	}
	
	cin>>l;
	
	for(i=0 ; i<l ; i++)
	{
		cin>>m;
		
		it=upper_bound(v.begin(),v.end(),m);
		it1=lower_bound(v.begin(),v.end(),m)-1;
		
		if(it1!=v.end() && m>v[0])
		cout<<*it1<<" ";
		else	cout<<"X ";
		
		if(it!=v.end() && m<v[n-1])
		cout<<*it;
		else cout<<"X";
		
		cout<<endl;
	}
}
