#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 2e5 + 20;
const int EPS = 200;
const int INF = 0x3f3f3f3f;

int N, M;
struct edge
{
	int to, cost;
	edge(int v = 0, int c = 0) : to(v), cost(c) {}
};

vector<edge> g[MAXN];

int d[MAXN], vis[MAXN];
bool flag;

inline void init()
{
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	flag = false;
	for(int i = 0; i <=min((N + EPS), MAXN); i++)
		g[i].clear();
}

bool SPFA()
{
	queue<int> q;

	d[1] = 0;
	vis[1] = 0;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = 0; i < (int) g[u].size(); i++)
		{
			edge &e = g[u][i];
			if(d[e.to] > d[u] + e.cost)
			{
				d[e.to] = d[u] + e.cost;
				//cout<<u<<" "<<e.to<<endl;
				vis[e.to] = vis[u] + 1;
				if(vis[e.to] >= N) return true;
				q.push(e.to);
			}
		}
	}
	return false;
}
int main()
{
	int T;
	cin>>T;

	int a, b, w;
	while(T--)
	{
		scanf("%d%d", &N, &M);
		init();

		for(int i = 1; i <= M; i++)
		{
			scanf("%d%d%d",&a, &b, &w);
			if(w < 0) g[a].push_back(edge(b, w));
			else {g[b].push_back(edge(a, w));
				  g[a].push_back(edge(b, w));}
		}

		if(SPFA()) puts("YE5");
		else puts("N0");
	}
	return 0;
}