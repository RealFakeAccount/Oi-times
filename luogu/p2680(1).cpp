#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 3e5 + 20;
const int INF = 0x3f3f3f3f;

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
	int u, v, a, dis;
	event(int u = 0, int v = 0) :
	u(u), v(v) {}
	bool operator <(const event &rhs) const{
		return dis < rhs.dis;
	}
	bool operator >(const event &rhs) const{
		return dis > rhs.dis;
	}
}E[MAXN];

int dep[MAXN], f[MAXN][20], n[MAXN], d[MAXN][20];

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
			d[v][0] = g[u][i].cost;
			f[v][0] = u;
			for(int i = 1; i < 20; i++)
				f[v][i] = f[f[v][i - 1]][i - 1],
				d[v][i] = d[f[v][i - 1]][i - 1] + d[v][i - 1];
			q.push(v);
		}
	}
}

inline P lca(int x ,int y)
{
	int dis = 0;
	if(dep[x] > dep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--)
		if(dep[f[y][i]] >= dep[x]) dis += d[y][i], y = f[y][i];
	if(x == y) return P(y, dis);
	for(int i = 19; i >= 0; i--)
		if(f[x][i] != f[y][i])
			dis += d[x][i], dis += d[y][i], 
			x = f[x][i], y = f[y][i];
	return P(f[y][0], (dis + d[x][0] + d[y][0]));
}

void prepare()
{
	bfs();
	register P ans;
	for(int i = 1; i <= M; i++)
	{
		ans = lca(E[i].u, E[i].v);
		E[i].a = ans.first, E[i].dis = ans.second;
	}
//	sort(E + 1, E + M + 1);
}

bool used;
int co;
int dfs(int cur, int fa, int cost, int num)
{
	int tag = 0;
	for(int i = 0; i < (int) g[cur].size(); i++)
	{
		edge &e = g[cur][i];
		if(e.to == fa) continue;
		tag += dfs(e.to, cur, e.cost, num);
	}
	tag += n[cur];
	if(tag == num) co = max(cost, co);
	return tag;
} 

inline bool check(int x)
{
//	event ca; ca.dis = x;
//	int p = upper_bound(E + 1, E + M + 1, ca) - E;
//	if(p - 1 == M) return true;
	int cnt = 0, maxd = -INF;
	memset(n, 0, sizeof(n));
	for(int i = 1; i <= M; i++)
		if(E[i].dis > x) 
			n[E[i].a] -= 2, n[E[i].u]++, n[E[i].v]++, cnt++,
			maxd = max(maxd, E[i].dis);
	co = -INF;
	dfs(1, 1, 0, cnt);
	if(co == -INF) return false;
	else return maxd - co <= x;

}

int main()
{
//	freopen("p2680.in", "r", stdin);
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
	//	int mid = (l + r + 1) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout<<l<<endl;
	return 0;
}
