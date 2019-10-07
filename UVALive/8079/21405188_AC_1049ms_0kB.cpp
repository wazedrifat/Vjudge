#include <bits/stdc++.h>
using namespace std;

#define MX 10000001
#define MOD 100000007
#define ll long long int

ll nCr[5][5], dp[MX][5];

int main(){
	// freopen("in.txt", "r", stdin);

	for (int i = 1; i <= 4; i++){
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; j++)
			nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
	}

	// cout << "nCr : \n";
	// for (int i = 0; i <= 4; i++)
	// {
	// 	for (int j = 0; j <= i; j++)
	// 		cout << nCr[i][j] << "\t";
	// 	cout << endl;
	// }

	dp[1][0] = 2;
	dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;

	for (int i = 2; i <= MX; i++)
	for (int j = 0; j <= 4; j++){
		dp[i][j] = (2 * dp[i-1][j] ) % MOD;
		for (int k = 0; k < j; k++)
			dp[i][j] = (dp[i][j] + dp[i-1][k]*nCr[j][j-k]) % MOD;
	}

	// cout << "dp : " << endl;
	// for (int i = 0; i <= 5; i++){
	// 	for (int j = 0; j <= 4; j++)
	// 		cout << dp[i][j] << "\t";
	// 	cout << endl;
	// }

	ll n = 1;
	while (cin >> n && n)
		cout << dp[n][4] << endl;
}