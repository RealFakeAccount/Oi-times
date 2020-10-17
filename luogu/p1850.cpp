#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e3 + 20;
const int MAXM = MAXN;
const int MAXV = 3e2 + 10;
const int INF = 0x3f3f3f3f;

int N, M, V, E;
int dis[MAXV][MAXV];
int C[MAXN], D[MAXN];
double K[MAXN], f[MAXN][MAXN][2]; 

void init()
{
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 0; i <= N; i++) for(int j = 0; j <= M; j++)
	f[i][j][0] = f[i][j][1] = 1e30;
}

void floyd()
{
	for(int k = 1; k <= V; k++)
		for(int i = 1; i <= V; i++)
			for(int j = 1; j <= V; j++)
				if(dis[i][k] != INF && dis[k][j] != INF)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(int i = 1; i <= V; i++) dis[i][i] = 0;
}

int main()
{
	cin>>N>>M>>V>>E; init();
	
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &D[i]);
	for(int i = 1; i <= N; i++) scanf("%lf", &K[i]);
	for(int i = 1, u, v, w; i <= E; i++){
		scanf("%d%d%d", &u, &v, &w);
		dis[u][v] = min(dis[u][v], w);
		dis[v][u] = min(dis[v][u], w);
	}
	floyd();
	f[1][0][0] = f[1][1][1] = 0.0;
	for(int i = 2; i <= N; i++){
		for(int j = 0; j <= M; j++){
			f[i][j][0] = min(
				f[i - 1][j][0] 
				+ dis[ C[i - 1] ][ C[i] ],
				f[i - 1][j][1]
				+ dis[ D[i - 1] ][ C[i] ] * K[i - 1] 
				+ dis[ C[i - 1] ][ C[i] ] * (1.0 - K[i - 1]) );
			if(j) f[i][j][1] = min(
				f[i - 1][j - 1][0] 
				+ dis[ C[i - 1] ][ D[i] ] * K[i]
				+ dis[ C[i - 1] ][ C[i] ] * (1.0 - K[i]),
				f[i - 1][j - 1][1] 
				+ dis[ C[i - 1] ][ C[i] ] * (1.0 - K[i - 1]) * (1.0 - K[i])
				+ dis[ C[i - 1] ][ D[i] ] * (1.0 - K[i - 1]) * K[i] 
				+ dis[ D[i - 1] ][ C[i] ] * K[i - 1] * (1.0 - K[i])
				+ dis[ D[i - 1] ][ D[i] ] * K[i] * K[i - 1]
				);
		}
	}
	double ans = INF;
	for(int i = 0; i <= M; i++) ans = min(ans, min(f[N][i][0], f[N][i][1]));
	printf("%.2lf", ans); 
	return 0;
}