#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define MX 100005

class DisjointSet
{
public:
    PII a[MX];//index for value, first value for parent, second value for rank
    DisjointSet()
    {
        for(int i=0 ; i<MX ; i++)
        {
            a[i].first=i;
            a[i].second=0;
        }
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

        if(a[x]==a[y])    return;
        else if(a[x].second<a[y].second)
        swap(x, y);

        a[y].first=x;
        a[x].second++;
    }

    void print(int v)
    {
        for(int i=0 ; i<v ; i++)
            cout<<"i="<<i<<" parent="<<a[i].first<<endl;
    }
};

int main()
{
    int t;
    scanf("%d", &t);
	bool f=0;

    while(t--)
	{
		if(f)	cout<<endl;
			f=1;

		DisjointSet s;

		int n, tr=0, fl=0;
		scanf("%d", &n);

		string str;
		(void)getchar();
		while(getline(cin, str) && str[0]!=NULL)
		{

			char ch=str[0];
			int u=0, v=0;

			int i=2;
			for( ; str[i]!=' ' ; i++)
				u=u*10+(str[i]-'0');
			for(i++ ; str[i]!=' ' && i<str.length() ; i++)
				v=v*10+(str[i]-'0');
			//cout<<"ch="<<ch<<" u="<<u<<" v="<<v<<endl;
			if(ch=='c')
				s.Union(u, v);
			else
			{
				int x=s.FindSet(u);
				int y=s.FindSet(v);
				//cout<<"x="<<x<<" y="<<y<<endl;
				tr+=(x==y);
				fl+=(x!=y);
			}
			//cout<<"@ last : ch="<<ch<<" u="<<u<<" v="<<v<<endl;
		}
		cout<<tr<<","<<fl<<endl;
	}
}
