#include <bits/stdc++.h>
using namespace std;

#define MX 1000005 //1e6+5
#define ll long long int

bool flag[MX];
vector<int> prime, factors;
int res[MX];

void SieveOfEratosthenes(int limit = MX)
{
	prime.clear();
	flag[0] = flag[1] = 1;

	prime.push_back(2);

	for (int i = 4; i <= limit; i += 2)
		flag[i] = 1;

	for (int i = 3; i * i < limit; i += 2)
		if (flag[i] == 0)
			for (int j = i * i; j <= limit; j += 2 * i)
				flag[j] = 1;

	for (int i = 3; i <= limit; i += 2)
		if (flag[i] == 0)
			prime.push_back(i);
}

void factorize(int n)
{
	int sqrtn = sqrt(n);
	for (int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	if (n % prime[i] == 0){
		int cnt = 0;
		while (n % prime[i] == 0){
			n /= prime[i];
			cnt++;
		}
		res[prime[i] ]++;
		// cout << "prime : " << prime[i] << endl;
		sqrtn = sqrt(n);
	}

	if (n != 1){
		// cout << "prime : " << n << endl;
		res[n]++;
	}
		
}

int main(){
	// freopen("in.txt", "r", stdin);

	SieveOfEratosthenes();
	int t;
	cin >> t;

	while (t--){
		memset(res, 0, sizeof res);

		int n;
		cin >> n;


		for (int i = 0; i < n; i++){
			int x;
			cin >> x;

			factorize(x);
		}

		int ans = 0;
		for (int i = 0; i < prime.size(); i++){
			int c = res[ prime[i] ] ;

			// if(c)
			// 	cout << prime[i] << " " << c << endl;
			ans += c / 3 + (c % 3 != 0);
		}
		cout << ans << endl;
		// cout << endl << endl << endl;
	}
}