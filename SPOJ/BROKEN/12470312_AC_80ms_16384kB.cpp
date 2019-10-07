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

INT i,j,n,test,sum,cnt,t,ps,l,k,f,maxi;
INT m[1000];
string s;

int main(	)
{
//	READ
	
	while(1)
	{
		memset(m,0,sizeof m);
		
		scanf("%d",&n);
		getchar();
		
		if(n==0)	return 0;
		
		getline(cin,s);
		
		i=0;	j=n;	l=s.length();	maxi=min(l,n);
		
		for(k=0,cnt=0 ; k<l && cnt<n ; k++)		
		{
			if(m[ s[k]-'\0' ]==0)	cnt++;
			
			m[ s[k]-'\0' ]++;
		}
		
		j=k;	maxi=max(maxi,j-i);
	//	cout<<"k="<<k<<endl;
		while(j<l)
		{
			if(m[ s[j]-'\0' ]==0)
			{
				while(i<l && --m[ s[i]-'\0' ]!=0)	i++;
				i++;
			}
			
			m[ s[j]-'\0' ]++;
			j++;
			
//			cout<<"i="<<i<<" j="<<j<<" dif="<<j-i<<" ";
//			for(k=i ; k<j ; k++)	cout<<s[k];
//			cout<<endl;
			
			maxi=max(maxi,j-i);
		}
		
		cout<<maxi<<endl;
	}
}
