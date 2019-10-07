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
		int n;
		cin >> n;

		cout << n/2 + (n%2) << " " << n/2 << endl;
	}
}