#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int test;
    cin>>test;
    long long int dp[10005];
 
    for(int t=1 ; t<=test ; t++)
    {
        for(int i=0 ; i<=5 ; i++)
            cin>>dp[i];
 
        long long int n;
        cin>>n;
 
        for(int i=6 ; i<=n ; i++)
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%10000007;
 
        cout<<"Case "<<t<<": "<<dp[n]%10000007<<endl;
    }
}