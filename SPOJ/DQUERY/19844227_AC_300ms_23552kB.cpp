#include <bits/stdc++.h>
using namespace std;

#define qMX 200005
#define MX 1000005

struct query{
  int l, r, id;
} qr[qMX];

const int k = 320;

bool cmp(query &a, query &b) {
  int block_a = a.l / k, block_b = b.l / k;
  if(block_a == block_b) return a.r < b.r;
  return block_a < block_b;
}

int l = 0, r = -1, sum = 0, ans[qMX], cnt[MX], res, a[30005];

void add(int x) {
	if(++cnt[x] == 1)
		res++;
}
void remove(int x) {
	if(--cnt[x] == 0){
		res--;
	}
}

int main(){
	// freopen("in.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; i++){
		scanf("%d%d", &qr[i].l, &qr[i].r);
		qr[i].l--;
		qr[i].r--;
		qr[i].id = i;
	}

	sort (qr, qr + q, cmp);

	// cout << "sorting " << q << endl;
	
	for (int i = 0; i < q; i++){
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

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
}