#include<bits/stdc++.h>
using namespace std;

int main()
{
	char ch[100005];
	while(scanf("%s", ch)!=EOF)
	{
		string s=ch;
		deque<char>temp, res;

		for(int i=0, f=0 ; i<s.length() ; i++)
		{
			if(s[i]=='[')
            {
                while(temp.size())
                {
                    char t=temp.back();
                    temp.pop_back();
                    res.push_front(t);
                }
                f=1;
            }
            else if(s[i]==']')
                f=0;
            else if(f)
                temp.push_back(s[i]);
            else
                res.push_back(s[i]);
		}

		while(temp.size())
        {
            int t=temp.back();
            temp.pop_back();
            res.push_front(t);
        }

		for(auto w : res)
			cout<<w;
		cout<<endl;
		res.clear();
		temp.clear();
	}
}
