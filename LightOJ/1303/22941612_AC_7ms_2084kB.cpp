#include<bits/stdc++.h>
using namespace std;
 
int main(   )
{
    int test,visit[25][25],f[25],done[25];
    vector<int>v;
   
    cin>>test;
 
    for(int t=1 ; t<=test ; t++)
    {      
        int n,m;
        cin>>n>>m;
       
        cout<<"Case "<<t<<": ";
       
        v.clear();
        memset(visit, 0, sizeof visit);
        memset(f, 0, sizeof f);
        memset(done, 0, sizeof done);
       
        int b=n*m,cnt=0;
       
        for(int i=1 ; i<=n ; i++)
        v.push_back(i);
//      cout<<"b="<<b<<endl;
        for(int i=0 ; b ; i=(i+1)%m,cnt++)
        {
//          cout<<"i="<<i<<" cnt="<<cnt<<endl;
            if(f[i])
            {
                done[ f[i] ]++;
                b--;
               
                if(done[ f[i] ]<m )
                v.push_back( f[i] );
                f[i]=0;
            }
            for(int j=0 ; j<v.size() ; j++)
            if(visit[i][ v[j] ]==0)
            {
//              cout<<"b="<<b<<" i="<<i<<" v[j]="<<v[j]<<endl;
                f[i]=v[j];
                visit[i][ v[j] ]=1;
                v.erase(v.begin()+j);
                break;
            }
           
//          cout<<b<<endl;
//          cout<<"vector : ";
//          for(int i=0 ; i<v.size() ; i++)
//          cout<<v[i]<<" ";
//          cout<<endl;
        }
       
        cout<<cnt*5<<endl;
    }
 
}