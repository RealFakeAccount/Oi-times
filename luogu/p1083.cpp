#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int MAXN = 1e6 + 20;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M;

namespace stree
{
	#define mid (((l) + (r)) >> 1)
	#define ls ((o) << 1)
	#define rs (((o) << 1) | 1)

	struct _node
	{
		int mx, tag; 
		_node() : mx(0), tag(0) {}
	}node[MAXN << 2];

	inline void pushup(int o)
	{
		node[o].mx = min(node[ls].mx, node[rs].mx);
	}

	inline void givetag(int o, int v)
	{
		node[o].mx -= v, node[o].tag += v;
	}

	inline void pushdown(int o)
	{
		if(node[o].tag)
		{
			int &v = node[o].tag;
			givetag(ls, v), givetag(rs, v);
			v = 0;
		}
	}

	void build(int o, int l, int r)
	{
		if(l == r) return node[o].mx = read(), void();
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(o);
	}

	void modify(int o, int l, int r, int a, int b, int v)
	{
		if(l > b || r < a) return;
		if(a <= l && r <= b) return givetag(o, v), void();
		pushdown(o);
		modify(ls, l, mid, a, b, v), modify(rs, mid + 1, r, a, b, v);
		return pushup(o), void();
	}
}

int main()
{
	//freopen("p1083.in", "r", stdin);
	cin>>N>>M;
	stree::build(1, 1, N);

	for(int i = 1, d, s, t; i <= M; i++)
	{
		d = read(), s = read(), t = read();
		stree::modify(1, 1, N, s, t, d);
		if(stree::node[1].mx < 0) {
			puts("-1");cout<<i<<endl; return 0;
		}

	}
	puts("0");
	return 0;
}
