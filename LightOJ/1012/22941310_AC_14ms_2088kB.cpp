#include<bits/stdc++.h>
using namespace std;
 
#define PII pair<int, int>
 
map<PII, bool>mp;
int n, m;
char p[30][30];
 
int dfs(int i, int j)
{
    mp[ PII(i, j) ]=1;
 
//  cout<<"i="<<i<<" j="<<j<<endl;
    int cnt=1;
    if(i>0 && p[i-1][j]=='.' && mp.find( PII(i-1, j) )==mp.end() )      cnt+=dfs(i-1, j);
    if(i<n-1 && p[i+1][j]=='.' && mp.find( PII(i+1, j) )==mp.end() )    cnt+=dfs(i+1, j);
    if(j>0 && p[i][j-1]=='.' && mp.find( PII(i, j-1) )==mp.end() )      cnt+=dfs(i, j-1);
    if(j<m-1 && p[i][j+1]=='.' && mp.find( PII(i, j+1) )==mp.end() )    cnt+=dfs(i, j+1);
 
    return cnt;
}
 
int main()
{
    int test;
    cin>>test;
 
    for(int t=1 ; t<=test ; t++)
    {
        mp.clear();
        cin>>m>>n;
 
        int sx=0, sy=0;
        for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
        {
            cin>>p[i][j];
            if(p[i][j]=='@')
            {
                sx=i;   sy=j;
            }
        }
 
        cout<<"Case "<<t<<": "<<dfs(sx, sy)<<endl;
    }
}
 