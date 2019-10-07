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

INT t,f,i,l;
string s;

int main(	)
{
	cin>>t;
	
	while(t--)
	{
		cin>>s;
		
		for(i=0,l=s.length(),f=0 ; i<l ; i++)
		if(s[i]=='D')
		{
			cout<<"You shall not pass!"<<endl;
			f=1;
			break;
		}
		
		if(f==0)
		cout<<"Possible"<<endl;
	}
	
}