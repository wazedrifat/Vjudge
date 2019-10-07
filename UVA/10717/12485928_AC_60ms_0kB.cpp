//wazed rifat

#include<bits/stdc++.h>
using namespace std;

#define INT long long int
#define MAX 1<<64
#define MAX3(A,B,C) max(A , max(B , C) )
#define MIN3(A,B,C) min(A , min(B , C) )
#define PI 2.0*acos(0.0)
#define PII pair<INT,INT>
#define READ freopen("input1.txt","r",stdin);
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define EPS 1e-9
#define DIS(x1,y1,x2,y2) sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) )

INT i,j,n,m,test,sum,cnt,t,ps,k,f,l,arr[55],maxi,mini;
vector<INT>lcm;

INT LCM(INT a , INT b  , INT c , INT d)
{
	INT L;
	
	L=(a/__gcd(a,b))*b;	//cout<<"L="<<L<<"	";
	L=(L/__gcd(L,c))*c;	//cout<<"L="<<L<<"	";
	L=(L/__gcd(L,d))*d;	//cout<<"L="<<L<<"	";
	
	return L;
}

int main(	)
{
//	READ
	while(1)
	{
		cin>>n>>t;
		
		if(n==0 && t==0)	break;
		
		for(i=0 ; i<n ; i++)	cin>>arr[i];
		
		for(i=0 ; i<n ; i++)
		for(j=i+1 ; j<n ; j++)
		for(k=j+1 ; k<n ; k++)
		for(l=k+1 ; l<n ; l++)
		lcm.push_back(LCM(arr[i],arr[j],arr[k],arr[l]));
		
	//	cout<<"lcm="<<lcm<<endl;
		
		for(j=0 ; j<t ; j++)
		{
			cin>>k;
			
			maxi=LONG_LONG_MIN;	mini=LONG_LONG_MAX;
			for(i=0,l=lcm.size() ; i<l ; i++)
			{
				sum=k/lcm[i];
				
				if(sum*lcm[i]<=k)
				maxi=max(maxi,sum*lcm[i]);
				
				if(sum*lcm[i]<k)	sum++;
				mini=min(mini,sum*lcm[i]);
			}
			
			cout<<maxi<<" "<<mini<<endl;
		}
		
		lcm.clear();
	}
}
