//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define	INT			double
#define PII			pair<INT,INT>
#define FOR(A,B,C)	for(int A=B ; A<=C ; A++)
#define SCN(N)		INT N;	scanf("%lf",&N);
#define SN(N)		scanf("%d",&N);
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
#define EPS			1e-6

int main(	)
{
    int t;
    SN(t)

    while(t--)
    {
        SCN(u)SCN(k1)SCN(k2)

        INT l=0.0,r=PI,maxi=-1.0,alpha=-1.0;

        int cnt=100;
        while(cnt--)
        {
            INT a1=(2*l+r)/3.0;
            INT x1=(u*u*sin(2*a1))/10.0;
            INT y1=(u*u*sin(a1)*sin(a1))/20.0;
            INT sum1=k1*x1+k2*y1;
            if(sum1>maxi+EPS)
            {
                maxi=sum1;   alpha=a1;
            }

            INT a2=(l+2*r)/3.0;
            INT x2=(u*u*sin(2*a2))/10.0;
            INT y2=(u*u*sin(a2)*sin(a2))/20.0;
            INT sum2=k1*x2+k2*y2;
            if(sum2>maxi+EPS)
            {
                maxi=sum2;   alpha=a2;
            }

      //      cout<<"sum1="<<sum1<<" sum2="<<sum2<<endl;

            if(sum1+EPS<sum2)   l=a1;
            else    r=a2;
        }

        printf("%.3f %.3f\n",alpha,maxi);
    }
}
