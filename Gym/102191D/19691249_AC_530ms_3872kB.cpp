#include<bits/stdc++.h>
using namespace std;

#define PII pair <int, int>

PII a[300005];
deque<int>d;

bool cmp(PII p1, PII p2)
{
	return ( (p1.first == p2.first)?	p1.second >= p2.second : p1.first >= p2.first);
}

int main()
{
    int n, flag = 0;
    cin >> n;

	n /=2;
    for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		a[i] = PII ( max (x, y), min(x, y));
	}

	sort(a, a + n, cmp);

	d.push_back(a[0].second);
	d.push_back(a[0].first);

//	for(int i = 0; i < d.size(); i++)
//			cout << d[i] << " ";
//	cout << endl;

    for(int i = 1; i < n; i++)
	{
		if(a[i].first <= d.front())
		{
			d.push_front(a[i].first);
			d.push_front(a[i].second);
		}
		else if(a[i].first <= d.back())
		{
			d.push_back(a[i].first);
			d.push_back(a[i].second);
		}
		else
			flag = 1;
	}

	if(flag == 1)
		cout << -1;
	else
		for(int i = 0; i < d.size(); i++)
			cout << d[i] << " ";
}
