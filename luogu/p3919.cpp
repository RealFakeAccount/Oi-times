#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
const int MAXN = 1e6 + 20;
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int N, M;

namespace stree
{
	#define mid (((l) + (r)) >> 1)
	struct Node *null;
	struct Node
	{
		int val;
		Node *ls, *rs;
		Node() : val(0), ls(null), rs(null) {}
	}pool[MAXN << 4], *pit = pool, root[MAXN];

	inline Node *newnode()
	{
		return new (pit++) Node();
	}

	void init()
	{
		null = newnode();
		null->ls = null->rs = null;
		null->val = 0;
		root[0] = Node();
	}

	Node *modify(const Node *o, int l, int r, int pos, int val)
	{
		Node *cur = newnode();
		*cur = *o;
		if(l == r) return cur->val = val, cur;
		if(pos <= mid) return cur->ls = modify(o->ls, l, mid, pos, val), cur;
		else return cur->rs = modify(o->rs, mid + 1, r, pos, val), cur;
	}

	int query(const Node *o, int l, int r, int pos)
	{
		if(l == r) return o->val;
		if(pos <= mid) return query(o->ls, l, mid, pos);
		else return query(o->rs, mid + 1, r, pos);
	}

	Node *build(int l, int r)
	{
		Node *cur = newnode();
		if(l == r) return cur->val = read(), cur;
		cur->ls = build(l, mid), cur->rs = build(mid + 1, r);
		return cur;
	}
}

int main()
{
	//freopen("p3919.in", "r", stdin);
	using namespace stree;
	cin>>N>>M; init();
	root[0] = *build(1, N);
	int ver = 0;
	while(M--)
	{
		int v = read(), type = read(), pos = read();
		if(type == 1) {
			root[++ver] = Node(); 
			root[ver] = *modify(&root[v], 1, N, pos, read());
		}
		else {
			root[++ver] = root[v];
			printf("%d\n", query(&root[ver], 1, N, pos)); 
		}
	}
	return 0;
}
