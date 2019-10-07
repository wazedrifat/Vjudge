#include<bits/stdc++.h>
using namespace std;

int a[300005];

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
		cin >> a[i];

	if(n <= 4)
	{
		cout << -1;
		return 0;
	}

	for(int i = 1; i <= n; i+=2)
		cout << a[i] << " ";

	if(n % 2 == 0)
		swap(a[n], a[n-2]);

	for(int i = 2; i <= n ; i+=2)
		cout << a[i] << " ";
}
