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

INT i,j,n,m,test,sum,cnt,t,ps,l,k;
char a[35],c1,c2;
string s;

int main(	)
{
	scanf("%d*c",&t);
	
	while(t--)
	{
		for(i=0 ; i<26 ; i++)
		a[i]=i+'A';
		
		a[30]='_';
		
		cin>>s;
		
		cin>>n;
		
		while(n--)
		{
			cin>>c1>>c2;
			
		//	a[c2-'A']=c1;
			
			for(i=0 ; i<26 ; i++)
			if(a[i]==c2)	a[i]=c1;
		}
		
		for(i=0,l=s.length() ; i<l ; i++)
		printf("%c",a[s[i]-'A']);
		
		cout<<endl;
	}
}
