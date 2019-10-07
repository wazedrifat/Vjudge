#include<bits/stdc++.h>
using namespace std;

int a[105][105], temp[105];

int MS(int arr[], int lim)
{
	int	maxi=INT_MIN,s=0;

	for(int i=0 ; i<lim ; i++)
	{
		maxi=max(maxi,s+arr[i]);
		s=max(0,s+arr[i]);
	}
	return maxi;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	for(int i=0 ; i<n ; i++)
	for(int j=0 ; j<n ; j++)
		scanf("%d", &a[i][j]);

	int maxi=INT_MIN;
	for(int i=0 ; i<n ; i++)
	{
		for(int i=0 ; i<n ; i++)
			temp[i]=0;
		for(int j=i ; j<n ; j++)
		{
			for(int k=0 ; k<n ; k++)
				temp[k]+=a[j][k];
//			for(int k=0 ; k<n ; k++)
//				cout<<temp[k]<<" ";
//			cout<<endl;
//			cout<<"i="<<i<<" j="<<j<<" sum="<<MS(temp, n)<<endl;

			maxi=max(maxi, MS(temp, n));
		}
	}
	cout<<maxi<<endl;
}
