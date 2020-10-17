#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;
const int MAXN = 1e5 + 200;

int N, M, R, P;
int dep[MAXN], fa[MAXN], son[MAXN], siz[MAXN];
int idx[MAXN], top[MAXN], w[MAXN];
int a[MAXN];
vector<int> g[MAXN];//to

inline int read()
{
	static int x;
	scanf("%d", &x);
	return x;
}

inline void addedge(int x, int y)
{
	g[x].push_back(y);
	g[y].push_back(x);
}

namespace stree
{
	#define ls ((o) << 1)
	#define rs (((o) << 1) + 1)
	#define mid (((l) + (r)) >> 1)

	struct nodes
	{
		int sum, addv;
		nodes(int s = 0,int a = 0) : sum(s), addv(a) {} 
		inline void givetag(int v)
		{
			sum += v, addv += v;
		}
	}node[MAXN << 2];

	inline void pushup(int o)
	{
		node[o].sum = (node[ls].sum + node[rs].sum) % P;
	}

	inline void pushdown(int o)
	{
		if(node[o].addv)
		{
			int &v =node[o].addv;

			node[ls].givetag(v),
			node[rs].givetag(v);

			v = 0;
		}
	}

	void build(int o, int l, int r)
	{
		if(l == r) node[o] = nodes(w[l] % P, 0);

		build(ls, l, mid), build(rs, mid+1, r);
		pushup(o);
	}

	void modify(int o, int l, int r, int a, int b, int v)
	{
		if(l > b || r < a) return ;
		if(a <= l && r <= b) {node[o].givetag(v);return;}

		pushdown(o);
		modify(ls, l ,mid, a, b, v), modify(rs, mid + 1, r, a, b, v);
		pushup(o);
	}

	int query(int o, int l, int r, int a, int b)
	{
		if(l > b || r < a) return 0;
		if(a <= l && r <= b) return node[o].sum;

		pushdown(o);
		return (query(ls, 1, mid, a, b) + query(rs, mid + 1, r, a, b)) % P;
	}
}

namespace Hld
{
	int dfs1(int cur, int f, int deep)
	{
		dep[cur] = deep;
		fa[cur] = f;
		siz[cur] = 1;
		int maxson = -1;

		for(int i = 0; i < (int) g[cur].size(); i++)
		{
			int &v = g[cur][i];
			if(v == f) continue;
			siz[cur] += dfs1(v, cur, deep + 1);

			if(siz[v] > maxson) son[cur] = v, maxson = siz[v];
		}
		return siz[cur];
	}

	void dfs2(int cur, int topf)
	{
		static int cnt = 1;
		idx[cur] = cnt++;
		top[cur] = topf;
		w[cnt] = a[cur];
		if(!son[cur]) return;

		dfs2(son[cur], topf);
		for(int i = 0; i <(int) g[cur].size(); i++)
		{
			int &v = g[cur][i];
			if(!idx[v]) dfs2(v, v);
		} 
	}

	inline int Qsum(int x, int y)
	{
		int ans = 0;
		while(top[x] != top[y])
		{
			if(dep[top[x]] < dep[top[y]])
				swap(x, y);
			ans = (ans + stree::query(1, 1, N, idx[top[x]], idx[x])) % P;
			x = fa[top[x]];
		}
		if(dep[x] < dep[y]) swap(x, y);
		ans = (ans + stree::query(1, 1, N, idx[y], idx[x])) % P;
		return ans; 
	}

	inline void Asum(int x, int y, int v)
	{
		while(top[x] != top[y])
		{
			if(dep[top[x]] < dep[top[y]]) swap(x, y);
			stree::modify(1, 1, N, idx[top[x]], idx[x], v);
			x = fa[top[x]];
		}
		if(dep[x] < dep[y]) swap(x, y);
		stree::modify(1, 1, N, idx[y], idx[x], v);
	}

	inline void Atree(int root, int v)
	{
		stree::modify(1, 1, N, idx[root], idx[root] + siz[root] - 1, v % P);
	}

	inline int Qtree(int root)
	{
		return stree::query(1, 1, N, idx[root], idx[root] + siz[root] -1);
	}
}


int main()
{
	freopen("p3384.txt", "r",stdin);
	
	cin>>N>>M>>R>>P;
	for(int i = 1; i <= N; i++)
		a[i] = read();

	for(int i = 1; i <= (N - 1); i++)
		addedge(read(), read());

	Hld::dfs1(1, 1, 1);
	Hld::dfs2(1, 1);
	int opt;
	while(M--)
	{
		opt = read();
		if(opt == 1) Hld::Asum(read(), read(), read());
		if(opt == 2) printf("%d\n", Hld::Qsum(read(), read()));
		if(opt == 3) Hld::Atree(read(), read());
		if(opt == 4) printf("%d\n", Hld::Qtree(read()));
		else assert("ERROR");
	}
	return 0;
}