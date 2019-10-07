#include <bits/stdc++.h>
using namespace std;

#define MX 100005
#define ll long long int 

int a[305][305];

int main(){
	// freopen("in.txt", "r", stdin);

	int t;
	cin >> t;

	string res[] = {"YES", "NO"};

	while (t--){
		int n, x;
		cin >> n >> x;

		int sum = x;

		for (int i = 1; i < n; i++){
			cin >> x;
			sum ^= x;
		}

		cout << (!sum) << endl;
	}
}