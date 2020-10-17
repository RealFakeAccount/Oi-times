#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int MAXN = 100 + 20;
const int INF = 0x3f3f3f3f;

int N, S, T, C;

namespace dinic
{
	struct edge
	{
		int to, cap, rev;
		edge(int v = 0, int c = 0, int r = 0) : 
		to(v), cap(c), rev(r) {}
	};
	vector<edge> g[MAXN];
	int level[MAXN], iter[MAXN];

	inline void init()
	{
		for(int i = 0; i <= N; i++)
			g[i].clear();
		memset(level, 0, sizeof(level));
		memset(iter, 0, sizeof(iter));
	}

	inline void addedge(int u, int v, int c)
	{
		g[u].push_back(edge(v, c, g[v].size()));
		g[v].push_back(edge(u, c, g[u].size() - 1));
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
				edge e = g[u][i];
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
		if(u == T) return  flow;

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

	int maxflow()
	{
		int d = 0, flow = 0;
		while(bfs())
		{
			memset(iter, 0, sizeof(iter));
			while(d = dfs(S, INF), d) flow += d;
		}
		return flow;
	}
}

int main()
{
	//freopen("820.in", "r", stdin);
	//freopen("820.out", "w", stdout);
	int cnt = 0;
	while(cin>>N, N)
	{
		cnt++;

		dinic::init();
		cin>>S>>T>>C;
		int u, v, c;
		for(int i = 1; i <= C; i++)
		{
			scanf(" %d %d %d", &u, &v, &c);
			dinic::addedge(u, v, c);
		}

		printf("Network %d\n", cnt);
		printf("The bandwidth is %d.\n", dinic::maxflow());
		puts("");
	}
	return 0;
}