#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e4 + 20;

int N, M;
struct Edge
{
	int to, cost;
};vector<Edge> g[MAXN];

bool vis[MAXN];
int dis[MAXN];

bool spfa(int cur){
	vis[cur] = true;
	for(int i = 0; i < (int) g[cur].size(); i++){
		Edge &e = g[cur][i];
		if(dis[e.to] < dis[cur] + e.cost){
			if(vis[e.to]) return true;
			dis[e.to] = dis[cur] + e.cost;
			if(spfa(e.to)) return true;
		}
	}
	vis[cur] = false ;
	return false;
}

int main()
{
	//freopen("p1993.in", "r", stdin);
	cin>>N>>M;
	for(int i = 1, u, v, c, t; i <= M; i++){
		scanf("%d%d%d",&t, &u, &v);
		if(t == 1) scanf("%d", &c), g[v].push_back((Edge){u, c});
		else if(t == 2) scanf("%d", &c), g[v].push_back((Edge){u, -c});
		else g[u].push_back((Edge){v, 0}), g[v].push_back((Edge){u, 0});
	}
	for(int i = 1; i <= N; i++) g[0].push_back((Edge){i, 0});
	memset(dis, -0x3f, sizeof(dis)); dis[0] = 0;
	if(spfa(0)) puts("No");
	else puts("Yes");
	return 0;
}