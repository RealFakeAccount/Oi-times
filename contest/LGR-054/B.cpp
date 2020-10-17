#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
const int MAXN = 1e3 + 10;
const int MAXV = 2e4 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, a[MAXN];
int f[MAXN][MAXV];
int dp(int u, int v, int cnt) {
	if(f[u][v] != -1) return f[u][v];

	f[u][v] = (cnt != 1);
	for(int i = u + 1; i <= N; i++) if(a[u] - a[i] == v) 
		f[u][v] = (1LL * f[u][v] + dp(i, v, cnt + 1)) % MOD;
}

int main()
{
	cin>>N;
	int mx = 0;
	for(int i = 1; i <= N; i++) mx = max(mx, a[i] = read());
	memset(f, 0xff, sizeof(f));
	long long ans = 0;
	for(int i = 0; i <= a[1]; i++) (ans += dp1(1, i)) %= MOD;
	for(int i = 0; i <= mx; i++) (ans += dp2(1, i)) %= MOD;
	cout<<ans<<endl;
	return 0;
}