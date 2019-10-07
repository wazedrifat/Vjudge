//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define	INT			int
#define PII			pair<INT,INT>
#define FOR(A,B,C)	for(int A=B ; A<=C ; A++)
#define SI(N)		INT N;	scanf("%d",&N);
#define SD(N)		double N;	scanf("%lf",&N);
#define SC(N)		scanf("%d",&N);
#define PTC(A)		printf("Case %d: %d\n",t,A);
#define PT(A)		printf("%d\n",A);
#define ALL(V)		V.begin(),V.end()
#define MS(ARR,VAL) memset(ARR,VAL,sizeof ARR);
#define PB(VEC,VAL)	VEC.push_back(VAL);
#define MAX3(A,B,C)	max(A , max(B , C) )
#define MIN3(A,B,C)	min(A , min(B , C) )
#define PI			2.0*acos(0.0)
#define READ		freopen("input1.txt","r",stdin);
#define boost		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS			1e-9

INT n;
vector<INT>v[200];

bool bfs()
{
    queue<INT>q;
    vector<INT>c(n,1e9);

    q.push(0);
    c[0]=0;

    while(!q.empty())
    {
        INT u=q.front();    q.pop();
        FOR(i,0,v[u].size()-1)
        {
            INT t=v[u][i];

            if(c[t]==c[u])  return 1;
            else if(c[t]==1e9)
            {
                c[t]=1-c[u];
                q.push(t);
            }
        }
    }
    return 0;
}

int main(	)
{
  //  READ
    while(cin>>n && n)
    {
        FOR(i,0,n)  v[i].clear();

        SI(l)

        FOR(i,0,l-1)
        {
            SI(a)   SI(b)
            PB(v[a],b)  PB(v[b],a)
        }

        if(bfs())  cout<<"NOT BICOLORABLE."<<endl;
        else    cout<<"BICOLORABLE."<<endl;
    }
}
