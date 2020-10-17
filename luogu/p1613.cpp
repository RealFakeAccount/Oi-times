#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 50 + 2;

int N, M;
bool d[MAXN][MAXN][63];
int f[MAXN][MAXN];

int main()
{
	cin>>N>>M;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1, u, v; i <= M; i++){
		scanf("%d%d", &u, &v);
		d[u][v][0] = 1, f[u][v] = 1;
	}
	
	for(int p = 1; p < 63; p++)
		for(int k = 1; k <= N; k++)
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= N; j++)
					if(d[i][k][p - 1] && d[k][j][p - 1])
						d[i][j][p] = 1, f[i][j] = 1;
	
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	cout<<f[1][N]<<endl;
	return 0;
}