#include<bits/stdc++.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
using namespace std;
int t,i,j,k,n,m,a=0,b,c=0;
char s[15];
int main()
{
	cin>>t;
	for(k=0;k<t;k++)
	{
		cin>>s;
		if(strcmp(s,"Alice")==0||strcmp(s,"Ariel")==0||strcmp(s,"Aurora")==0||strcmp(s,"Phil")==0||strcmp(s,"Peter")==0||strcmp(s,"Olaf")==0||strcmp(s,"Phoebus")==0||strcmp(s,"Ralph")==0||strcmp(s,"Robin")==0)
		b=0;
		else if(strcmp(s,"Bambi")==0||strcmp(s,"Belle")==0||strcmp(s,"Bolt")==0||strcmp(s,"Mulan")==0||strcmp(s,"Mowgli")==0||strcmp(s,"Mickey")==0||strcmp(s,"Silver")==0||strcmp(s,"Simba")==0||strcmp(s,"Stitch")==0)
		b=1;
		else if(strcmp(s,"Dumbo")==0||strcmp(s,"Genie")==0||strcmp(s,"Jiminy")==0||strcmp(s,"Kuzko")==0||strcmp(s,"Kida")==0||strcmp(s,"Kenai")==0||strcmp(s,"Tarzan")==0||strcmp(s,"Tiana")==0||strcmp(s,"Winnie")==0)
		b=2;
		if(a>=b)
		c+=a-b;
		else
		c+=b-a;
		a=b;
	}
	cout<<c;
}
