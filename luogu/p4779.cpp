#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

struct edge
{
	int to, cost;
};vector<edge> g[MAXN];

int N, M, S;

int dis[MAXN]; bool vis[MAXN]
void dijkstra(){
	priority_queue<P, vector<P>, greater<P> > q;
	memset(dis, 0x7f, sizeof(dis));
	dis[S] = 0; q.push(P(0, S));
	while(!q.empty()){
		P p = q.top(); q.pop();
		int u = p.second;
		//if(dis[u] < p.first) continue;

		if(vis[u]) continue;
		vis[u] = true;

		for(int i = 0; i < (int) g[u].size(); i++){
			edge &e = g[u][i];
			if(dis[e.to] > dis[u] + e.cost){
				dis[e.to] = dis[u] + e.cost;
				q.push(P(dis[e.to], e.to));
			}
		}
	}
}

int main()
{
	cin>>N>>M>>S;
	for(int i = 1; i <= M; i++) {
		int u = read(), v = read(), c = read();
		g[u].push_back((edge){v, c});
	}
	dijkstra();
	for(int i = 1; i <= N; i++) printf("%d ", dis[i]);
	return 0;
}