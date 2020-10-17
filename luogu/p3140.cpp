#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int MAXN = 1e2 + 5;

int N, K;
ll f[MAXN][7 + 2];
int a[MAXN << 1];
ll cost[MAXN << 1][MAXN << 1];

int main()
{
	cin>>N>>K;
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for(int i = N + 1; i <= (N << 1); i++) a[i] = a[i - N];
	for(int i = 1; i <= (N << 1); i++){
		for(int j = i + 1; j <= (N + i + 1); j++){
			cost[i][j] = cost[i][j - 1] + (j - i) * a[j];
		}
	}

	ll ans = (1LL << 62);
	for(int p = N; p < (N << 1); p++){
		memset(f, 0x7f, sizeof(f));
		for(int i = 1; i <= N; i++) f[i][1] = cost[p - N + 1][p - N + i];

		for(int i = 1; i <= N; i++){
			for(int k = 1; k <= K; k++)
				for(int j = 1; j < i; j++){
					f[i][k] = min(f[i][k], 
					f[j][k - 1] + cost[p - N + j + 1][p - N + i]);
					// if(j == i - 1) assert(cost[p - N + j + 1][p - N + i] == 0);
				} 
		}
		ans = min(ans, f[N][K]);
	}
	cout<<ans<<endl;
	return 0;
}