#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 20;
const int MAXM = 5e5 + 20;

inline int read()
{
	static int n, ch;
	n = 0, ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
	return n;
}

int N, M, S;

namespace lca
{
	vector<int> g[MAXN];
	int fa[MAXN], top[MAXN], dep[MAXN];

	inline void addedge(int u, int v)
	{
		g[u].push_back(v);
		g[v].push_back(u);
	}

	void init()
	{
		memset(fa, 0, sizeof(fa));
		memset(top, 0, sizeof(top));
	}

	void dfs1(int u, int f, int topf, int deep)
	{
		fa[u] = f;
		top[u] = topf;
		dep[u] = deep;

		if(g[u].size() == 2)
		{
			for(int i = 0; i <= 1; i++)
			{
				int v = g[u][i];
				if(v == f) continue;
				dfs1(v, u, topf, deep + 1);
			}
			return ;
		}

		for(int i = 0; i < (int) g[u].size(); i++)
		{
			int v = g[u][i];
			if(v == f) continue;
			dfs1(v, u, u, deep + 1);
		}
		return ;
	}

	inline int findans(int x, int y)
	{
		while(top[x] != top[y])
		{
			if(dep[top[x]] < dep[top[y]]) swap(x, y);
			x = fa[top[x]];
		}
		return ;
	}
}

int main()
{
	cin>>N>>M>>S;

	int x, y;
	for(int i = 1; i < N; i++)
	{
		x = read(), y= read();
		lca::addedge(x, y);
	}

	lca::init();
	lca::dfs1(S, S, S, 1);
	int a, b;
	while(M--)
	{
		a = read(), b = read();
		printf("%d\n", lca::findans(a, b));
	}
	return 0;
}