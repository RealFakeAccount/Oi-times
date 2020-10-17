#include <bits/stdc++.h>
using namespace std;

const int MAXN=100000+3;

namespace Treap
{
	const int MAXNODE=100000+3;

	struct node
	{
		int key, val, s;
		node *ls, *rs;

		inline void maintain()
		{
			s = ls->s + rs->s + 1;
		}
	} pool[MAXNODE],*pit,*null;

	void init()
	{
		pit = pool;
		null = new node();
		null->s = 0;
	}

	inline node *newnode(int v)
	{
		pit->key = v, pit->val = rand();
		pit->s = 1, pit->ls = pit->rs = null;
		return pit++;
	}
	
	node* merge(node* a,node* b)
	{
		if(a==null)
			return b;
		if(b==null)
			return a;
		
		if(a->val < b->val)
		{
			a->rs=merge(a->rs,b);
			a->maintain();
			return a;
		}
		
		else
		{
			b->ls=merge(a,b->ls);
			b->maintain();
			return b;
		}
	}
	
	typedef pair<node*,node*> droot;
	droot split(node *o,int k)
	{
		droot d(null,null);
		if(o==null)
			return d;
		
		int s=o->ls->s;
		if(k<=s)
		{
			d=split(o->ls,k);
			o->ls=d.second;
			o->maintain();
			d.second=o;
		}
		else
		{
			d=split(o->rs,k-s-1);
			o->rs=d.first;
			o->maintain();
			d.first=o;
		}
		return d;
	}
	
	int findkth(const node *o,int k)
	{
		if(o==null || k<=0 || k>o->s)
			return 0;
			
		int s=o->ls->s;
		if(s+1==k)
			return o->key;
		else if(k<=s)
			return findkth(o->ls,k);
		else 
			return findkth(o->rs,k-s-1);
	}
	
	int lowercount(const node *o,int v)//the key of the last number which less than v
	{
		if(o==null)
			return 0;
		return v<=o->key ? lowercount(o->ls,v) : lowercount(o->rs,v)+o->ls->s+1;
	}
	
	int uppercount(const node *o,int v)//the key of the last number which less than or equal to v
	{
		if(o==null)
			return 0;
		return v<o->key ? uppercount(o->ls,v) : uppercount(o->rs,v)+o->ls->s+1;
	}
	
	inline void insert(node *&root, int v) //find,spilt,merge,merge
	{
		int x=lowercount(root, v);
		droot l=split(root, x);
		root=merge(merge(l.first, newnode(v)), l.second);
	}

	inline void erase(node *&root, int v)//find,spilt,spilt,merge
	{
		int x=lowercount(root, v);
		droot l=split(root, x), r=split(l.second,1);
		root=merge(l.first, r.second);
	}

	inline int pred(const node *root, int v) 
	{
		return findkth(root, lowercount(root, v));
	}

	inline int succ(const node *root, int v) {
		return findkth(root, uppercount(root, v)+1);
	}
}

using namespace Treap;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	init();
	node *root=null;
	int x,opt;
	while(n--)
	{
		cin>>opt>>x;
		switch(opt)
		{
			case(1):
				insert(root,x);
				break;
			
			case(2):
				erase(root,x);
				break;
				
			case(3):
				cout<<lowercount(root,x)+1<<endl;
				break;
				
			case(4):
				cout<<findkth(root,x)<<endl;
				break;
			
			case(5):
				cout<<pred(root,x)<<endl;
				break;
				
			case(6):
				cout<<succ(root,x)<<endl;
				break;
		}
	}
	return 0;
}

