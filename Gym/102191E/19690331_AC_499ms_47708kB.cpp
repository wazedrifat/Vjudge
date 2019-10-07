#include<bits/stdc++.h>
using namespace std;

#define PII pair <int, int>

PII dir[26];
deque<PII>d;
map<PII, int>m;

int main()
{
    dir['L' - 'A'] = PII(-1, 0);
    dir['R' - 'A'] = PII(1, 0);
    dir['U' - 'A'] = PII(0, 1);
    dir['D' - 'A'] = PII(0, -1);
    int res = 0;

    int n;
    cin >> n;
    PII p(0, 0);
	d.push_back(p);
	m[p] = 1;

    for(int i = 0; i < n; i++)
	{
        char c;
        cin >> c;

		p.first += dir[c - 'A'].first;
		p.second += dir[c - 'A'].second;

//		cout << "p = (" << p.first << "," << p.second << ") m[p] = " << m[p] << endl;

		if(m.find(p) != m.end() && m[p] == 1)
		{
			for(int j = 0; d.size() > 0 && d[0] != p; j++)
			{
				m[ d[0] ] = 0;
				d.pop_front();
			}
			d.pop_front();
		}

		m[p] = 1;
		d.push_back(p);

//		cout << "i = " << i <<" : ";
//		for(int j = 0; j < d.size(); j++)
//			cout << "(" << d[j].first << "," << d[j].second << ") ";
//		cout << endl;

		res = max(res, (int)d.size()-1);
	}
	cout << res;
}
