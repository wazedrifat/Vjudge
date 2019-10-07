//wazed rifat
#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
int t,i;
int main()
{
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>a>>b>>c>>d;
		printf("Case %d: %.7lf\n",i,(double)pow(d/(d+1),0.50)*a);
		//cout<<"Case 1: "<<(double)pow(d/(d+1),0.50)*a<<endl;
	}
}
