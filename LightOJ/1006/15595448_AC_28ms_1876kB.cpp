#include<iostream>
#include<vector>
using namespace std;
long long int a,b,c,d,e,f,n;
vector<long long int> arr(10005,-1);

long long int fn(int n)
{
    if(n==0)return a;
    if(n==1)return b;
    if(n==2)return c;
    if(n==3)return d;
    if(n==4)return e;
    if(n==5)return f;
    if(arr[n]!=-1)return arr[n];
    else return arr[n]=(fn(n-1)+fn(n-2)+fn(n-3)+fn(n-4)+fn(n-5)+fn(n-6))%10000007;


}
int main()
{
    int n,caseno=0,cases;
    cin>>cases;
    while(cases--)
    {
        cin>>a>>b>>c>>d>>e>>f>>n;
        arr.clear();
        arr.resize(10005,-1);
        cout<<"Case "<<++caseno<<": "<<fn(n)%10000007<<endl;
    }

}
