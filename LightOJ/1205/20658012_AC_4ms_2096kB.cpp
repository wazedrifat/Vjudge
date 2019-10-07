#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
ll a, b, dp[20][20][2][2];
int A[20], dig[20], h1, h2, lim;
 
int digit(ll z, int arr[])
{
    memset(arr, 0, sizeof arr);
    if(!z)  return 1;
 
    int i=0;
    while(z)
    {
        arr[i++]=z%10;
        z/=10;
    }
    return i;
}
 
ll rec(int pos, int len, int pal=1, int high=1)
{
    if(pos<0 || (!pal && pos<(len+1)/2 ) )  return pal;
    if(dp[pos][len][pal][high]!=-1) return dp[pos][len][pal][high];
 
    ll cnt=0;
    int hi=high?    A[pos] : 9;
 
    for(int i=0 ; i<=hi ; i++)
    {
        dig[pos]=i;
 
        if(len==pos && !i)
            cnt+=rec(pos-1, len-1, pal, high&(i==hi));
        else if(pal && pos<(len+1)/2)
            cnt+=rec(pos-1, len, (dig[len-pos]==i), high&(i==hi));
        else if(pos>=(len+1)/2)
            cnt+=rec(pos-1, len, pal, high&(i==hi));
    }
    return dp[pos][len][pal][high]=cnt;
}
 
int main()
{
    int test;
    cin>>test;
 
    for(int t=1 ; t<=test ; t++)
    {
        memset(dp, -1, sizeof dp);
 
        ll x, y;
        cin>>x>>y;
        if(x>y) swap(x, y);
 
        ll res1=0;
        int h=0;
        if(x)
        {
            a=x-1;
            h=digit(a, A);
            res1=rec(h-1, h-1);
        }
 
        memset(dp, -1, sizeof dp);
        a=y;
        h=digit(y, A);
        ll res2=rec(h-1, h-1);
 
        ll res=res2-res1;
        cout<<"Case "<<t<<": "<<res<<endl;
    }
}