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

INT i,j,m,test,cnt,t,ps,l,k,f;
string str,sum1,sum2,n;
vector<string>v;
char ch[100],c;

string add(string s1,string s2)
{
	stringstream ss(s1);
	INT N,M;
	ss>>N;
	stringstream sss(s2);
	sss>>M;
	stringstream s;
	s<<N+M;
	string strr;
	s>>strr;
	return strr;
}

string mult(string s1,string s2)
{
	stringstream ss(s1);
	INT N,M;
	ss>>N;
	stringstream sss(s2);
	sss>>M;
	stringstream s;
	s<<N*M;
	string strr;
	s>>strr;
	return strr;
}

int main(	)
{
	while(scanf("%s",ch)!=EOF)
	{
		string s=ch;
		cin>>n;
		
		v.clear();
		
		for(i=0,l=s.length(),f=0,k=-1,sum1="0",sum2="0" ; i<l ; i++)
		{
			
			str="";
			
			while( (s[i]!='*' && s[i]!='+') && i<l)
			str+=s[i++];
			
	//		cout<<"str="<<str<<endl;
			
			if(f)
			{
	//			cout<<"k="<<k<<"	c="<<c<<"	sum1="<<sum1<<endl;
				if(c=='*')
				{
					
	//				cout<<"mult="<<mult(str,sum1)<<endl;
					sum1=mult(str,sum1);
				}
				else
				{
	//				cout<<"add="<<add(str,sum1)<<endl;
					sum1=add(str,sum1);
				}
			}
			else	sum1=str;
			
//			if(c=='*' && f)
//			cout<<v[k]<<"	"<<mult(str,v[k]);
			
			if(c=='*' && f)	v[k]=mult(str,v[k]);
			else
			{
				v.push_back(str);
				k++;
			}
			
			if(i>=l)	break;
					
			c=s[i];			
			f=1;
		}
		
		
		for(i=0,l=v.size() ; i<l ; i++)
		sum2=add(sum2,v[i]);
		
	//	cout<<"sum1="<<sum1<<"	sum2="<<sum2<<endl;
		
		if(n==sum1 && n==sum2)
		cout<<"U"<<endl;
		else if(n==sum1)
		cout<<"L"<<endl;
		else if(n==sum2)
		cout<<"M"<<endl;
		else
		cout<<"I"<<endl;
	}
}
