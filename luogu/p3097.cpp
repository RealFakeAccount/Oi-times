#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 4e4 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, D;
int a[MAXN];

inline int max(int a, int b, int c) {return max(a, max(b, c));}


namespace stree
{
	#define mid ((l + r) >> 1)
	#define ls (o << 1)
	#define rs ((o << 1) | 1)

	int node[MAXN << 2][2][2];

	inline void pushup(int o){
		node[o][0][0] = max(
		node[ls][0][1] + node[rs][0][0], 
		node[ls][0][0] + node[rs][1][0]);
		
		node[o][1][0] = max(
		node[ls][1][0] + node[rs][1][0],
		node[ls][1][1] + node[rs][0][0]);
		
		node[o][0][1] = max(
		node[ls][0][1] + node[rs][0][1],
		node[ls][0][0] + node[rs][1][1]);

		node[o][1][1] = max(
		node[ls][1][0] + node[rs][1][1],
		node[ls][1][1] + node[rs][0][1]);
	}

	void modify(int o, int l, int r, int p, int v){
		if(l == r) return node[o][1][1] = v, void();
		if(p <= mid) modify(ls, l, mid, p, v);
		else modify(rs, mid + 1, r, p, v);
		return pushup(o);
	}

	void build(int o, int l, int r){
		if(l == r) return node[o][1][1] = a[l], void();
		build(ls, l, mid), build(rs, mid + 1, r);
		return pushup(o);
	}
}

int main()
{
	cin>>N>>D;
	for(int i = 1; i <= N; i++) a[i] = read();

	stree::build(1, 1, N);
	long long ans = 0;

	while(D--){
		int p = read(), v = read();
		stree::modify(1, 1, N, p, v);
		ans += max(max(stree::node[1][1][1], stree::node[1][0][1]), 
			max(stree::node[1][1][0], stree::node[1][0][0]));
	}
	cout<<ans<<endl;
	return 0;
}