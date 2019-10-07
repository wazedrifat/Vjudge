#include <bits/stdc++.h>
using namespace std;

#define in freopen("in.txt", "r", stdin);
#define out freopen("out.txt", "w", stdout);
#define MX 3005
#define LL int
#define INF INT_MAX
#define PII pair<LL, LL>

int a[21] = {	1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
			1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
			47045881, 64000000, 85766121
		};
		
int main(){
	int n;

	while(cin >> n && n){
		int f = 0;
		
		for (int i = 0; !f && i < 21; i++)
			if (a[i] == n){
				cout << "Special" << endl;
				f = 1;
			}
		if (!f)
			cout << "Ordinary" << endl;
	}
}
