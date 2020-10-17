#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 20;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, Q;
int a[MAXN], c[80], cnt = 0;

namespace stree
{
	int node[MAXN << 2];
	#define mid (((l) + (r)) >> 1)
	#define ls ((o) << 1)
	#define rs (((o) << 1) | 1)

	inline void pushup(int o)
	{
		node[o] = min(node[ls], node[rs]);
	}

	void build(int o, int l, int r)
	{
		if(l == r) return node[o] = a[l], void();
		build(ls, l, mid), build(rs, mid + 1, r);
		return pushup(o), void();
	}

	void modify(int o, int l, int r, int p, int v)
	{
		if(p == l && p == r) return node[o] = v, void();
		if(p <= mid) modify(ls, l, mid, p, v);
		else modify(rs, mid + 1, r, p, v);
		return pushup(o), void();
	}

	int query(int o, int l, int r, int a, int b)
	{
		if(r < a || l > b) return 0x3f3f3f3f;
		if(a <= l && r <= b) return node[o];
		return min(query(ls, l, mid, a, b), query(rs, mid + 1, r, a, b));
	}
}

void solve()
{
	int tmp = a[c[1]];
	for(int i = 1; i < cnt; i++) 
	{
		a[c[i]] = a[c[i + 1]];
		stree::modify(1, 1, N, c[i], a[c[i + 1]]);
	}
	a[c[cnt]] = tmp;
	stree::modify(1, 1, N, c[cnt], tmp);
}

int main()
{
	//freopen("12299.in", "r", stdin);
	//freopen("12299.out", "w", stdout);
	using namespace stree;
	while(cin>>N>>Q)
	{
		char ch[60];
		for(int i = 1; i <= N; i++) a[i] = read();
		build(1, 1, N);
		int l, r;
		for(int i = 1; i <= Q; i++)
		{
			scanf(" %[^(]", ch);
			if(ch[0] == 'q')
			{
				scanf("(%d,%d)", &l, &r);
				printf("%d\n", query(1, 1, N, l, r));
			}
			if(ch[0] == 's')
			{
				char d; cnt = 0; d = getchar();
				while(true)
				{
					if(d == ')') break;
					if(isdigit(d)){
						int x = 0;
						while(isdigit(d)) x = x * 10 + d - '0', d = getchar();
						c[++cnt] = x;
					}
					else d = getchar();
				}
				solve();
			}
		}
	}
	return 0;
}
