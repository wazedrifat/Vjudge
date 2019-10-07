#include<bits/stdc++.h>
using namespace std;

#define MX 200005

string s;

int main()
{
    int n, st, en;
    scanf("%d %d %d", &n, &st, &en);
    st--;	en--;

    cin>>s;
	
	cout<<(s[st]!=s[en]);
}
