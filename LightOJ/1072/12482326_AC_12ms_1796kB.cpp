//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define MIN3(A,B,C) min(A , min(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT test,t;
double R,n,k;

int main(	)
{
	cin>>test;
	
	for(t=1 ; t<=test ; t++)
	{
		cin>>R>>n;
		
		k=sin(PI/n);
		
		printf("Case %d: %.7f\n",t,R*k/(k+1.0));
	}
}