#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e2 + 10;
inline int read(){
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M, K, Q;
int dis[MAXN][MAXN];

int main()
{
	cin>>N>>M>>K>>Q;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= N; i++) dis[i][i] = 0;
	for(int i = 1; i <= M; i++){
		int u = read(), v = read(), d = read();
		dis[u][v] = d;
	}

	for(int k = 1; k <= N; k++)
		for(int j = 1; j <= N; j++)
			for(int i = 1; i <= N; i++)
				if(dis[i][k] != INF && dis[k][j] != INF)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	long long ans = 0; int cnt = 0;
	while(Q--){
		int u = read(), v = read();
		int tmp = INF;
		for(int i = 1; i <= K; i++) tmp = min(tmp, dis[u][i] + dis[i][v]);
		// cout<<tmp<<endl;
		ans += (tmp == INF ? 0 : tmp);
		cnt += (tmp != INF);
	}
	cout<<cnt<<endl<<ans<<endl;
	return 0;
}