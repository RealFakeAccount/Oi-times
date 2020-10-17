#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e2 + 10;
const int INF = 0x3f3f3f3f;

int N, M, K, S, T;

namespace dinic
{
	struct edge
	{
		int to, cap, rev;
		edge(int v, int c, int r) : to(v), cap(c), rev(r) {}
	};
	vector<edge> g[MAXN << 1];
	int level[MAXN << 1], iter[MAXN << 1];

	inline void addedge(int u, int v, int c)
	{
		g[u].push_back(edge(v, c, g[v].size()));
		g[v].push_back(edge(u, 0, g[u].size() - 1));
	}

	inline bool bfs()
	{
		queue<int> q;
		memset(level, -1, sizeof(level));
		q.push(S);
		level[S] = 0;

		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int i = 0; i < (int) g[u].size(); i++)
			{
				edge &e = g[u][i];
				if(e.cap && level[e.to] == -1)
				{
					level[e.to] = level[u] + 1;
					q.push(e.to);
				}
			}
		}
		return ~level[T];
	}

	int dfs(int u, int flow)
	{
		if(u == T) return flow;

		for(int &i = iter[u]; i < (int) g[u].size(); i++)
		{
			edge &e = g[u][i];
			if(e.cap && level[e.to] == level[u] + 1)
			{
				int d = dfs(e.to, min(flow, e.cap));
				if(d)
				{
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}	
		return 0;
	}

	inline int maxflow()
	{
		int d = 0, flow = 0;
		while(bfs())
		{
			memset(iter, 0, sizeof(iter));
			while(d = dfs(S, INF), d) flow += d;
		}
		return flow;
	}

	inline void init()
	{
		for(int i = 0; i < (MAXN << 1); i++)
			g[i].clear();
	}
}
int main()
{
	//freopen("1325.in", "r", stdin);
	while(cin>>N, N != 0)
	{
		cin>>M>>K;
		S = N + M, T = N + M + 1;
		using namespace dinic;
		init();

		register int x, y;
		for(int i = 1; i <= K; i++)
		{
			scanf("%*d %d %d",&x, &y);
			if(x == 0 || y == 0) continue;
			addedge(x, y + N, 1);
		}

		for(int i = 0; i < N; i++)
			addedge(S, i, 1);
		for(int i = 0; i < M; i++)
			addedge(N + i , T, 1);

		printf("%d\n", dinic::maxflow());
	}
	return 0;
}
