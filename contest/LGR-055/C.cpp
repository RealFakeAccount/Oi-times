#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M;
int val[(1 << 20)], cnt[(1 << 20)];
long long f[(1 << 20)];

long long dp(int state) {
	if(f[state] != -1) return f[state];

	f[state] = 0;
	for(int i = state; i; i = state & (i - 1)) 
		if(i != state) (f[state] += dp(i) + 1LL * val[state] * cnt[i]) %= MOD, ++cnt[state];
	(f[state] += dp(0) + val[state]) %= MOD; ++cnt[state];
	return f[state];
}

int main()
{
	freopen("C.in", "r", stdin);
	cin>>N>>M;
	for(int i = 1; i <= M; i++) {
		int tmp = 0; scanf(" ");
		for(int j = N - 1; j >= 0; j--) 
			tmp |= ((getchar() - '0') << j);
		val[tmp] = read();
	}
	memset(f, 0xff, sizeof(f));

	f[0] = val[0], cnt[0] = 1;
	cout<<dp((1 << N) - 1)<<endl;
	return 0;
}
