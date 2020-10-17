#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 5e4 + 10;
const int MOD = 1e9 + 7;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, Q;
int a[MAXN], b[MAXN], c[MAXN];

namespace TB
{
	#define mid ((l + r) >> 1)
	#define ls (o << 1)
	#define rs ((o << 1) | 1)

	int node[MAXN];

	inline void pushup(int o){
		node[o] = (1LL * node[ls] * node[rs]) % MOD;
	}

	void build(int o, int l, int r){
		if(l == r) return node[o] = read(), void();
		build(ls, l, mid), build(rs, mid + 1, r);
		return pushup(o);
	}

	void modify(int o, int l, int r, int p, int v){
		if(l == r) return node[o] = v, void();
		if(p <= mid) modify(ls, l, mid, p, v);
		else modify(rs, mid + 1, r, p, v);
		return pushup(o);
	}
}

int main()
{
	cin>>N>>Q;
	for(int i = 1; i <= N; i++) a[i] = read();
	for(int i = 1; i <= N; i++) b[i] = read();

	for(int i = 1; i <= N; i++)
		c[i] = max(c[i - 1], a[i]);

	while(Q--){
		int opt = read(), x = read(), y = read();
		if(opt == 0) {
			a[x] = y;
			for(int i = x; i <= N; i++) c[i] = max(c[i - 1], a[i]);
			int ans = 1;
			for(int i = 1; i <= N; i++) 
				ans = (1LL * ans * min(b[i], c[i])) % MOD;
			printf("%d\n", ans);
		}
		else {
			b[x] = y;
			int ans = 1;
			for(int i = 1; i <= N; i++)
				ans = (1LL * ans * min(b[i], c[i])) % MOD;
			printf("%d\n", ans);
		}
	}
	return 0;
}