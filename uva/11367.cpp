#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1000 + 20;
const int INF = 0x3f3f3f3f;

int N, M, Q;
int C, S, T;
int cc[MAXN], d[MAXN][110];
bool vis[MAXN][110];

struct edge
{
	int to, dis;
	edge(int v = 0, int c = 0) : to(v), dis(c) {}
};

vector<edge> g[MAXN];

struct P
{
	int city, fuel, cost;
	bool operator >(const P &x) const{
		return cost > x.cost;
	}
}ans;

inline bool solve()
{
	priority_queue<P, vector<P>, greater<P> > q;

	//d[S][0] = 0;
	vis[S][0] = true;
	P s;
	s.city = S, s.fuel = 0, s.cost = 0;
	q.push(s);
	while(!q.empty())
	{
		P p = q.top(); q.pop();
		if(p.city == T)
		{
			ans = p; return true;
		}
		if(p.fuel < C && !vis[p.city][p.fuel + 1]) 
		{
			vis[p.city][p.fuel + 1] = true;
			P nxt = p;
			nxt.fuel++;
			nxt.cost += cc[p.city];
			q.push(nxt);
		}

		int u = p.city;
		for(int i = 0; i < (int) g[u].size(); i++)
		{
			const edge &e = g[u][i];
			if(e.dis <= p.fuel && !vis[e.to][p.fuel - e.dis])
			{
				vis[e.to][p.fuel - e.dis] = true;
				P nxt = p;
				nxt.fuel -= e.dis;
				nxt.city = e.to;
				q.push(nxt);
			}
		}
	}
	return false;
}

int main()
{
	//freopen("11367.txt", "r", stdin);
	cin>>N>>M;
	for(int i = 0; i < N; i++)
		scanf("%d", &cc[i]);

	int u, v, c;
	for(int i = 1; i <= M; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		g[u].push_back(edge(v, c));
		g[v].push_back(edge(u, c));
	}	

	cin>>Q;
	while(Q--)
	{
		cin>>C>>S>>T;
		memset(d, 0x3f, sizeof(d));
		memset(vis, false, sizeof(vis));
		if(solve())	cout<<ans.cost<<endl;
		else puts("impossible");
	}
	return 0;
}
