#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 10;
typedef pair<int, int> P;
inline int read(){
	int x = 0; char ch = getchar(); bool flag = false;
	while(!isdigit(ch)) flag |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return flag ? -x : x;
}

int N, D, K;
P a[MAXN];

namespace stree
{
	#define mid ((l + r) >> 1)
	#define ls (o << 1)
	#define rs ((o << 1) | 1)

	int node[MAXN];

	inline void init(){
		memset(node, -0x3f, sizeof(node));
	}

	inline void pushup(int o){
		node[o] = max(node[ls], node[rs]);
	}

	void modify(int o, int l, int r, int p, int v){
		if(l == r) return node[o] = v, void();
		if(p <= mid) modify(ls, l, mid, p, v);
		else modify(rs, mid + 1, r, p, v);
		return pushup(o);
	}

	int query(int o, int l, int r, int a, int b){
		if(l > b || r < a) return -INF;
		if(a <= l && r <= b) return node[o];
		return max(query(ls, l, mid, a, b), query(rs, mid + 1, r, a, b));
	}
	#undef mid
	#undef ls
	#undef rs
}

int f[MAXN];
bool check(int x){
	memset(f, 0, sizeof(f)); stree::init();
	stree::modify(1, 1, N, 1, 0);

	for(int i = 2; i <= N; i++){
		if(a[i].first - D + x < 0) continue;
		int l = upper_bound(a + 1, a + N + 1, P(max(a[i].first - D - x, 0), 0)) - a - 1;
		int r = upper_bound(a + 1, a + N + 1, P(min(a[i].first, a[i].first - D + x), 0)) - a - 1;
		f[i] = stree::query(1, 1, N, l, r) + a[i].second;
		if(f[i] >= K) return true;
		stree::modify(1, 1, N, i, f[i]);
	}
	return false;
}

int main()
{
	freopen("p3957.in", "r", stdin);
	cin>>N>>D>>K;
	for(int i = 1; i <= N; i++)
		a[i + 1].first = read(), a[i + 1].second = read();
	a[1] = P(0, 0); ++N;

	int l = 0, r = a[N].first + 1;
	while(l < r){
		int mid = ((l + r) >> 1);
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(l == a[N].first + 1) puts("-1");
	else cout<<l<<endl;
	return 0;
} 
