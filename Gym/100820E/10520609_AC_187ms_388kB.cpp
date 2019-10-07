#include<bits\stdc++.h>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);

    int len = n /2 ,id = 1,res = 20000000;
    for(i=0;i<len;i++){
        int df = a[i] + a[n-id];
        //cout<<df<<endl;
        if(df < res ){
            res = df;
        }
        id++;
    }
    cout<<res<<endl;

}
