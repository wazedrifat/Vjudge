//wazed rifat
 
#include<bits/stdc++.h>
using namespace std;
 
#define INT int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<TYP,TYP>
#define READ freopen("input1.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;
 
INT i,j,n,m,test,sum,cnt,t,ps,l1,l2,dp[105][105];
string s1,s2,str[101][101];
 
int main(   )
{
//  READ
    scanf("%d*%c",&test);
   
    for(t=1 ; t<=test ; t++)
    {
        cin>>s1>>s2;
       
    //  cout<<s1<<" "<<s2<<endl;
       
        printf("Case %lld: ",t);
       
        memset(dp,0,sizeof dp);
        for(i=0,l1=s1.size() ; i<l1 ; i++)  str[i][0]="";
        for(i=0,l2=s2.size() ; i<l2 ; i++)  str[0][i]="";
       
        for(i=1 ; i<=l1 ; i++)
        for(j=1 ; j<=l2 ; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                str[i][j]=str[i-1][j-1]+s1[i-1];
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    str[i][j]=str[i-1][j];
                }
                else if(dp[i][j-1]>dp[i-1][j])
                {
                    dp[i][j]=dp[i][j-1];
                    str[i][j]=str[i][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    str[i][j]=min(str[i-1][j],str[i][j-1]);
                }
            }
        }
       
        if(dp[l1][l2])
        cout<<str[l1][l2]<<endl;
        else
        cout<<":("<<endl;
    }
}