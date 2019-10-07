//wazed rifat
#include<bits/stdc++.h>
using namespace std;
long long int i,sa=0,sg=0,a,n,g,f=0,temp;
string s;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>a>>g;
		//cout<<endl<<sa<<"	"<<sg<<"	"<<sa+a-sg<<"	"<<sg+g-sa<<endl;
		if((a<=g&&abs(sa+a-sg)>500)||(g<=a)&&abs(sg+g-sa)>500)
		{
			//cout<<"1.test";
			if((g<=a)&&abs(sg+g-sa)>500)
			{
				//cout<<"2.test";
				sa+=a;
				s+="A";
			}
			else if(a<=g&&abs(sa+a-sg)>500)
			{
				//cout<<"3.test";
				sg+=g;
				s+="G";
			}
			f=1;
		}
		if(a<g&&f==0)
		{
			sa+=a;
			s+="A";
		}
		else if(g<a&&f==0)
		{
			sg+=g;
			s+="G";
		}
		else if(a==g&&f==0)
		{
			if(sa<=sg)
			{
				sa+=a;
				s+="A";
			}
			else
			{
				sg+=g;
				s+="G";
			}
		}
		f=0;
		//cout<<sa<<"	"<<sg<<endl<<endl;
		temp=min(sa,sg);
		sa-=temp;
		sg-=temp;
		//cout<<sa<<"	"<<sg<<endl<<endl;
	}
	if(abs(sa-sg)>500)
	cout<<-1;
	else
	cout<<s;
}
