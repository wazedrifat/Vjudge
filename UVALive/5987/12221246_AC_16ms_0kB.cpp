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

INT i,j,n,m,test,sum,cnt,t,ps,l,k,minn;
vector<INT>v;
bool f[100001];
vector<INT>p;

void sieve(INT mm)
{
	f[0]=f[1]=1;
	
	p.push_back(2);
	
	for(INT ii=4 ; ii<=mm ; ii+=2)
	f[ii]=1;
	
	for(INT ii=3 ; ii*ii<mm ; ii+=2)
	if(f[ii]==0)
		for(INT jj=ii*ii ; jj<=mm ; jj+=2*ii)	f[jj]=1;
		
	for(INT ii=3 ; ii<=mm ; ii+=2)
	if(f[ii]==0)	p.push_back(ii);
	
	ps=p.size();
}

int main(	)
{
	sieve(100000);
	
	for(m=30,sum=0 ; sum<=10000 ; m++)
	{
		if(f[m])
		for(i=0,cnt=0,n=m ; n>1 ; i++)
		{
			if(n%p[i]==0)
			{
				while(n%p[i]==0)	n/=p[i];
				
				cnt++;
			}
			
			if(cnt>=3)
			{
				v.push_back(m);
				sum++;
			//	if(sum<100)
			//	cout<<m<<"	";
				break;
			}
		}
	}
	
//	cout<<sum<<"	"<<v[sum-1]<<endl;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		cout<<v[n-1]<<endl;
		
		
	}
}
