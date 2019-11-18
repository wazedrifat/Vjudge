
#include<bits/stdc++.h>
using namespace std;
 
#define LLI long long int
 
int i,j,test,sum,t,l1,l2,f,a[27],b[27],cnt1,cnt2;
string s1,s2;
 
int is( char ch)
{
    if(ch>='A'&&ch<='Z')    return 1;
    else if(ch>='a'&&ch<='z') return 2;
    else return 0;
}
 
int main(   )
{
    scanf("%d",&test);
    getchar();
   
    for(t=1 ; t<=test ; t++)
    {
        for(i=0 ; i<26 ; i++)
        a[i]=b[i]=0;
       
        getline(cin,s1);
        getline(cin,s2);
       
        l1=s1.length();
        l2=s2.length();
               
//      cout<<"s1("<<s1.length()<<")="<<s1<<endl<<"s2("<<s2.length()<<")="<<s2<<endl;
 
        for(i=0 ; i<l1 ; i++)
        {
            char c=s1[i];
           
            if(is(c)==1)    a[c-'A']++;
            else if(is(c)==2)   a[c-'a']++;
        }
       
        for(i=0 ; i<l2 ; i++)
        {
            char c=s2[i];
           
            if(is(c)==1)    b[c-'A']++;
            else if(is(c)==2)   b[c-'a']++;
        }
       
        for(i=0,cnt1=0 ; i<26 ; i++)
        if(a[i]==b[i])
            cnt1++;
       
        if(cnt1==26)
        printf("Case %d: Yes\n",t);
        else
        printf("Case %d: No\n",t);
    }
   
}
 
 