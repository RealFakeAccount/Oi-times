#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e3 + 20;

bool S[MAXN][MAXN];
int s[MAXN][MAXN];
int N, M;

struct rec // rectangle
{
	int l, h;
	rec(int l = 0, int h = 0) : l(l), h(h) {}
};
struct _Stack
{
	stack<rec> sta;

	inline void init()
	{
		while(!sta.empty())
			sta.pop();
	}

	inline int Pushin(rec now)
	{
		if(sta.empty() || sta.top().h < now.h)
		{
			sta.push(now);
			return 0;
		}

		rec cur;
		int len = 0, area = 0;
		while(!sta.empty() && now.h < sta.top().h)
		{
			cur = sta.top();
			len += cur.l;
			area = max(area, len * cur.h);
			sta.pop();
		}
		sta.push(rec(len + now.l, now.h));
		return area;
	}
}Stack;

inline void init()
{
	memset(S, false, sizeof(S));
	memset(s, 0, sizeof(s));
	Stack.init();
}

inline void solve()
{
	char ch;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
		{
			cin>>ch;
			if(ch == 'F') S[i][j] = true;
			else S[i][j] = false;
		}

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			S[i][j] == true ? s[i][j] = s[i - 1][j] + 1 : s[i][j] = 0;
		
	/*for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= M; j++)
				cout<<s[i][j]<<" ";
			cout<<endl;
		}*/
	int area = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
			area = max(area, Stack.Pushin(rec(1, s[i][j])));

		area = max(area, Stack.Pushin(rec(1, 0)));
		Stack.init();
	}	

	cout<<area * 3<<endl;
}

int main()
{
	freopen("1330.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int K;
	cin>>K;
	while(K--)
	{
		cin>>N>>M;
		init();
		solve();
	}
	return 0;
}
