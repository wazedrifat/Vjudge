#include<bits\stdc++.h>
using namespace std;
int main()
{
    int i,j;
    char s[250],c[250]="\0";
    cin>>s;
    for(i=0,j=0;i<strlen(s);i++)
    {
        //cout<<"test i"<<i<<endl;
        if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
        {
            i+=2;
            if(j>0&&c[j-1]!=' ')
            {
                c[j]=' ';
                j++;
            }
        }
        else
        {
            c[j]=s[i];
            j++;
        }
    }
    if(c[strlen(c)-1]==' ')
        c[strlen(c)-1]='\0';
    cout<<c;
    //cout<<endl<<strlen(c);
}
