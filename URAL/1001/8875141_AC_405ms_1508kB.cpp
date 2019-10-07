#include<bits/stdc++.h>
#include<math.h>
#include<vector>
using namespace std;
vector<double>v;
int main()
{
    double a,i=0,j;
    while(scanf("%lf",&a)!=EOF)
    {
    	v.push_back(a);
    }
    for(j=v.size()-1;j>=0;j--)
        printf("%.4lf\n",sqrt(v[j]));
}