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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,maxx;

int main(	)
{
	while(cin>>n && n)
	{
		for(i=0,sum=0,maxx=INT_MIN ; i<n ; i++)
		{
			cin>>m;
			
			sum+=m;
			maxx=max(maxx,sum);
			sum=max(0,sum);
		}
		
	//	cout<<maxx<<endl;
		
		if(maxx>0)
		cout<<"The maximum winning streak is "<<maxx<<".\n";
		else	cout<<"Losing streak."<<endl;
	}
}
