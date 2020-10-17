#include <cstdio>
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 400 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, K;
int f[MAXN][MAXN];
int a[MAXN], sum[MAXN];

namespace stree
{
	#define ls ((o) << 1)
	#define rs (((o) << 1) | 1)
	#define mid ((l + r) >> 1)

	int node[MAXN];

	void build(int o, int l, int r) {
		if(l == r) return node[o] = a[l], void();
		build(ls, l, mid), build(rs, mid + 1, r);
		return node[o] = max(node[ls], node[rs]), void();
	}

	int query(int o, int l, int r, int a, int b) {
		if(a <= l && r <= b) return node[o];
		if(l > b || r < a) return 0;
		return max(query(ls, l, mid, a, b), query(rs, mid + 1, r, a, b));
	}
}

int query(int l, int r) {
	// return stree::query(1, 1, N, a, b) * (b - a + 1) - (sum[b] - sum[a - 1]);
	int mx = 0;
	for(int i = l; i <= r; i++) mx = max(mx, a[i]);
	return mx * (r - l + 1) - (sum[r] - sum[l - 1]);
}

int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	cin>>N>>K; ++K;
	memset(f, 0x3f, sizeof(f)); f[0][0] = 0;

	for(int i = 1; i <= N; i++) a[i] = read();
	for(int i = 1; i <= N; i++) sum[i] = sum[i - 1] + a[i];
	stree::build(1, 1, N);

	for(int i = 1; i <= N; i++) 
		for(int j = 0; j < i; j++) 
			for(int k = 1; k <= min(i, K); k++) 
				if(f[j][k - 1] != f[0][1])  f[i][k] = min(f[i][k], f[j][k - 1] + query(j + 1, i));
	printf("%d\n", f[N][K]);
	return 0;
}