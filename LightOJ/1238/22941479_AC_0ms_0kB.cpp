#include<bits/stdc++.h>
using namespace std;
 
#define PII pair<int, int>
 
map<PII, int>mp;
int n, m;
char p[30][30];
 
int bfs(PII s, PII d)
{
    queue<PII>Q;
    mp.clear();
 
    Q.push(s);
    mp[s]=0;
 
    while(!Q.empty())
    {
        PII u=Q.front();
        Q.pop();
        int i=u.first, j=u.second, k=mp[u];
 
//      cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
        if(u==d)    return mp[d];
 
        if(i>0 && p[i-1][j]!='#' && p[i-1][j]!='m' && mp.find( PII(i-1, j) )==mp.end() )
        {
            mp[ PII(i-1, j) ]=k+1;
            Q.push( PII(i-1, j) );
        }
        if(i<n-1 && p[i+1][j]!='#' && p[i+1][j]!='m' && mp.find( PII(i+1, j) )==mp.end() )
        {
            mp[ PII(i+1, j) ]=k+1;
            Q.push( PII(i+1, j) );
        }
        if(j>0 && p[i][j-1]!='#' && p[i][j-1]!='m' && mp.find( PII(i, j-1) )==mp.end() )
        {
            mp[ PII(i, j-1) ]=k+1;
            Q.push( PII(i, j-1) );
        }
        if(j<m-1 && p[i][j+1]!='#' && p[i][j+1]!='m' && mp.find( PII(i, j+1) )==mp.end() )
        {
            mp[ PII(i, j+1) ]=k+1;
            Q.push( PII(i, j+1) );
        }
    }
    return mp[d];
}
 
int main()
{
//  freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
 
    for(int t=1 ; t<=test ; t++)
    {
        cin>>n>>m;
 
        PII a, b, c, h;
        for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
        {
            cin>>p[i][j];
            if(p[i][j]=='a')
                a=PII(i, j);
            else if(p[i][j]=='b')
                b=PII(i, j);
            else if(p[i][j]=='c')
                c=PII(i, j);
            else if(p[i][j]=='h')
                h=PII(i, j);
        }
 
//      cout<<"a="<<bfs(a, h)<<" b="<<bfs(b, h)<<" c="<<bfs(c, h)<<endl;
        int res=max( bfs(a, h) , bfs(b, h) );
        res=max( res , bfs(c, h) );
 
        cout<<"Case "<<t<<": "<<res<<endl;
    }
}
 