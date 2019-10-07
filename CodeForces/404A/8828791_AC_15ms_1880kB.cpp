#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j=0,k;
	cin>>n;
	char s[n+5],c,d;
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(j==0)
		{
			if(i==0)
		    {
			    c=s[0];
			    d=s[1];
			    if(c==d)
			    {
			    	j=1;
			    	continue;
				}
		    }
		    	if(s[i]!=c||s[n-i-1]!=c)
		        j=1;
		        for(k=0;k<n;k++)
		        {
			        if(k!=i&&k!=n-i-1&&s[k]!=d)
		            {
		        	    j=1;
		        	    break;
		            }
		        }
		}
	}
	if(j==1)
	cout<<"NO";
	else
	cout<<"YES";
}