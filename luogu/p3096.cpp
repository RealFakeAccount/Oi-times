#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e4 + 10;
const int MAXK = 2e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M, K, Q;
int hub[MAXK];

struct edge
{
	int to, cost;
};vector<edge> g[MAXN], rg[MAXN];

inline bool tension(const int &st, int &lg){
	return st < lg ? (lg = st, true) : false;
}

int d[MAXK][2][MAXN];

void dijkstra(int idx, int *dis){
	priority_queue<P, vector<P>, greater<P> > q;
	q.push(P(0, hub[idx])); dis[hub[idx]] = 0;

	while(!q.empty()){
		P p = q.top(); q.pop();
		int u = p.second;
		if(dis[u] < p.first) continue;

		for(int i = 0; i < (int) g[u].size(); i++){
			edge &e = g[u][i];
			if(tension(dis[u] + e.cost, dis[e.to]))
				q.push(P(dis[e.to], e.to));
		}
	}
}

void rdijkstra(int idx, int *dis){
	priority_queue<P, vector<P>, greater<P> > q;
	q.push(P(0, hub[idx])); dis[hub[idx]] = 0;

	while(!q.empty()){
		P p = q.top(); q.pop();
		int u = p.second;
		if(dis[u] < p.first) continue;

		for(int i = 0; i < (int) rg[u].size(); i++){
			edge &e = rg[u][i];
			if(tension(dis[u] + e.cost, dis[e.to]))
				q.push(P(dis[e.to], e.to));
		}
	}
}

int done[MAXN];

int main()
{
	// freopen("p3096.in", "r", stdin);
	cin>>N>>M>>K>>Q;
	for(int i = 1; i <= M; i++){
		int u = read(), v = read(), d = read();
		g[u].push_back((edge){v, d});
		rg[v].push_back((edge){u, d});
	}
	for(int i = 1; i <= K; i++) hub[i] = read();
	for(int i = 1; i <= K; i++) done[hub[i]] = i;

	memset(d, 0x3f, sizeof(d));
	for(int i = 1; i <= K; i++) {
		dijkstra(i, d[i][0]);
		rdijkstra(i, d[i][1]);
	}

	int cnt = 0; long long ans = 0;
	while(Q--){
		int u = read(), v = read();
		int tmp = INF;
		if(done[u]) tmp = d[done[u]][0][v];
		else
			for(int i = 1; i <= K; i++)
				if(d[i][1][u] != INF && d[i][0][v] != INF)
					tmp = min(tmp, d[i][1][u] + d[i][0][v]);
		
		if(tmp != INF) ++cnt, ans += 1LL * tmp;
	}
	cout<<cnt<<endl<<ans<<endl;
	return 0;
}