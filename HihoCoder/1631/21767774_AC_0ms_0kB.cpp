#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001

int main() 
{
	// IN
	int res = 0, n, m, x, cat[1000], c = 0;
	while (cin >> m >> n >> x) {
		for (int i = 0; i < n; i++)
			cin >> cat[i];

		sort(cat, cat+n);
		
		int mini = min (n , m);
		m -= mini;
		c = mini;

		// cout << "m = " << m << " c = " << c << endl;

		for (int i = 1; m > 0 && i < x; i++)
			for (int j = 0; m > 0 && j < n; j++)
				if (i % cat[j] == 0) {
					m = max(0, m-1);

					c -= (m == 0);
				}

		for (int i = 0; i < n; i++)
			if (x % cat[i] == 0) {
				// cout << "x = " << x << " c = " << cat[i] << endl;
				c--;
			}

		cout << m << " " << c << endl;
	}
}