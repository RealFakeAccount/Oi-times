#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 200 + 10;
const int MAXQ = 5e4 + 20;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int N, M, Q;
int time[MAXN];
int dis[MAXN][MAXN];

inline void floyd(int x)
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(dis[i][x] != INF && dis[x][j] != INF)
				dis[i][j] = min(dis[i][j], dis[i][x] + dis[x][j]);
}


int main()
{
	cin>>N>>M;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 0; i < N; i++) time[i] = read();
	for(int i = 0, u, v, c; i < M; i++){
		u = read(), v = read(), c = read();
		dis[u][v] = dis[v][u] = min(dis[u][v], c);
	}
	cin>>Q;
	int p = 0;
	while(Q--){
		int x = read(), y = read(), w = read();
		while(time[p] <= w && p < N) {
			floyd(p), ++p;
		}
		if(dis[x][y] == INF || time[x] > w || time[y] > w) puts("-1");
		else cout<<dis[x][y]<<endl;
	}
	return 0;
}
