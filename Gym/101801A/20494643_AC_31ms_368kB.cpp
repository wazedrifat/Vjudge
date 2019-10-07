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
		int s, d;
		cin >> s >> d;

		// cout << s << " 3" << d << " " << (s>d) << endl;
		cout << res[(s<d)] << endl;
	}
}