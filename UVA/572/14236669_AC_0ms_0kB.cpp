#include<bits/stdc++.h>
using namespace std;

#define MX 10005
#define PII pair<int, int>

char ch[105][105];
class DisjointSet
{
public:
    PII a[MX];//index for value, first value for parent, second value for rank
    DisjointSet(int sz=MX)
    {
        for(int i=0 ; i<sz ; i++)
			a[i]=PII(i, 0);
    }

    int FindSet(int n)
    {
        int m=n;
        while(a[m].first!=m)
        m=a[m].first;

        a[n].first=m;
        return m;
    }

    void Union(int n1, int n2)
    {
        int x=FindSet(n1);
        int y=FindSet(n2);

//		cout<<"n1="<<n1<<" n2="<<n2<<endl;
//        cout<<"x="<<x<<" y="<<y<<endl;

        if(a[x]==a[y])    return;
        else if(a[x].second<a[y].second)
        swap(x, y);

        a[y].first=x;
        a[x].second++;
    }

	void Clear()
	{
		for(int i=0 ; i<MX ; i++)
			a[i]=PII(i, 0);
	}

	void print(int r, int c)
    {
        for(int i=0 ; i<r*c ; )
		{
			for(int j=0 ; j<c ; j++,i++)
				cout<<i<<"="<<a[i].first<<"\t";
			cout<<endl;
		}
    }
}d;

int main()
{
//	freopen("input.txt", "r", stdin);
	int r, c;
	set<int>s;

	while(scanf("%d %d", &r, &c) && r && c)
	{
		d.Clear();

//		d.print(r, c);
//		cout<<endl<<endl;
		for(int i=0 ; i<r ; i++)
		for(int j=0 ; j<c ; j++)
		{
			cin>>ch[i][j];
			if(ch[i][j]=='*')	continue;
			if(i && ch[i-1][j]=='@')
				d.Union(c*(i-1)+j, c*i+j);

			if(j && ch[i][j-1]=='@')
				d.Union(c*i+j, c*i+j-1);

			if(i && j && ch[i-1][j-1]=='@')
				d.Union(c*(i-1)+j-1, c*i+j);

			if(i && j<c && ch[i-1][j+1]=='@')
				d.Union(c*(i-1)+j+1, c*i+j);

//			if(!f)	continue;
//			cout<<"f="<<f<<" r="<<i<<" c="<<j<<endl;
//			d.print(r, c);
//			cout<<endl<<endl;
		}

//		d.print(r, c);

		s.clear();
		for(int i=0 ; i<r ; i++)
		for(int j=0 ; j<c ; j++)
			if(ch[i][j]=='@')
			s.insert(d.FindSet(i*c+j));

//		cout<<"set size=";
		cout<<s.size()<<endl;
//
//		for(auto w : s)
//			cout<<w<<" ";
//		cout<<endl;
	}
}
