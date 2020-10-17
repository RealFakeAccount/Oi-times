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

int N;
namespace stree
{
	#define mid (((l) + (r)) >> 1)
	#define ls ((o) << 1)
	#define rs (((o) << 1) | 1)

	struct _node
	{
		int mx, mn;
		int tag; bool isleaf;
	}node[MAXN << 2];
	
	inline void givetag(int o, int v)
	{
		node[o].mx = node[o].mn = v;
		node[o].tag = v;
	}

	inline void pushup(int o)
	{
		node[o].mx = max(node[ls].mx, node[rs].mx);
		node[o].mn = min(node[ls].mn, node[rs].mn);
	}

	inline void pushdown(int o, int l, int r)
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
		givetag(o, 0);
		if(l == r){
			node[o].isleaf = true;
			return ;
		}
		build(ls, l, mid), build(rs, mid + 1, r);
		node[o].isleaf = false;
		return ;
	}

	int modify(int o, int l, int r, int a, int b, int h)
	{
		if(r < a || l > b) return 0;
		if(node[o].mn > h) return 0;
		if(a <= l && r <= b){
			if(node[o].isleaf){
				if(node[o].mx <= h){
					node[o].mx = node[o].mn = h;
					return 1;
				}
			}
			if(node[o].mx <= h){
				givetag(o, h);
				return r - l + 1;
			}
		}
		pushdown(o, l, r);
		int tmp = modify(ls, l, mid, a, b, h) + modify(rs, mid + 1, r, a, b, h);
		pushup(o);
		return tmp;
	}
}

int main()
{
	using namespace stree;
	int T, t = 0; cin>>T;
	while(T--)
	{
		t++; cin>>N;
		build(1, 1, MAXN);
		int ans = 0;
		for(int i = 1, l, r, h; i <= N; i++)
		{
			l = read(), r = read() - 1, h = read();
			ans += modify(1, 1, MAXN, l, r, h);
		}
		cout<<ans<<endl;
	}
	read();
	return 0;
}