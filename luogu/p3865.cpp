#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 20;
int N, M;

inline int read()
{
	static int x;
	scanf("%d", &x);
	return x;
}

namespace stree
{
	#define ls ((o) << 1)
	#define rs (((o) << 1) + 1)
	#define mid (((l) + (r)) >> 1)

	int node[MAXN << 2];

	void pushup(int o)
	{
		node[o] = max(node[ls], node[rs]);
	}

	void build(int o, int l, int r)
	{
		if(l > r) return;

		if(l == r)
		{
			node[o] = read();
			return;
		}

		build(ls, l, mid),
		build(rs, mid+1, r);
		pushup(o);
		return;
	}

	int query(int o, int l, int r, int a, int b)
	{
		if(l > b || r < a) return 0;
		if(a <= l && r <= b) return node[o];
		return max(query(ls, l, mid, a, b),
				   query(rs, mid+1, r, a, b));
	}
}

int main()
{
	//freopen("p3865.txt","r",stdin);
	cin>>N>>M;
	stree::build(1, 1, N);

	int a, b;
	while(M--)
	{
		scanf("%d%d",&a, &b);
		printf("%d\n", stree::query(1, 1, N, a, b));
	}
	return 0;
}