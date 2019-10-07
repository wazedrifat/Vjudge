#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;

	map<string, string>str;

	for(int i=0 ; i<m ; i++)
    {
        char c1[15], c2[15];
        scanf("%s%s", c1, c2);

        string s1=c1, s2=c2;

        if(s2.length()<s1.length())
            str[s1]=s2;
        else
            str[s1]=s1;
    }

    for(int i=0 ; i<n ; i++)
    {
        char c[100];
        scanf("%s", c);
        string s=c;
        cout<<str[s]<<" ";
    }
}
