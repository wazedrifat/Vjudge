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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,x,y,a[10001];

int main(	)
{
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0 ; i<n ; i++)	cin>>a[i];
		
		sort(a,a+n);
		
		cin>>m;
		
		x=i=0;	y=j=n-1;
		while(i<j)
		{
			while(a[i]+a[j]>m)	j--;
			
			if(a[i]+a[j]==m)
			{
				x=i;	y=j;
			}
			i++;
		}
		
		printf("Peter should buy books whose prices are %d and %d.\n\n",a[x],a[y]);
	}
}
