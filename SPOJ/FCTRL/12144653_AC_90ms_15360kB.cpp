//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT long long int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<TYP,TYP>
#define READ freopen("input1.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

INT i,j,n,m,test,sum1,sum2,cnt,t,ps,l;

int main(	)
{
	boost
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(i=5,sum1=0 ; i<=n ; i*=5)
		sum1+=n/i;
		
		for(i=2,sum2=0 ; i<=n ; i*=2)
		sum2+=n/i;
		
		cout<<min(sum1,sum2)<<endl;
	}
}

