#include<bits/stdc++.h>
using namespace std;
 
int main(   )
{
    int test;
    cin>>test;
   
    for(int t=1 ; t<=test ; t++)
    {
        stack<string>s,s1;
        string str;
       
        s.push("http://www.lightoj.com/");
       
        cout<<"Case "<<t<<":\n";
       
        while(cin>>str && str!="QUIT")
        {
            if(str=="VISIT")
            {
                cin>>str;
                s.push(str);
                cout<<str<<endl;
               
                while(s1.size())
                s1.pop();
            }
            else if(str=="BACK")
            {
                if(s.size()<=1)
                cout<<"Ignored"<<endl;
                else
                {
                    s1.push(s.top());
                    s.pop();
                    cout<<s.top()<<endl;
                }
            }
            else if(str=="FORWARD")
            {
//              cout<<"s1 is : "<<s1.size()<<"    "<<s1.top()<<endl;
                if(!s1.size())
                cout<<"Ignored"<<endl;
                else
                {
                    cout<<s1.top()<<endl;
                    s.push(s1.top());
                    s1.pop();
//                  if(s1.size())
//                  cout<<"next is : "<<s1.top()<<endl;
                }
            }
        }
    }
}
 