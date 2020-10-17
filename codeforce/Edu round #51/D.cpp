#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAXN = 1e3 + 10;

int N, K;
ll f[MAXN][MAXN << 1][4];

int main()
{
	cin>>N>>K;
	f[1][1][0] = f[1][1][3] = 1;
	f[1][2][1] = f[1][2][2] = 1;
	for(int i = 1; i < N; i++){
		memset(f[(i + 1) & 1], 0, sizeof(f[(i + 1) & 1]));
		for(int k = 1; k <= K; k++){
			f[(i + 1) & 1][k][0] += f[i & 1][k][0];
			f[(i + 1) & 1][k + 1][1] += f[i & 1][k][0];
			f[(i + 1) & 1][k + 1][2] += f[i & 1][k][0];
			f[(i + 1) & 1][k + 1][3] += f[i & 1][k][0];

			f[(i + 1) & 1][k][0] += f[i & 1][k][1];
			f[(i + 1) & 1][k][1] += f[i & 1][k][1];
			f[(i + 1) & 1][k + 2][2] += f[i & 1][k][1];
			f[(i + 1) & 1][k][3] += f[i & 1][k][1];

			f[(i + 1) & 1][k][0] += f[i & 1][k][2];
			f[(i + 1) & 1][k + 2][1] += f[i & 1][k][2];
			f[(i + 1) & 1][k][2] += f[i & 1][k][2];
			f[(i + 1) & 1][k][3] += f[i & 1][k][2];

			f[(i + 1) & 1][k + 1][0] += f[i & 1][k][3];
			f[(i + 1) & 1][k + 1][1] += f[i & 1][k][3];
			f[(i + 1) & 1][k + 1][2] += f[i & 1][k][3];
			f[(i + 1) & 1][k][3] += f[i & 1][k][3];

			for(int m = 0; m < 3; m++)
				for(int n = 0; n < 4; n++)
					f[(i + 1) & 1][k + m][n] %= MOD;
		}
	}
	cout<<(f[N & 1][K][0] + f[N & 1][K][1] + f[N & 1][K][2] + f[N & 1][K][3]) % MOD<<endl;
	return 0;
}
