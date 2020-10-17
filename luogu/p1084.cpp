#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 5e4 + 20;
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
vector<edge> g[MAXN], unc;

int dep[MAXN], f[MAXN][17], d[MAXN];
vector<int> army, co[MAXN];

inline void init()
{
	unc.clear();
	for(int i = 0; i <= N; i++) co[i].clear();
}

void bfs()
{
	queue<int> q;
	dep[1] = 1, q.push(1);

	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = 0; i < (int) g[u].size(); i++)
		{
			edge &e = g[u][i];
			if(dep[e.to]) continue;

			dep[e.to] = dep[u] + 1;
			d[e.to] = d[u] + e.cost;
			f[e.to][0] = u;
			for(int j = 1; j < 17; j++)
				f[e.to][j] = f[f[e.to][j - 1]][j - 1];
			q.push(e.to);
		}
	}
}

inline void jump(int u, int x)
{
	if(dep[u] == 2) return co[u].push_back(x), void();

	for(int t = 16; t >= 0; t--)
		if(f[u][t] && f[u][t] != 1 && d[f[u][t]] <= x) 
			x -= d[f[u][t]], u = f[u][t];
		
	co[u].push_back(x);
}

bool covered(int u, int fa)
{
	if(co[u].size()) return true;
	if(g[u].size() == 1) return false; 
	for(int i = 0; i < (int) g[u].size(); i++)
		if(g[u][i].to == fa) continue;
		else if(!covered(g[u][i].to, u)) return false;
	return true;
}

inline bool cmp1(const edge &lhs, const edge &rhs)
{return lhs.cost > rhs.cost;}

inline bool cmp2(const edge &lhs, const edge &rhs)
{return lhs.cost < rhs.cost;}

inline bool calc(int x)
{
	init();priority_queue<int> aval;
	for(int i = 0; i < (int) army.size(); i++)
		jump(army[i], x);

	for(int i = 0; i < (int) g[1].size(); i++)
		if(!covered(g[1][i].to, 1))
			unc.push_back(g[1][i]);

	for(int i = 0, v; i < (int) g[1].size(); i++)
		if(co[v = g[1][i].to].size() >= 2)
		{
			sort(co[v].begin(), co[v].end(), cmp2);
			for(int j = 1; j < (int) co[v].size(); j++)
			if(co[v][j] > g[1][i].cost) 
				aval.push(co[v][j] - g[1][i].cost);
		}
		
	sort(unc.begin(), unc.end(), cmp2);

	int cnt;
	for(int i = 0; i < (int) unc.size(); i++)
	{
		do
		{
			if(aval.empty()) return false;
			cnt = aval.top(); aval.pop();
		}while(cnt < unc[i].cost);
	}
	return true;
}

int main()
{
	//freopen("p1084.in", "r", stdin);
	cin>>N; int l = 0, r = 0;
	for(int i = 1, u, v, w; i < N; i++)
	{
		u = read(), v = read(), w = read();
		g[u].push_back(edge(v, w));
		g[v].push_back(edge(u, w));
		r += w;
	}

	cin>>M; bfs();
	
	for(int i = 1, u; i <= M; i++) 
		army.push_back(u = read());

	int _r = (r += 20);
	
	#define mid (((l) + (r)) >> 1)
	while(l < r)
	{
		if(calc(mid)) r = mid;
		else l = mid + 1;
	}

	if(l == _r) puts("-1"); 
	else cout<<l<<endl;
	return 0;
}
