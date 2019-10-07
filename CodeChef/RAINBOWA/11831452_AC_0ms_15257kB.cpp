//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

int i,j,n,test,sum,ans,cnt,t,k,f,x,m;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
	
		int a[8]={0};
		
		for(i=0,f=1,m=0 ; i<n ; i++)
		{
			cin>>x;
			
			if(x<1||x>7)
			m=2;
			
			if(x==f&&m==0)
			{
//				cout<<a[x];
				a[x]++;
//				cout<<"1st"<<a[x]<<endl;
			}
			else if(x==f&&m==1)
			{	
//				cout<<a[x];			
				a[x]--;
//				cout<<"2nd"<<a[x]<<endl;
			}
			else if(x==f+1&&m==0)
			{
//				cout<<a[x];
				f++;
				a[x]++;
//				cout<<"3rd"<<a[x]<<endl;
			}
			else if(x==f-1&&m==0)
			{
				m=1;
				
				if(f!=7)	m=2;
				
//				cout<<a[x];
				a[x]--;
				f--;
//				cout<<"4th"<<a[x]<<endl;
			}
			else if(x==f-1&&m==1)
			{
//				if(a[x+1]!=0&&x+1!=k)	m=2;
				
//				cout<<a[x];
				a[x]--;
				f--;
//				cout<<"5th"<<a[x]<<endl;
			}
			else
			{
				m=2;
//				cout<<"6th"<<a[x]<<endl;
			}
		}
		
//		cout<<"x="<<x<<"	f="<<f<<"	m="<<m<<endl;
		
		for(i=1 ; i<=6&&m!=2 ; i++)
		if(a[i]!=0)	m=2;
		
		a[7]=0;
		
//		for(i=1 ; i<=7 ; i++)
//		cout<<i<<":"<<a[i]<<"	";
//		cout<<endl<<endl;
		
		if(m==2||x!=1||f!=1)	cout<<"no";
		else cout<<"yes";
		
//		if(t)
		cout<<endl;
		
//		for(i=1 ; i<=7 ; i++)
//		cout<<i<<":"<<a[i]<<"	";
//		cout<<endl;
	}
	
}

