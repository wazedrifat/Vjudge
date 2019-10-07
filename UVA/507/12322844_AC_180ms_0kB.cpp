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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,a[20001],maxi;
PII ans;

PII MS(	)
{
	INT	s=0;
	PII answer;
	maxi=INT_MIN;
	
	for(INT ii=0,l=0 ; ii<n ; ii++)
	{
		s+=a[ii];
		
		if(maxi<s)
		{
			maxi=s;	
			answer.first=l;
//			cout<<"1/maxi="<<maxi<<"  sum="<<s<<"  low="<<answer.first<<"  high="<<answer.second<<endl;
			answer.second=ii;
		}
		else if(maxi==s)
		{
			if( (ii-l==answer.second-answer.first && l<answer.first) || ii-l>answer.second-answer.first )
			{
				answer.first=l;
				answer.second=ii;
			}
		}
		
		if(s<0)
		{
			s=0;
			l=ii+1;
//			cout<<"2/maxi="<<maxi<<"  sum="<<s<<"  low="<<answer.first<<"  high="<<answer.second<<endl;
		}
	}
	
//	cout<<answer.first<<"	"<<answer.second<<endl;
	
	return answer;
}

int main(	)
{
//	READ
	
	cin>>test;
	
	for(t=1 ; t<=test ; t++)
	{
		cin>>n;
		n--;
		
		for(i=0 ; i<n ; i++)	cin>>a[i];
		
		ans=MS();
		
//		cout<<ans.first<<"	"<<ans.second;
		
		if(maxi>=0)
		printf("The nicest part of route %d is between stops %d and %d\n",t,ans.first+1,ans.second+2);
		else
		printf("Route %d has no nice parts\n",t);
	}
}
