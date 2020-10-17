#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 20;

int N, M;
int a[MAXN];vector<int> cp;

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

namespace stree
{
	#define mid (((l) + (r)) >> 1)

	struct node *null;
	struct node
	{
		int siz;
		node *ls, *rs;
		node() : siz(0), ls(null), rs(null) {}
		inline void pushup()
		{
			this->siz = ls->siz + rs->siz;
		}
	}pool[MAXN << 4], *root[MAXN], *pit = pool;

	inline node *newnode()
	{
		static int cnt = 0;
		if(cnt < (MAXN << 4))
		{cnt++; return new (pit++) node();}
		return new node();
	}

	void init()
	{
		null = newnode();
		null->ls = null->rs = null;
		null->siz = 0;
	}
	
	node *modify(const node *o, int l, int r, int v)
	{
		if(l > r) return null;
		node *cur = newnode();
		*cur = *o;
		
		if(l == r)
		{
			cur->siz++;
			return cur;
		}

		if(v <= mid) cur->ls = modify(o->ls, l ,mid, v);
		else cur->rs = modify(o->rs, mid + 1, r, v);

		cur->pushup();
		return cur;
	}

	int query(node *a, node *b, int l ,int r, int k)
	{
		if(l > r) return 0;
		if(l == r) return cp[l - 1];

		int s = b->ls->siz - a->ls->siz;
		if(k <= s) return query(a->ls, b->ls, l, mid, k);
		else return query(a->rs, b->rs, mid + 1, r, k - s);
	}
	#undef mid
}

using namespace stree;
void compress_build()
{
	for(int i = 1; i <= N; i++)
		cp.push_back(a[i]);

	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());

	root[0] = newnode();
	for(int i = 1; i <= N; i++)
	{
		root[i] = newnode();
		root[i] = modify(root[i - 1], 1, cp.size(), 
		(lower_bound(cp.begin(), cp.end(), a[i]) - cp.begin() + 1) );
	}	
}

int main()
{
	//freopen("p3834.txt", "r", stdin);
	//freopen("test.txt", "w", stdout);
	cin>>N>>M;
	
	for(int i = 1; i <= N; i++)
		a[i] = read();

	init();
	compress_build();

	int l, r;
	while(M--)
	{
		l = read(); r = read();
		printf("%d\n", query(root[l - 1], root[r], 1, cp.size(), read()));
	}
	return 0;
}
