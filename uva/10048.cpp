#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int MAXC = 1e2 + 10;
const int MAXS = 1e3 + 20;
const int INF = 0x3f3f3f3f;

inline int read()
{
	int x = 0; register char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M, Q;
int d[MAXC][MAXC];

inline void init()
{
	memset(d, 0x3f, sizeof(d));
	for(int i = 1; i <= N; i++)
		d[i][i] = 0;
}

inline void solve()
{
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
}

int main()
{
	//freopen("10048.in", "r", stdin);
	int T = 0;
	while(cin>>N>>M>>Q, N != 0)
	{
		T++;
		init();

		if(T > 1) puts("");
		printf("Case #%d\n", T);

		register int u, v;
		for(int i = 1; i <= M; i++)
		{
			u = read(), v = read();
			d[u][v] = d[v][u] = read();
		}

		solve();

		
		for(int i = 1; i <= Q; i++)
		{
			u = read(), v = read();
			if(d[u][v] == INF) {puts("no path"); continue;}
			printf("%d\n", d[u][v]);
		}

		
	}
	return 0;
}