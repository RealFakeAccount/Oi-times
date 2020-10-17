#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
const double EPS = 1e-4;
const int INF = 0x3f3f3f3f;
const int MAXP = 5e3 + 20;
const int MAXL = 1e3 + 20;


int L, P;int fun[MAXL];

struct edge
{
	int to;
	double cost;
	edge(int v = 0, double c = 0) : to(v), cost(c) {}
};
vector<edge> g[MAXL];

struct sedge
{
	int from, to, cost;
	sedge(int u = 0, int v = 0, int c = 0) : 
	from(u), to(v), cost(c) {}
}E[MAXP];

double d[MAXL];int vis[MAXL];
inline void init()
{
	for(int i = 1; i <= L; i++) d[i] = INF;
	for(int i = 1; i <= L; i++) g[i].clear();
	memset(vis, 0, sizeof(vis));
}

inline bool SPFA()
{
	queue<int> q;
	q.push(1);
	d[1] = 0;

	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = 0; i < (int) g[u].size(); i++)
		{
			edge &e = g[u][i];
			if(d[e.to] > d[u] + e.cost)
			{
				d[e.to] = d[u] + e.cost;
				vis[e.to] = vis[u] + 1;
				if(vis[e.to] >= L) return true;
				q.push(e.to);
			}
		}
	}
	return false;
}

inline bool check(double x)
{
	init();
	for(int i = 1; i <= P; i++)
		g[E[i].from].push_back(edge(E[i].to, x * E[i].cost - fun[E[i].from]));
	return SPFA();
}

int main()
{
	//freopen("p2868.in", "r", stdin);
	cin>>L>>P;

	for(int i = 1; i <= L; ++i)
		scanf(" %d", &fun[i]);

	register int u, v, c;

	register double l = 0, r = 0;
	for(int i = 1; i <= P; i++)
	{
		scanf(" %d %d %d", &u, &v, &c);
		E[i] = sedge(u, v, c);
		r += c;
	}

	register double mid;
	while((r - l) > EPS)
	{
		mid = (l + r) / 2;
		if(!check(mid)) r = mid;
		else l = mid;
	}

	printf("%.2f", r);
	return 0;
}
