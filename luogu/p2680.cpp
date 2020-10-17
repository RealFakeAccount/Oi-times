#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 3e5 + 20;

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M;

struct edge
{
	int to, cost;
	edge(int v = 0, int c = 0) :
	to(v), cost(c) {}
};
vector<edge> g[MAXN];

struct event
{
	int u, v, a;
	event(int u = 0, int v = 0) :
	u(u), v(v) {}
}E[MAXN];

int dep[MAXN], f[MAXN][20], p[MAXN];

void bfs()
{
	queue<int> q;
	dep[1] = 1; q.push(1);
	while(!q.empty())
	{
		int u = q.front(); q.pop();

		for(int i = 0; i < (int) g[u].size(); i++)
		{
			int v = g[u][i].to;
			if(dep[v]) continue;

			dep[v] = dep[u] + 1;
			f[v][0] = u;
			for(int i = 1; i < 20; i++)
				f[v][i] = f[f[v][i - 1]][i - 1];
			q.push(v);
		}
	}
}

inline int lca(int x ,int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--)
		if(dep[f[y][i]] >= dep[x]) y = f[y][i];
	if(x == y) return y;
	for(int i = 19; i >= 0; i--)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[y][0];
}

void prepare()
{
	bfs();
	for(int i = 1; i <= M; i++)
		E[i].a = lca(E[i].u, E[i].v),
		p[E[i].a]++, p[E[i].u]--, p[E[i].v]--;
}

bool dfs(int cur, bool used, int num, int x)
{
	for(int i = 0; i < (int) g[cur].size(); i++)
	{
		edge &e = g[u][i];
		if(used && e.cost >= x) return false;
	}
}

inline bool check(int x)
{
	return dfs(1, false, 0, x);
}

int main()
{
	cin>>N>>M;

	register int u, v, c, l = 0, r = 0;

	for(int i = 1; i < N; i++)
	{
		u = read(), v = read(), c = read(), r += c;
		g[u].push_back(edge(v, c));
		g[v].push_back(edge(u, c));
	}

	for(int i = 1; i <= M; i++)
		u = read(), E[i] = event(u, read());

	prepare();

	#define mid (((l) + (r)) >> 1)
	while(l < r) 
	{
		if(check(mid)) r = mid;
		else r = mid + 1;
	}
	return 0;
}