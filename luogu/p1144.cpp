#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000000 + 20;
const int mod = 100003;

int N, M;
namespace dijkstra
{
	int d[MAXN];
	typedef pair<int, int> P;
	struct edge
	{
		int to,cost, rev;
		edge(int to = 0, int cost = 0, int rev = 0) : to(to), cost(cost), rev(0) {}
	};
	vector<edge> g[MAXN];

	inline void addedge(int u, int v, int c)
	{
		g[u].push_back(edge(v, c, g[v].size()));
		g[v].push_back(edge(u, c, g[u].size() - 1));
	}

	inline bool tension(int &l, const int &s)
	{
		return l > s ? (l = s, true) : false;
	}

	void dij(int s)
	{
		priority_queue<P, vector<P>, greater<P> > q;
		memset(d, INF, sizeof(d));
		d[s] = 0;
		q.push(P(0,s));

		while(!q.empty())
		{
			P p = q.top();q.pop();
			int v = p.second;
			if(d[v] < p.first)
				continue;

			for(int i = 0; i < (int) g[v].size(); i++)
				if(tension(d[g[v][i].to], d[v] + g[v][i].cost))
					q.push(P(d[g[v][i].to], g[v][i].to));
		}
	}

	int f[MAXN];
	void cntmin(int n, int t)
	{
		fill(f, f + MAXN, 0);
		f[s] = 1;
		while(n--)
		{
			for(int i = 0; i < (int) g[n].size(); i++)
			{
				edge &e = g[n][i];
				if(d[e.to] == d[n] + e.cost) 
					f[e.to] += f[n], f[e.to] %= mod;
			}
		}
	}
}

inline int read()
{
	static int x;
	scanf("%d", &x);
	return x;
}
using namespace dijkstra;
int main()
{
	freopen("p1144.txt", "r", stdin);
	cin>>N>>M;

	for(int i = 1; i <= M; i++)
		addedge(read(), read(), 1);

	dij(1);
	cntmin(N,1);
	for(int i = 1; i <= N; i++)
		printf("%d\n", f[i]);
	return 0;
}




