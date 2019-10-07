#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, skill = 10, ques = 10;
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        skill = min(skill, m);
    }

    for(int i = 0; i < 10; i++)
    {
        int m;
        cin >> m;

        ques = min(ques, m);
    }

    if(skill < ques)
        cout<<skill;
    else
        cout<<10;
}
