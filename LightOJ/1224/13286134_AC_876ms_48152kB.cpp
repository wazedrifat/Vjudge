#include<bits/stdc++.h>
using namespace std;
 
#define MX 5
 
struct node
{
    int end;
    node *next[MX];
   
    node()
    {
        end=0;
        for(int i=0 ; i<MX ; i++)
        next[i]=NULL;
    }
};
 
class trie
{
public:
    node *root;
    int val;
   
    trie()
    {
        root=new node();
        val=0;
    }
   
    void Insert(string s)
    {
        node *cur=root;
       
        for(int i=0 ; i<s.length() ; i++)
        {
            int id=4;
           
            if(s[i]=='A')       id=0;
            else if(s[i]=='C')  id=1;
            else if(s[i]=='G')  id=2;
            else if(s[i]=='T')  id=3;
           
            if(cur->next[id]==NULL)
            cur->next[id]=new node();
           
            cur=cur->next[id];
            cur->end++;
           
            if(cur->end*(i+1)>val)
            val=cur->end*(i+1);
        }
    }
   
    void del(node *cur)
    {
        for(int i=0 ; i<MX ; i++)
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
        tr.val=0;
        int n;
        cin>>n;
       
        while(n--)
        {
            string s;
            cin>>s;
           
            tr.Insert(s);
        }
       
        cout<<"Case "<<t<<": "<<tr.val<<endl;
       
        tr.del(tr.root);
    }
 
}