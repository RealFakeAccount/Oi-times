#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e4 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M;
vector<int> g[MAXN];

int fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN];
int dfs1(int u, int f, int d) {
	fa[u] = f, dep[u] = d, siz[u] = 1;

	int tmp = -1;
	for(int i = 0; i < (int) g[u].size(); i++) {
		int &v = g[u][i];
		if(v == fa) continue;
		siz[u] += dfs1(v, u, d + 1);

		if(tmp == -1 || siz[v] > siz[tmp]) tmp = v;
	}
	son[u] = tmp; return siz[u];
}

int idx[MAXN], top[MAXN];
void dfs2(int u, int t) {
	static int dfsclock = 0;
	idx[u] = ++dfsclock, top[u] = t;

	if(son[u] == -1) return;
	dfs2(son[u], t);
	for(int i = 0; i < (int) g[u].size(); i++) {
		int &v = g[u][i];
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}

struct stree
{
	#define mid ((l + r) >> 1)
	#define ls (o << 1)
	#define rs ((o << 1) | 1)

	struct Node {
		int val, tag;
	}node[MAXN << 2];

	inline void pushup(int o) {
		node[o].val = node[ls].val + node[rs].val;
	}

	inline void givetag(int o, int l, int r, int v) {
		node[o].val += (r - l + 1) * v, node[o].tag += v;
	}

	inline void pushdown(int o, int l, int r) {
		int &v = node[o].tag;
		if(v == 0) return;
		givetag(ls, l, mid, v), givetag(rs, mid + 1, r, v);
		v = 0;
	}

	void build(int o, int l, int r) {
		if(l == r) return node[o].val = 1, void();
		build(ls, l, mid), build(rs, mid + 1, r);
		return pushup(o);
	}

	void modify(int o, int l, int r, int a, int b, int v) {
		if(l > b || r < a) return ;
		if(a <= l && r <= b) return givetag(o, l, r, v);
		pushdown(o, l, r);
		modify(ls, l, mid, a, b, v), modify(rs, mid + 1, r, a, b, v);
		return pushup(o);
	}

	int query(int o, int l, int r, int a, int b) {
		if(l > b || r < a) return 0;
		if(a <= l && r <= b) return node[o].val;
		pushdown(o, l, r);
		return query(ls, l, mid, a, b) + query(rs, mid + 1, r, a, b);
	}
}Tree[3];

int main()
{
	cin>>N;
	for(int i = 1; i < N; i++) {
		int u = read(), v = read();
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs1(1, 0, 1), dfs2(1, 1);
	cin>>M; Tree[0].build(1, 1, N);
	while(M--) {
		int Type = read();
		if(Type == 1) {
			int x = read(), y = read(), col = read();
			int ans = 0;
			while(top[x] != top[y]) {
				if(dep[x] < dep[y]) swap(x, y);
				ans += Tree[col].query(1, 1, N, idx[top[x]], idx[x]);
				x = fa[top[x]];
			}
			if(dep[x] < dep[y]) swap(x, y);
			ans += Tree[col].query(1, 1, N, idx[y], idx[x]);
			ans -= Tree[col].query(1, 1, N, idx[y], idx[y]);
		}
		else if(Type == 2) {
			int x = read(), y = read(), col1 = read(), col2 = read();

		}
		else {
			int root = read(), 
		}
	}
	return 0;
}