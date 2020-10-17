#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int MAXN = 1e3 + 20;

int T, N, S, K;
vector<int> g[MAXN], nodes[MAXN];
int dep[MAXN], fa[MAXN]; 
bool covered[MAXN];

void init()
{
	memset(dep, 0, sizeof(dep));
	memset(covered, false, sizeof(covered));
	memset(fa, 0, sizeof(fa));
	for(int i = 0; i <= N; i++)
		g[i].clear(), nodes[i].clear();
}

void bfs()
{
	queue<int> q;
	q.push(S); dep[S] = 1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		
		for(int i = 0; i < (int) g[u].size(); i++)
		{
			int v = g[u][i];
			if(dep[v]) continue;
			//puts("qwq");

			fa[v] = u;
			dep[v] = dep[u] + 1;
			if(g[v].size() == 1 && dep[v] > K + 1) nodes[dep[v]].push_back(v);
			q.push(v);
		}
	}
}

void dfs(int u, int fa, int d)
{
	covered[u] = true;
	for(int i = 0 ; i < (int) g[u].size(); i++)
	{
		int v = g[u][i];
		if(v != fa && d < K) dfs(v, u, d + 1);
	}
}

int solve()
{
	int ans = 0;
	for(int d = N - 1; d > K; d--)
		for(int i = 0; i < (int) nodes[d].size(); i++)
		{
			int u = nodes[d][i];
			if(covered[u]) continue;

			int v = u;
			for(int j = 1; j <= K; j++) v = fa[v];
			dfs(v, v, 0); ans++;
		}
	return ans;
}

int main()
{
	cin>>T;
	while(T--)
	{
		init();
		cin>>N>>S>>K;

		int u, v;
		for(int i = 1; i < N; i++)
		{
			scanf(" %d %d", &u, &v);
			g[u].push_back(v), g[v].push_back(u);
		}

		bfs();
		printf("%d\n", solve());
	}
	return 0;
}
