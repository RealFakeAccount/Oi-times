#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 3e4 + 20;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to, cost;	
};

int N, H;
vector<Edge> g[MAXN];
int dis[MAXN];
bool inq[MAXN];

int main()
{
	cin>>N>>H;
	for(int i = 1, u, v, c; i <= H; i++){
		scanf("%d%d%d", &u, &v, &c);
		 g[u - 1].push_back((Edge){v, c});
	}
	for(int i = 0; i <= N; i++){
		if(i) g[i - 1].push_back((Edge){i, 0});
		if(i != N) g[i].push_back((Edge){i - 1, -1});
	}
	memset(dis, -0x3f, sizeof(dis));
	dis[0] = 0;
	queue<int> q;
	q.push(0);	
	while(!q.empty())
	{
		int u = q.front(); q.pop(); inq[u] = false;
		for(int i = 0; i < (int) g[u].size(); i++){
			Edge &e = g[u][i];
			if(dis[e.to] < dis[u] + e.cost){
				dis[e.to] = dis[u] + e.cost;
				if(!inq[e.to]) q.push(e.to), inq[e.to] = true;
			}
		}
	}
	cout<<dis[N]<<endl;
	return 0;
}