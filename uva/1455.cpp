#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e5 + 20;
const int MAXX = 1e6 + 20;

int N, M, lsty;
P a[MAXN];

namespace stree
{
	#define mid (((l) + (r)) >> 1)
	#define ls ((o) << 1)
	#define rs (((o) << 1) | 1)
	struct _node
	{
		int sum, num;
		int tags, tagn;
		inline void init(){
			sum = num = 0;
			tags = tagn = 0;
		}
	}node[MAXX << 2];

	void refresh(int o, int l, int r)
	{
		if(l == r) return (node[o].init());
		refresh(ls, l, mid), refresh(rs, mid + 1, r);
		node[o].init();
		return ;
	}

	inline void pushup(int o){
		node[o].sum = node[ls].sum + node[rs].sum;
		node[o].num = node[ls].num + node[rs].num;
	}

	inline void givetag(int o, int v, bool type){
		if(type) {
			node[o].tags += v,
			node[o].sum += v;
		}
		else node[o].tagn += v,
			node[o].num += v;
	}

	inline void pushdown(int o, int l, int r)
	{
		if(node[o].tags != 0){
			int &v = node[o].tags;
			givetag(ls, v, 1), givetag(rs, v, 1);
			v = 0;
		}
		if(node[o].tagn != 0){
			int &v = node[o].tagn;
			givetag(ls, v, 0), givetag(rs, v, 0);
			v = 0;
		}
	}

	P query(int o, int l, int r, int p)
	{
		if(l == r) return P(node[o].sum, node[o].num);
		pushdown(o, l, r);
		if(p <= mid) return query(ls, l, mid, p);
		else return query(rs, mid + 1, r, p);
	}

	void modify(int o, int l, int r, int a, int b, P v)
	{
		if(l > b || r < a || l > r) return;
		if(a <= l && r <= b) 
			return (givetag(o, v.first, 1), givetag(o, v.second, 0));
		modify(ls, l, mid, a, b, v), modify(rs, mid + 1, r, a, b, v);
		pushup(o);
		return ;
	}
}

namespace ufs
{
	struct _node
	{
		int fa, up, down, siz;
		inline void init(int i, int y){
			fa = i, up = down = y, siz = 1;
		}
	}node[MAXN];

	inline void init(){for(int i = 1; i <= N; i++) node[i].init(i, a[i].second);}

	int findfa(int x){return node[x].fa == x ? x : node[x].fa = findfa(node[x].fa);}

	void unite(int x, int y){
		using namespace stree;
		int u = findfa(x), v = findfa(y);
		if(u == v) return ; 
		if(node[u].siz > 1) modify(1, 1, lsty, node[u].down + 1, node[u].up, P(-node[u].siz, -1));
		if(node[v].siz > 1) modify(1, 1, lsty, node[v].down + 1, node[v].up, P(-node[v].siz, -1));
		if(node[u].siz < node[v].siz) {
			node[u].fa = v;
			node[v].siz += node[u].siz;
			node[v].up = max(node[u].up, node[v].up);
			node[v].down = min(node[u].down, node[v].down);
			modify(1, 1, lsty, node[v].down + 1, node[v].up, P(node[v].siz, 1));
		}
		else{
			node[v].fa = u;
			node[u].siz += node[v].siz;
			node[u].up = max(node[u].up, node[v].up);
			node[u].down = min(node[u].down, node[v].down);
			modify(1, 1, lsty, node[u].down + 1, node[u].up, P(node[u].siz, 1));
		}
	}
}

int main()
{
	int T; cin>>T;
	while(T--)
	{
		lsty = 0;
		char ch[15];
		cin>>N;
		for(int i = 0; i < N; i++)
			scanf("%d%d", &a[i].first, &a[i].second), lsty = max(lsty, a[i].second);
		cin>>M; double v;
		ufs::init(); stree::refresh(1, 1, lsty);
		for(int i = 1, x, y; i <= M; i++)
		{
			scanf(" %[^0-9]", ch);
			if(ch[0] == 'r') {
				scanf("%d%d", &x, &y);
				ufs::unite(x + 1, y + 1);
			}
			else {
				scanf("%lf", &v);
				if((int) v >= lsty) puts("0 0");
				else{
					P ans = stree::query(1, 1, lsty, (int) v + 1);
					printf("%d %d\n", ans.second, ans.first);}
			}
		}
	}
	return 0;
}
