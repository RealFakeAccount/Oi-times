

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 1e4 + 20;
const int MAXM = 5e4 + 20;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

struct _edge
{
	int from, to, cost;
	_edge(int u = 0, int v = 0, int c = 0) : from(u), to(v), cost(c) {}
	bool operator >(const _edge &lhs) const{
		return cost > lhs.cost;
	} 
}E[MAXM];

struct edge
{
	int to, cost;
	edge(int v = 0, int c = 0) : 
	to(v), cost(c) {}
};
vector<edge> g[MAXN];

int N, M, Q, t;

namespace KS
{
	int fa[MAXN];

	void init() {for(int i = 1; i <= N; i++) fa[i] = i; }
	int findfa(int x) {return fa[x] == x ? x : fa[x] = findfa(fa[x]);}
	inline void unite(int x, int y) {fa[findfa(x)] = findfa(y);}

	vector<int> need;
	void kruskal()
	{
		init();
		register int u, v, cnt = 0;
		sort(E + 1, E + M + 1, greater<_edge>());

		for(int i = 1; i <= M; i++)
		{
			u = findfa(E[i].from), v = findfa(E[i].to);
			if(u == v) continue;
			cnt++; unite(u, v); need.push_back(i);
			if(cnt == N - 1) break;
		}
 	}

 	void build()
 	{
 		for(int i = 0; i < (int) need.size(); i++)
 		{
 			int e = need[i];
 			g[E[e].from].push_back(edge(E[e].to, E[e].cost));
 			g[E[e].to].push_back(edge(E[e].from, E[e].cost));
 		}
 	}
}

namespace lca
{
	int dep[MAXN], f[MAXN][17], s[MAXN][17], bl[MAXN];

	void dfs(int u, int idx)
	{
		bl[u] = idx; 
		for(int i = 0; i < (int) g[u].size(); i++)
		{
			int v = g[u][i].to;
			if(!bl[v]) dfs(v, idx);
		}
		return ;
	}


	void bfs()
	{
		queue<int> q;
		memset(s, 0x3f, sizeof(s));

		int cnt = 0;
		for(int i = 1; i <= N; i++)
			if(!bl[i]) {dfs(i, ++cnt), dep[i] = 1, q.push(i);}

		while(!q.empty())
		{
			int u = q.front(); q.pop();

			for(int i = 0; i < (int) g[u].size(); i++)
			{
				edge &e = g[u][i];
				if(dep[e.to]) continue;

				dep[e.to] = dep[u] + 1;
				f[e.to][0] = u;
				s[e.to][0] = e.cost;
				for(int i = 1; i < t; i++)
					f[e.to][i] = f[ f[e.to][i - 1] ][i - 1],
					s[e.to][i] = min(s[ f[e.to][i - 1] ][i - 1], s[e.to][i - 1]);
				q.push(e.to);
			}
		}
	}

	inline int getans(int x, int y)
	{
		if(bl[x] != bl[y]) return -1;
		int ans = INF;
		if(dep[y] < dep[x]) swap(x, y);
		for(int i = t; i >= 0; i--)
			if(dep[f[y][i]] >= dep[x]) ans = min(ans, s[y][i]), y = f[y][i];
		if(x == y) return ans;
		for(int i = t; i >= 0; i--)
			if(f[y][i] != f[x][i]) 
				ans = min(ans, min(s[x][i], s[y][i])), x = f[x][i], y = f[y][i];
		ans = min(ans, min(s[x][0], s[y][0]));
		return ans;
	}
}

int main()
{
	//freopen("p1967.in", "r", stdin);
	cin>>N>>M;
	t = 15;

	register int u, v, c;
	for(int i = 1; i <= M; i++)
	{
		u = read(), v = read(), c = read();
		E[i] = _edge(u, v, c);
	}

	KS::kruskal();
	KS::build();
	lca::bfs();

	cin>>Q;
	while(Q--)
	{
		u = read(), v = read();
		printf("%d\n", lca::getans(u, v));
	}
	return 0;
}
