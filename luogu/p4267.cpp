#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;

int N, a[MAXN];
int f[MAXN][MAXN], cnt[MAXN][MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++) scanf(" %d", &a[i]);

	for(int i = 1; i <= N; i++){
		int tmp = 0;
		for(int j = i; j <= N; j++) {
			if(a[j] != j - i) ++tmp;
			cnt[i][j] = tmp;
		}
	}
	
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= i; j++)
			for(int k = 0; k < i; k++)
				f[i][j] = min(f[i][j], f[k][j - 1] + cnt[k + 1][i]);
	for(int i = 1; i <= N; i++)
		printf("%d\n", f[N][i]);
	return 0;
}