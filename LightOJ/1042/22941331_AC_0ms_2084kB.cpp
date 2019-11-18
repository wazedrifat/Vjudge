#include<bits/stdc++.h>
using namespace std;
 
int next_popcount(int n)
{
    int c = (n & -n);
    int r = n+c;
    return (((r ^ n) >> 2) / c) | r;
}
 
int main()
{
    int test;
    scanf("%d", &test);
   
    for(int t=1 ; t<=test ; t++)
    {
        int n, m, ans;
        scanf("%d", &n);
       
        n=next_popcount(n);
       
        printf("Case %d: %d\n", t, n);
    }
}
 