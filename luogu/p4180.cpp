#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAXM = 200000 + 20;
const int MAXN = 5000 + 20;
const int INF = 0x7f7f7f7f;

inline int read()
{
	int x = 0;char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M, K;

struct edge
{
	int u, v, c;
	edge(int u = 0, int v = 0, int c = 0) : 
	u(u), v(v), c(c) {}
	bool operator <(const edge &rhs) const{
		return c < rhs.c;
	}
	bool operator >(const edge &rhs) const{
		return c > rhs.c;
	}
}E[MAXM];
bool cmp(const edge &lhs, const edge &rhs)
{
	return lhs > rhs;
}

bool in_t[MAXM];
vector<edge> g[MAXN];

int G[MAXN][K][2], f[MAXN][K], dep[MAXN], dis[MAXN];

void bfs()
{
	queue<int> q;
	q.push(1);dep[1] = 1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = 0; i < (int) g[u].size(); i++)
		{
			edge &e = g[u][i];
			int v = e.v;
			if(dep[v]) continue;

			dep[v] = dep[u] + 1;
			dis[v] = dis[u] + e.c;
			f[v][0] = u;
			G[v][0][0] = e.c;
			G[v][0][1] = -INF;

			for(int j = 1; j <= K; j++)
			{
				f[v][j] = f[f[v][j - 1]][j - 1];
				G[v][j][0] = max(G[v][j - 1][0], G[f[v][j - 1]][j - 1][0]);

				if(G[v][j - 1][0] == G[f[v][j - 1]][j - 1][0])
					G[v][j][1] = max(G[v][j - 1][1], G[f[v][j - 1]][j - 1][1]);

				else if(G[v][j - 1][0] < G[f[v][j - 1]][j - 1][0])
					G[v][j][1] = max(G[v][j - 1][0], G[f[v][j - 1]][j - 1][1]);

				else if(G[v][j - 1][0] > G[f[v][j - 1]][j - 1][0])
					G[v][j][1] = max(G[f[v][j - 1]][j - 1][0], G[v][j - 1][1]);
			}	
			q.push(e.v);
		}
	}
}

namespace ufs
{
	int fa[MAXN];

	void init()
	{
		for(int i = 1; i <= N; i++)
			fa[i] = i;
	}

	int findfa(int x)
	{
		if(x == fa[x]) return x;
		return fa[x] = findfa(fa[x]);
 	}

 	inline void unite(int x, int y)
 	{
 		fa[y] = findfa(x);
 	}
}

inline P get_max(int x, int y)
{
	P res = P(-INF, -INF);
	if(dpe[x] > dep[y]) swap(x, y);
	for(int i = K; i >= 0; i--)
		if(dep[f[y][i]] >= d[x]) 
		{
			y = f[y][i];
			
		}
	if(x == y) return x;

}

int main()
{
	//freopen("p4180.in", "r", stdin);
	cin>>N>>M;
	K = log(N)/log(2) + 1;

	register int u, v, c;
	for(int i = 1; i <= M; i++)
	{
		u = read(), v = read(), c = read();
		E[i] = edge(u, v, c);
	}

	sort(E + 1, E + M + 1);

	int len = 0, cnt = 0;
	for(int i = 1; i <= M; i++)
	{
		u = ufs::findfa(E[i].u),
		v = ufs::findfa(E[i].v);
		if(u == v) continue;
		ufs::unite(u, v);
		g[E[i].u].push_back(edge(E[i].u, E[i].v, E[i].c));
		g[E[i].v].push_back(edge(E[i].v, E[i].u, E[i].c));
		in_t[i] = true;
		len += E[i].c;
		cnt++;
		if(cnt == N - 1) break;
	}

	bfs();
	int val = len;
	for(int i = 1; i <= M; i++)
	{
		if(in_t[i]) continue;

	}

	return 0;
}
