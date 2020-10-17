#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline int readInt()
{
	static int n, ch;
	n = 0, ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
	return n;
}

const int MAX_N = 100000 + 3;

namespace LinkCutTree
{
	const int MAX_NODE = MAX_N;

#define lc ch[0]
#define rc ch[1]

	extern struct Node *null;
	struct Node
	{
		Node *fa, *ch[2];
		bool tagReversed;
		int c, val, sum;

		inline void maintain()
		{
			if (this == null) return;
			sum = lc->sum + rc->sum + val;
		}

		inline void reverse()
		{
			if (this == null) return;
			swap(lc, rc);
			c = c == -1 ? -1 : c ^ 1;
			tagReversed ^= 1;
		}

		inline void pushDown()
		{
			if (tagReversed)
			{
				lc->reverse(), rc->reverse();
				tagReversed = false;
			}
		}

		inline bool isRoot() const
		{
			return fa == null || (fa->lc != this && fa->rc != this);
		}
	} pool[MAX_NODE], *null;

	void init(int n, int *v)
	{
		null = new Node();
		null->fa = null, null->lc = null->rc = null, null->sum = 0;
		for (int i = 0; i < n; ++i)
		{
			pool[i].fa = pool[i].lc = pool[i].rc = null;
			pool[i].tagReversed = false;
			pool[i].val = pool[i].sum = v[i];
		}
	}

	void rotate(Node *&o, int d)
	{
		Node *k = o->ch[d ^ 1];
		k->fa = o->fa, o->fa = k, k->ch[d]->fa = o;
		o->ch[d ^ 1] = k->ch[d], k->ch[d] = o;
		o->maintain(), k->maintain();
		o = k;
	}

	void _splay(Node *&o)
	{
		o->pushDown();
		if (o->c != -1)
		{
			Node *p = o->ch[o->c];
			p->pushDown();

			if (p->c != -1)
			{
				_splay(p->ch[p->c]);
				if (o->c == p->c) rotate(o, o->c ^ 1);
				else rotate(o->ch[o->c], o->c);
			}

			rotate(o, o->c ^ 1);
		}
	}

	void splay(Node *o)
	{
		o->c = -1;
		while (!o->isRoot())
		{
			if (o->fa->lc == o) o->fa->c = 0;
			else o->fa->c = 1;
			o = o->fa;
		}
		_splay(o);
	}

	Node *access(Node *o)
	{
		Node *k = null;
		while (o != null)
		{
			splay(o);
			o->rc = k;
			o->maintain();
			k = o;
			o = o->fa;
		}

		while (k->lc != null) k = k->lc;
		return k;
	}

	inline void makeRoot(Node *o)
	{
		access(o), splay(o);
		o->reverse();
	}

	inline void link(Node *u, Node *v)
	{
		makeRoot(u);
		u->fa = v;
	}

	inline Node *leftest(Node *v)
	{
		while (v->lc != null) v = v->lc;
		return v;
	}

	inline void cut(Node *u, Node *v)
	{
		makeRoot(u), access(v), splay(u);
		if (leftest(u->rc) == v)
		{
			u->rc->fa = null, u->rc = null;
			u->maintain();
		}
	}

	inline int sum(Node *u, Node *v)
	{
		makeRoot(u), access(v), splay(u);
		return u->sum;
	}

	inline bool connected(Node *u, Node *v)
	{
		return access(u) == access(v);
	}

	inline void link(int u, int v)
	{
		if (!connected(pool + u, pool + v))
			link(pool + u, pool + v);
	}

	inline void cut(int u, int v)
	{
		cut(pool + u, pool + v);
	}

	inline int sum(int u, int v)
	{
		return sum(pool + u, pool + v);
	}

	inline bool connected(int u, int v)
	{
		return connected(pool + u, pool + v);
	}

#undef lc
#undef rc
}

int n, m, v[MAX_N];

int main()
{

	n = readInt(), m = readInt();
	for (int i = 0; i < n; ++i) v[i] = readInt();

	LinkCutTree::init(n, v);

	int x,y;
	for (int i = 0; i < m; ++i)
	{
		int opt;
		opt=readInt();
		cin>>opt>>x>>y;
		if(opt==0)
			cout<<LinkCutTree::sum(x,y)<<endl;
		else if(opt==1)
			LinkCutTree::connected(x,y);
		else if(opt==2)
			LinkCutTree::cut(x,y);
		else if(opt==3)
		{
			cin>>x>>y;
		LinkCutTree::	splay(*&x);
			x.sum=y;
			x.maintain();
		}
		
	}

}

return 0;
}

