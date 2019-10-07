#include<bits/stdc++.h>
using namespace std;
 
#define MX 100000
 
int a[MX],st[5*MX];
 
void create(int low, int high, int pos)
{
    if(low==high)
    {
        st[pos]=a[low];
        return;
    }
   
    int mid=(low+high)/2;
   
    create(low, mid, 2*pos+1);
    create(mid+1, high, 2*pos+2);
   
//  cout<<"pos="<<pos<<" left="<<st[2*pos+1]<<" right="<<st[2*pos+2]<<endl;
//  cout<<"low="<<low<<" high="<<high<<endl;
   
    st[pos]=min(st[ 2*pos+1 ], st[ 2*pos+2 ]);
}
 
int mq(int qlow, int qhigh, int low, int high, int pos)
{
//  cout<<"low="<<low<<" high="<<high<<" pos="<<pos<<endl;
   
    if(qlow<=low && qhigh>=high)
    return st[pos];
    else if(qhigh<low || qlow>high)
    return INT_MAX;
   
    int mid=(low+high)/2;
   
//  cout<<"else"<<endl;
   
    int p=mq(qlow, qhigh, low, mid, 2*pos+1);
    int r=mq(qlow, qhigh, mid+1, high, 2*pos+2);
   
//  cout<<"low="<<low<<" high="<<high<<" p="<<p<<" r="<<r<<endl;
    return min(p,r);
}
 
int main(   )
{
    int test;
    scanf("%d",&test);
   
    for(int t=1 ; t<=test ; t++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
       
        for(int i=0 ; i<n ; i++)
        scanf("%d",&a[i]);
       
        create(0, n-1, 0);
       
//      for(int i=0 ; i<15 ; i++)
//      cout<<st[i]<<" ";
//      cout<<endl;
       
        printf("Case %d:\n",t);
       
        for(int i=0 ; i<q ; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
           
            printf("%d\n",mq(x-1, y-1, 0, n-1, 0));
        }
    }
}