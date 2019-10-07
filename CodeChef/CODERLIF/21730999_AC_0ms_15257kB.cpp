#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001

int main() 
{
	int test;
	cin >> test;
	
	for (int t = 1; t <= test; t++)
	{
		string res[2] = {"#coderlifematters", "#allcodersarefun"};
		int cnt = 0, flag = 1;

		for (int i = 0; i < 30; i++)
		{
			bool b;
			cin >> b;

			if (b)	cnt++;
			else cnt = 0;

			flag *= (cnt <= 5);
		}
		
		cout << res[flag] << endl;
	}
}