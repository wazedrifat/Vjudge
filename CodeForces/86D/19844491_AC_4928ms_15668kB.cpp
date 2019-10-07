#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define qMX 200005	
#define MX 1000005

struct query{
  ll l, r, id;
} qr[qMX];

const ll k = 320;

bool cmp(query &a, query &b) {
  ll block_a = a.l / k, block_b = b.l / k;
  if(block_a == block_b) return a.r < b.r;
  return block_a < block_b;
}

ll l = 0, r = -1, sum = 0, ans[qMX], cnt[MX], res, a[qMX];

void add(ll x) {
	res += (2 * cnt[x] + 1) * x;
	cnt[x]++;
}
void remove(ll x) {
	res += (- 2 * cnt[x] + 1) * x;
	cnt[x]--;
}

int main(){
	// freopen("in.txt", "r", stdin);

	ll n, q;
	scanf("%I64d%I64d", &n, &q);

	for (ll i = 0; i < n; i++)
		scanf("%I64d", &a[i]);

	for (ll i = 0; i < q; i++){
		scanf("%I64d%I64d", &qr[i].l, &qr[i].r);
		qr[i].l--;
		qr[i].r--;
		qr[i].id = i;
	}

	sort (qr, qr + q, cmp);

	// cout << "sorting " << q << endl;
	
	for (ll i = 0; i < q; i++){
		// cout << qr[i].l << " " << qr[i].r << " " << l << " " << r << endl;
		while (l < qr[i].l)	remove(a[l++]);
		// cout << "1------>" << l << " - " << r << " ==> " << res << endl;
		while (l > qr[i].l)	add(a[--l]);
		// cout << "2------>" << l << " - " << r << " ==> " << res << endl;
		while (r < qr[i].r)	add(a[++r]);
		// cout << "3------>" << l << " - " << r << " ==> " << res << endl;
		while (r > qr[i].r)	remove(a[r--]);
		// cout << "4------>" << l << " - " << r << " ==> " << res << endl;

		ans[ qr[i].id ] = res;
		// cout << qr[i].id << " -------- " << res << endl;
	}

	for (ll i = 0; i < q; i++)
		printf("%I64d\n", ans[i]);
}