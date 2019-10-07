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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,f,a[100000],q;

INT BS(INT xx)
{
	INT ll=0,rr=n-1;
	
    while (ll<=rr)
    {
        INT mm=ll+(rr-ll)/2;

        if (a[mm]==xx)	return mm;
		else if (a[mm]<xx)	ll=mm+1;
		else	rr=mm-1;
    }

    return -1;
}

int main(	)
{
	for(t=1 ; cin>>n>>q && n && q ; t++)
	{
		
		for(i=0 ; i<n ; i++)
		cin>>a[i];
		
		sort(a,a+n);
		
		printf("CASE# %d:\n",t);
		
		for(i=0 ; i<q ; i++)
		{
			cin>>m;
			
			k=BS(m);
			
			while(k>0 && a[k-1]==m)	k--;
			
			if(k>=0)
			cout<<m<<" found at "<<k+1<<endl;
			else
			cout<<m<<" not found"<<endl;
		}
	}
}
