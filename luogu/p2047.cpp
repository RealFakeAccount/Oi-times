#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int dis[MAXN][MAXN];ll cnt[MAXN][MAXN];
int N, M;

int main()
{
	cin>>N>>M;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1, u, v, c; i <= M; i++){
		u = read(), v = read(), c = read();
		dis[u][v] = dis[v][u] = c;
	}
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++) cnt[i][j] = 1LL;
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++){
				if(dis[i][k] + dis[k][j] < dis[i][j]){
					cnt[i][j] = cnt[i][k] * cnt[k][j];
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				else if(dis[i][k] + dis[k][j] == dis[i][j]) cnt[i][j] += cnt[i][k] * cnt[k][j];
			}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++) 
			cout<<cnt[i][j]<<" ";
		cout<<endl;
	}
	for(int k = 1; k <= N; k++){
		double ans = 0;
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++) if(i != j){
				if(dis[i][j] == dis[i][k] + dis[k][j])
					if(cnt[i][k] * cnt[k][j] != 0)
						ans += ((double)cnt[i][k] * cnt[k][j]) / ((double)cnt[i][j]);
			}
		printf("%.3lf\n", ans);
	}
	return 0;
}