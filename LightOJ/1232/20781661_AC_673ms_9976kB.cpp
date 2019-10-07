#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define MX 1000001
#define LL long long
#define INF INT_MAX
#define PII pair<LL, LL>
#define MOD 100000007

LL dp[10001][101], a[101];

int main(){
	// IN

	LL test;
	scanf("%lld", &test);

	// cout << "test = " << test << endl;

	for (LL t = 1; t <= test; t++){
		LL n, k;
		scanf("%lld%lld", &n, &k);

		// cout << "n = " << n << endl;

		for (LL i = 1; i <= n; i++)
			scanf("%lld", &a[i]);

		for (LL i = 0; i <= n; i++)
			dp[0][i] = 1;
		for (LL i = 1; i <= k; i++)
			dp[i][0] = 0;
		
		for (LL i = 1; i <= n; i++){
			for (LL j = 1; j <= k; j++)
				if(a[i] <= j)
					dp[j][i] = (dp[j - a[i]][i] + dp[j][i-1]) % MOD;
				else 
					dp[j][i] = dp[j][i-1];
		}

		// for(LL i = 0; i <= n; i++){
		// 	for (LL j = 0; j <= k; j++)
		// 		cout << dp[j][i] << " ";
		// 	cout << endl;
		// }
		printf("Case %lld: %lld\n", t, dp[k][n]);
	}
	
}
