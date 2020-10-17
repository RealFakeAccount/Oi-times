#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e2 + 20;
const int INF = 0x3f3f3f3f;

int A, B, M, L, K;
int d[MAXN][MAXN], f[MAXN][12];
bool vis[MAXN][12];

struct edge
{
	int to, cost;
};vector<edge> g[MAXN];
struct state
{
	int pos, time, k;
	state(int u = 0, int t = 0, int k = 0) :
	pos(u), time(t), k(k) {}
	bool operator >(const state &rhs) const{
		return time > rhs.time;
	}
};

void init()
{
	memset(d, 0x3f, sizeof(d));
	memset(f, 0x3f, sizeof(f));
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= (A + B); i++) g[i].clear();
}

void floyd()
{
	for(int i = 1; i <= (A + B); i++) d[i][i] = 0;
		for(int k = 1; k <= A; k++)
			for(int i = 1; i <= (A + B); i++)
				for(int j = 1; j <= (A + B); j++)
					if(d[i][k] != INF && d[k][j] != INF)
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

inline bool tension(const int &st, int &lg)
{
	return st < lg ? (lg = st, true) : false;
}

int bfs()
{
	priority_queue<state, vector<state>, greater<state> > q;
	f[(A + B)][0] = 0;
	q.push(state((A + B), 0, 0));

	while(!q.empty())
	{
		state u = q.top(); q.pop();
		if(u.pos == 1) return u.time;
		if(vis[u.pos][u.k]) continue;
		vis[u.pos][u.k] = true;
		for(int i = 0; i < (int) g[u.pos].size(); i++)
		{
			edge &e = g[u.pos][i];
			if(tension(u.time + e.cost, f[e.to][u.k]))
				q.push(state(e.to, f[e.to][u.k], u.k));
		}

		if(u.k < K)
		for(int i = 1; i <= (A + B); i++)
			if(d[i][u.pos] <= L && tension(u.time + 0, f[i][u.k + 1]))
				q.push(state(i, f[i][u.k + 1], u.k + 1));
	}
	return rand();
}

int main()
{
	//freopen("10269.in", "r", stdin);
	//freopen("10269.out", "w", stdout);
	int T; cin>>T;
	while(T--)
	{
		cin>>A>>B>>M>>L>>K;init();
		for(int i = 1, u, v, c; i <= M; i++)
		{
			scanf("%d%d%d", &u, &v, &c);
			d[u][v] = d[v][u] = c;
			g[u].push_back((edge){v, c});
			g[v].push_back((edge){u, c});
		}
		floyd();
		printf("%d\n", bfs());
	}
	return 0;
}
