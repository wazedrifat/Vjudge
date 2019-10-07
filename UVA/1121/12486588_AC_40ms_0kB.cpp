//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX3(A,B,C) max(A , max(B , C) )
#define MIN3(A,B,C) min(A , min(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,s,a[100000],mini;

int main(	)
{
//	READ
	while(scanf("%d%d",&n,&s)!=EOF)
	{
		for(i=0,j=0,mini=INT_MAX,sum=0 ; i<n ; i++)
		{
			cin>>a[i];
			
			sum+=a[i];
			
			while(j<i && sum-a[j]>=s)
			{
				sum-=a[j];
				j++;
			}
			
			if(sum>=s)
			mini=min(mini,i-j+1);
			
		//	cout<<"sum="<<sum<<" min="<<mini<<endl;
		}
		
		if(mini==INT_MAX)	cout<<0<<endl;
		else	cout<<mini<<endl;
	}
}
