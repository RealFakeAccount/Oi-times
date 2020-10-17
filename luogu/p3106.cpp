#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e4 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

struct edge
{
	int to, cost;
};

int N, M;
vector<edge> ga[MAXN], gb[MAXN];
vector<edge> rga[MAXN], rgb[MAXN];

inline bool tension(const int &st, int &lg){
	return st < lg ? (lg = st, true) : false;
}

int dis[2][MAXN];
void dijkstra0(){
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<P, vector<P>, greater<P> > q[2];
	dis[0][1] = dis[1][1] = 0;
	q[1].push(P(0, 1)), q[0].push(P(0, 1));

	while(!q[0].empty()){
		P p = q[0].top(); q[0].pop();
		int u = p.second;
		if(dis[0][u] < p.first) continue;

		for(int i = 0; i < (int) ga[u].size(); i++){
			edge &e = ga[u][i];
			if(tension(dis[0][u] + e.cost, dis[0][e.to]))
				q[0].push(P(dis[0][e.to], e.to));
		}
	}

	while(!q[1].empty()){
		P p = q[1].top(); q[1].pop();
		int u = p.second;
		if(dis[1][u] < p.first) continue;

		for(int i = 0; i < (int) gb[u].size(); i++){
			edge &e = gb[u][i];
			if(tension(dis[1][u] + e.cost, dis[1][e.to]))
				q[1].push(P(dis[1][e.to], e.to));
		}
	}
}

bool vis[MAXN][2];
void dfs0(int cur){
	vis[cur][0] = true;
	for(int i = 0; i < (int) rga[cur].size(); i++){
		edge &e = rga[cur][i];
		if(dis[0][e.to] + e.cost == dis[0][cur]) dfs0(e.to);
	}
}

void dfs1(int cur){
	vis[cur][1] = true;
	for(int i = 0; i < (int) rgb[cur].size(); i++){
		edge &e = rgb[cur][i];
		if(dis[1][e.to] + e.cost == dis[1][cur]) dfs1(e.to);
	}
}

int d[MAXN];
void dijkstra1(){
	priority_queue<P, vector<P>, greater<P> > q;
	memset(d, 0x3f, sizeof(d));
	q.push(P(0, 1)); d[1] = 0;
	while(!q.empty()){
		P p = q.top(); q.pop();
		int u = p.second;
		if(d[u] < p.first) continue;

		for(int i = 0; i < (int) ga[u].size(); i++){
			edge &e = ga[u][i];
			if(d[e.to] > d[u] + !vis[e.to][0] + !vis[e.to][1]){
				d[e.to] = d[u] + !vis[e.to][0] + !vis[e.to][1];
				q.push(P(d[e.to], e.to));
			}
		}
	}
}

int main()
{
	freopen("p3106.in", "r", stdin);
	cin>>N>>M;
	for(int i = 1; i <= M; i++){
		int u = read(), v = read(), a = read(), b = read();
		ga[u].push_back((edge){v, a}); gb[u].push_back((edge){v, b});
		rga[v].push_back((edge){u, a}); rgb[v].push_back((edge){u, b});
	}
	dijkstra0();
	dfs0(N), dfs1(N);
	dijkstra1();
	cout<<d[N]<<endl;
	return 0;
}