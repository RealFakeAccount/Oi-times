#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, K;

struct Seg
{
	int l, r, val;
	bool operator >(const Seg &rhs) const {
		return val > rhs.val;
	}
}seg[MAXN];

namespace stree
{
	#define mid ((l + r) >> 1)
	#define ls (o << 1)
	#define rs ((o << 1) | 1)

	struct Node
	{
		int val, tag;
	}node[MAXN << 2];

	inline void pushup(int o) {
		node[o].val = node[ls].val + node[rs].val;
	}

	inline void givetag(int o, int l, int r) {
		node[o].tag = 1;
		node[o].val = (r - l + 1);
	}

	inline void pushdown(int o, int l, int r) {
		int &v = node[o].tag; if(!v) return;
		givetag(ls, l, mid), givetag(rs, mid + 1, r);
		v = 0;
	}

	int query(int o, int l, int r, int a, int b) {
		if(l > b || r < a) return 0;
		if(a <= l && r <= b) return node[o].val;
		pushdown(o, l, r);
		return query(ls, l, mid, a, b) + query(rs, mid + 1, r, a, b);
	}

	void modify(int o, int l, int r, int a, int b) {
		if(l > b || r < a) return ;
		if(a <= l && r <= b) return givetag(o, l, r);
		pushdown(o, l, r);
		modify(ls, l, mid, a, b), modify(rs, mid + 1, r, a, b);
		return pushup(o);
	}
	#undef mid
	#undef ls
	#undef rs
}

Seg tmp[MAXN];
inline bool check(int x) {
	using namespace stree;
	memcpy(tmp, seg, (x + 1) * sizeof(Seg));
	sort(tmp + 1, tmp + x + 1, greater<Seg>()); 
	memset(node, 0, ((N + 1) << 2) * sizeof(Node));
	for(int i = 1; i <= x; i++) {
		int lmin = tmp[i].l, lmax = tmp[i].l, rmin = tmp[i].r, rmax = tmp[i].r;
		while(i + 1 <= x && tmp[i].val == tmp[i + 1].val) {
			++i;
			lmin = min(lmin, tmp[i].l), rmin = min(rmin, tmp[i].r);
			lmax = max(lmax, tmp[i].l), rmax = max(rmax, tmp[i].r);
		}
		if(lmax > rmin) return false;
		if(query(1, 1, N, lmax, rmin) == rmin - lmax + 1) return false;
		modify(1, 1, N, lmin, rmax);
	}
	return true;
}

int main()
{
	cin>>N>>K;
	for(int i = 1; i <= K; i++)
		seg[i].l = read(), seg[i].r = read(), seg[i].val = read();
	int l = 1, r = K + 1;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	printf("%d\n", l);
	return 0;
}
