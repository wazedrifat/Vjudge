//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define P pair<int,int>
 
int test,t,i,j,cnt,n;
deque< P > a;
P p;
 
bool compare(P x, P y)
{
    if(x.first<y.first) return true;
    else if(x.first>y.first)    return false;
    else
         if(x.second>=y.second) return true;
         else   return false;
}
 
int main(   )
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
//  freopen("input1.txt","r",stdin);
 
    for(i=1 ; i<=1000 ; i++)
    {
        for(j=1,cnt=0 ; j*j<i ; j++)
        {
            if(i%j==0)
            cnt+=2;
        }
       
        if(j*j==i)
        cnt++;
       
        p.first=cnt;
        p.second=i;
       
        a.push_back(p);
       
    }
   
    sort(a.begin(),a.end(),compare);
   
    cin>>test;
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>n;
 
        printf("Case %d: %d\n",t,a[n-1].second);
    }
}