#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;

int N, a[MAXN];
bool f[MAXN][MAXN][MAXN * 9];
int sum[MAXN];

int main()
{
	cin>>N; scanf(" ");
	for(int i = 1; i <= N; i++) a[i] = getchar() - '0';
	for(int i = 1; i <= N; i++) f[i][i][a[i]] = true;
	for(int i = 1; i <= N; i++) sum[i] = sum[i - 1] + a[i];
	for(int i = N; i >= 1; i--)
		for(int j = i + 1; j <= N; j++)
			for(int p = i + 1; p <= j; p++){
				if(sum[j] - sum[p - 1] == sum[p - 1] - sum[i - 1])
					f[i][j][sum[j] - sum[p - 1]] = true;
				for(int k = 0; k <= 900; k++)	
					f[i][j][k] |= f[i][p - 1][k] & f[p][j][k];
			}
	for(int i = 0; i <= 900; i++)
		if(f[1][N][i]) return puts("YES"), 0;
	puts("NO");
	return 0;
}
