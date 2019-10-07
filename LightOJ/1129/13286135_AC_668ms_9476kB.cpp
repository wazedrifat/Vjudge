#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    bool end;
    node *next[15];
   
    node()
    {
        end=0;
        for(int i=0 ; i<10 ; i++)
        next[i]=NULL;
    }
};
 
class trie
{
public:
    node *root;
    bool ch;
   
    trie()
    {
        root=new node();
        ch=0;
    }
   
    void Insert(string s)
    {
        node *cur=root;
       
        for(int i=0 ; i<s.length() ; i++)
        {
            int id=s[i]-'0';
           
            if(cur->next[id]==NULL)
            cur->next[id]=new node();
           
            cur=cur->next[id];
           
            if(cur->end)
            ch=1;
        }
       
        cur->end=1;
       
        for(int i=0 ; !ch && i<10 ; i++)
        if(cur->next[i]!=NULL)
        ch=1;
    }
   
    void del(node *cur)
    {
        for(int i=0 ; i<10 ; i++)
        if(cur->next[i]!=NULL)
            del(cur->next[i]);
           
        delete(cur);
    }
};
 
 
int main(   )
{
    int test;
    cin>>test;
   
    for(int t=1 ; t<=test ; t++)
    {
        trie tr;
        int n;
        cin>>n;
       
        while(n--)
        {
            string s;
            cin>>s;
           
            tr.Insert(s);
        }
       
        cout<<"Case "<<t<<": ";
       
        if(tr.ch)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
       
        tr.del(tr.root);
    }
 
}