#include<bits/stdc++.h>
using namespace std;
 
#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);
 
int check(int a[], int limit, int res)
{
    int cnt=1, sum=0;
   
    for(int i=0 ; i<limit ; i++)
    {
        if(a[i]>res)          return INT_MAX;
        else if(sum+a[i]<=res)  sum+=a[i];
        else
        {
            sum=a[i];
            cnt++;
        }
    }
    return cnt;
}
 
int main()
{
    int test, a[1005];
    cin>>test;
   
    for(int t=1 ; t<=test ; t++)
    {
        int n, m, sum=0;
        cin>>n>>m;
       
        for(int i=0 ; i<n ; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
       
        int l=0, h=sum, res=h, cnt=100;
        while(cnt--)
        {
            res=(l+h)/2;
           
            if(check(a, n, res)<=m) h=res;
            else    l=res+1;
        }
       
        printf("Case %d: %d\n", t, res);
    }
}