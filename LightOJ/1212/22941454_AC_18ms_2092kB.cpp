#include<bits/stdc++.h>
using namespace std;
 
int main(   )
{
    int test;
    cin>>test;
   
    for(int t=1 ; t<=test ; t++)
    {
        int n,m;
        cin>>n>>m;
       
        deque<int>d;
       
        cout<<"Case "<<t<<":\n";
       
        while(m--)
        {
            string s;
            int v;
           
            cin>>s;
           
            if(s=="pushLeft")
            {
                cin>>v;
               
                if(d.size()<n)
                {
                    d.push_front(v);
                    cout<<"Pushed in left: "<<v;
                }
                else cout<<"The queue is full";
            }
            else if(s=="pushRight")
            {
                cin>>v;
                if(d.size()<n)
                {
                    d.push_back(v);
                    cout<<"Pushed in right: "<<v;
                }
                else cout<<"The queue is full";
            }
            else if(s=="popLeft")
            {
                if(d.size())
                {
                    cout<<"Popped from left: "<<d[0];
                    d.pop_front();
                }
                else    cout<<"The queue is empty";
            }
            else if(s=="popRight")
            {
                if(d.size())
                {
                    cout<<"Popped from right: "<<d[ d.size()-1 ];
                    d.pop_back();
                }
                else    cout<<"The queue is empty";
            }
           
            cout<<endl;
        }
    }
}