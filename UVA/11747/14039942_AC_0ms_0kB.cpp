#include<bits/stdc++.h>
using namespace std;

int	pr[5000];
struct edge
{
    int u,v,w;
    edge(int _u, int _v, int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
};

vector<edge>e;
vector<int>vec;

bool comp(edge a, edge b){	return a.w<=b.w;	}
int find(int r){	return pr[r]==r? r: find(pr[r]);	}

int mst(int n)
{
	sort(e.begin(),e.end(),comp);

	for(int i=0 ; i<=n ; i++)	pr[i]=i;

	int cnt=0,sum=0;
	for(int i=0 ; i<e.size() ; i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);

		pr[ e[i].u ]=u;
		pr[ e[i].v ]=v;

		if(u!=v)
		{
			pr[u]=v;
			cnt++;
			sum+=e[i].w;

			if(cnt==n-1)	break;
		}
		else
            vec.push_back(e[i].w);
	}
	return sum;
}

int main()
{
    int n, m;

    while(scanf("%d %d", &n, &m) && (n||m) )
    {
        for(int i=0 ; i<m ; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            e.push_back(edge(u, v, w));
        }

        int f=mst(1000);

        if(vec.size()==0)
        cout<<"forest";
        else
            for(int i=0 ; i<vec.size() ; i++)
            {
                cout<<vec[i];
                if(i<vec.size()-1)
                    cout<<" ";
            }
        cout<<endl;
        e.clear();
        vec.clear();
    }
}
