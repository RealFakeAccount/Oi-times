#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e4 + 20;
const int MAXM = MAXN;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M;
int a[MAXN];
vector<int> ds;

namespace stree
{
	#define mid (((l) + (r)) >> 1)

	struct node *null;
	struct node
	{  
		int siz;
		node *ls, *rs;
		node() : siz(0), ls(null), rs(null) {}
		inline void pushup(){
			this->siz = ls->siz + rs->siz;
		}
	}pool[MAXN << 4], root[MAXN], *pit = pool;

	inline node *newnode()
	{
		static int cnt = 0;
		if(cnt < (MAXN << 4)){
			++cnt; return new (pit++) node();
		}
		return new node();
	}

	void init(){
		null = newnode();
		null->ls = null->rs = null;
		null->siz = 0;
	}

	node *modify(const node *o, int l, int r, int v)
	{
		node *cur = newnode();
		*cur = *o;
		if(l == r) return cur->siz++, cur;
		if(v <= mid) cur->ls = modify(o->ls, l, mid, v);
		else cur->rs = modify(o->rs, mid + 1, r, v);
		
		return cur->pushup(), cur;
	}

	int query(node *lhs, node *rhs, int l, int r, int k)
	{
		if(l == r) return ds[l - 1];
		int s = rhs->ls->siz - lhs->ls->siz;
		if(k <= s) return query(lhs->ls, rhs->ls, l, mid, k);
		else return query(lhs->rs, rhs->rs, mid + 1, r, k - s);
	}

	#undef mid
}

using namespace stree;

void discrete()
{
	for(int i = 1; i <= N; i++) ds.push_back(a[i]);
	sort(ds.begin(), ds.end());
	ds.erase(unique(ds.begin(), ds.end()), ds.end());

	root[0] = null;
	for(int i = 1; i <= N; i++)
		root[i] = modify(root[i - 1], 1, ds.size(), 
			upper_bound(ds.begin(), ds.end(), a[i]) - ds.begin());
}

int main()
{
	cin>>N>>M; stree::init();
	for(int i = 1; i <= N; i++) a[i] = read();
	discrete();
	for(int i = 1, l, r, k; i <= M; i++){
		char ch;
		scanf(" %c", &ch);
		if(ch == 'Q'){
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", stree::query(root[l - 1], root[r], 1, ds.size(), k)); 
		}
		else {
			scanf("%d%d", &l, &k);
			stree::modify(root[l], 1, ds.size(), k);
		}
	}
	return 0;
}