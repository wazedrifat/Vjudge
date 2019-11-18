#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

PII p[200005];

int main()
{
    int q, i=0, j=0;
    cin>>q;

    while(q--)
    {
        char ch;
        int id;
        cin>>ch>>id;

        if(ch=='L')
        {
            p[id]=PII(i, -i);
            if(!i && !j)    j++;
            i++;
//            cout<<"id="<<id<<" l="<<p[id].first<<" r="<<p[id].second<<endl;
        }
        else if(ch=='R')
        {
            p[id]=PII(-j, j);
            if(!i && !j)    i++;
            j++;
//            cout<<"id="<<id<<" l="<<p[id].first<<" r="<<p[id].second<<endl;
        }
        else
            cout<<min(j-p[id].second, i-p[id].first)-1<<endl;
    }
}