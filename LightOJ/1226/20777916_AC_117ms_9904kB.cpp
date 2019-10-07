#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define MX 1000001
#define LL long long
#define INF INT_MAX
#define PII pair<LL, LL>
#define MOD 1000000007

LL fac[MX], arr[1005];

LL extGcd(LL A, LL B, LL &X, LL &Y)
{
	LL x2, y2, x1, y1, x, y, r2, r1, q, r;
	x2 = 1;
	y2 = 0;
	x1 = 0;
	y1 = 1;
	for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y)
	{
		q = r2 / r1;
		r = r2 % r1;
		x = x2 - (q * x1);
		y = y2 - (q * y1);
	}
	X = x2;
	Y = y2;
	return r2;
}

LL modInv(LL a, LL m)
{
	LL x, y;
	extGcd(a, m, x, y);

	// Process x so that it is between 0 and m-1
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

void factorial(){
	fac[0] = 1;
	for (LL i = 1; i < MX; i++)
		fac[i] = (i * fac[i-1]) % MOD;
}

LL nCr(LL n, LL r){
	LL res = fac[n];

	res = (res * modInv(fac[r], MOD)) % MOD;
	res = (res * modInv(fac[n-r], MOD)) % MOD;

	return res;	
}

int main(){
	// IN

	factorial();

	int test;
	cin >> test;

	// cout << "test = " << test << endl;

	for (int t = 1; t <= test; t++){
		int n;
		cin >> n;

		// cout << "n = " << n << endl;

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		LL res = 1, sum = arr[0];

		for (int i = 1; i < n; i++){
			sum += arr[i];
			res = (res * nCr(sum - 1, arr[i] -1)) % MOD;

			// cout << "i = " << i << " sum = " << sum << " nCr = " << nCr(sum-1, arr[i]-1) << endl;
		}

		cout << "Case " << t <<": " << res << endl;
	}
	
}
