//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

double n,k;

int main(	)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

//	freopen("input1.txt","r",stdin);
	
	cin>>n>>k;
	
	if((int)n%5==0&&k-n>=0.5)
	printf("%.2lf",k-n-0.5);
	else 	printf("%.2lf",k);

}

