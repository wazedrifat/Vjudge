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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,maxx,dif;
vector<INT>v;
vector<INT>::iterator it,it1;

int main(	)
{
	cin>>n>>t;
	
	INT a[n];
	
	for(i=0,j=0,maxx=0,sum=0,dif=0 ; i<n ; i++)
	{
		cin>>a[i];
		
		sum+=a[i];
		dif++;
		
		if(sum<=t)
		maxx=max(maxx,dif);
		else
		{
			while(sum>t	&& j<=i)
			{
				sum-=a[j];
				dif--;	j++;
			}
			
			dif=max(0,dif);
			maxx=max(maxx,dif);
		}
		
	//	cout<<dif<<" "<<maxx<<endl;
	//	cout<<"i="<<i<<"  j="<<j<<endl;
	}
	
	cout<<maxx;
}
