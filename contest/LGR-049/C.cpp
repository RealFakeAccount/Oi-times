#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 20;
const int MAXL = 1e2 + 10;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int N, M, K, L;
int a[MAXN], r[MAXL];

struct Round
{
	int w, x, v;
	bool operator <(const Round &rhs) const{
		return w < rhs.w;
	}
}round[MAXN];

namespace stree
{
	#define mid (((l) + (r)) >> 1)
	#define ls ((o) << 1)
	#define rs (((o) << 1) | 1)

	struct Node{
		int val, tag;
		inline void pushup(int o){
			val = ls->val + rs->val;
		}
	}node[MAXN << 2];

	inline void givetag(int o, int v){
		node[o].val += v, node[o].tag += v;
	}

	inline void pushdown(int o, int l, int r)
	{
		if(node[o].tag != 0){
			int &v = node[o].tag;
			givetag(ls, v), givetag(rs, v);
			v = 0;
		}
	}

	void build(int o, int l, int r)
	{
		if(l == r) return node[o].val = a[l], void();
		build(ls, l, mid), build(rs, mid + 1, r);
		return node[o].pushup(o);
	}

	int query(int o, int l, int r, int a, int b)
	{
		if(l > r) return 0;
		if(a <= l && r <= b) return node[o].val;
		return query(ls, l, mid, a, b) + query(rs, mid + 1, r, a, b);
	}

	void modify(int o, int l, int r, int a, int b, int v)
	{
		if(l > r) return ;
		if(a <= l && r <= b) return givetag(o, v);
		return modify(ls, l, mid, a, b), modify(rs, mid + 1, r, a, b);
	}
	#undef mid
	#undef ls
	#undef rs
}

inline bool check(int l)
{	
	using namespace stree;
	stree::build(1, 1, N);

	for(int i = 1; i <= )

	bool flag = false; int p = 1;
	for(int i = 1; i <= l; i++){
		while(query(1, 1, N, p, p) > 0 && p <= N) ++p;
		if(p == N) {flag = true; break;}
		modify(1, 1, N, p, p + K - 1, 1);
	}
	return flag;
}

int main()
{
	cin>>N>>M>>K>>L;
	for(int i = 1; i <= N; i++) a[i] = read();
	for(int i = 1; i <= L; i++) r[i] = read();
	for(int i = 1, w, x, v; i <= M; i++){
		w = read(), x = read(), v = read();
		round[i] = (Round) {w, x, v};
	}
	sort(round + 1, round + M + 1);
	int l = 0, r = (1 << 20);
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout<<l<<endl;
	return 0;
}