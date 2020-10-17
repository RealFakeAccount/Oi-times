#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6+1e2;
const int MAXB = 30*MAXN;

int N,t1,t2,t3;

namespace Stree
{
	#define mid (((l) + (r)) >> 1 )

	extern struct node *null;
	struct node
	{
		bool B,B_,Htag;//have tag
		node *ls,*rs;
		node() : B(false), B_(true), Htag(false), ls(null), rs(null) {}
	}pool[MAXN << 4],*pit = pool,*null = new node();

	inline node *newnode()
	{
		static int cnt = 0;
		if( cnt < (MAXN << 4) )
			return new (pit++) node();
		else return new node();
	}

	void init()
	{
		null->ls = null->rs = null;
		null->B = null->Htag = false;	
		null->B_ = true;
	}
	
	inline void pushdown(node *o)
	{
		if(o->ls == null) o->ls = newnode();
		if(o->rs == null) o->rs = newnode();

		if(o->Htag)
		{
			o->ls->B = o->B;
			o->rs->B = o->B;
			o->ls->B_ = o->rs->B_ = o->B_;
			o->ls->Htag = o->rs->Htag = true;
	
			o->Htag = false;
		}
	}
	
	inline void pushup(node *o)
	{
		if(o->ls == null) o->ls = newnode();
		if(o->rs == null) o->rs = newnode();
			
		if(o->ls->B == true && o->rs->B == true)
			o->B = true;
		else o->B = false;

		if(o->ls->B_ == true && o->rs->B_ == true)
			o->B_ = true;
		else o->B_ = false;
	}

	inline int query(node *o,int l,int r,int a,int b)
	{
		if(l > b || r < a) return false;
		if(a <= l && r <= b)
			 return o->B;
		else
		{
			pushdown(o);
			if(mid < a) return query(o->rs, mid+1, r, a, b);
			if(b <= mid) return query(o->ls, l, mid, a, b);
			else return query(o->ls, l, mid, a, b) & query(o->rs, mid+1, r, a, b);
		}
	
	}

	inline void modify(node *o,int l,int r,int a,int b,bool v)
	{
		if(l > b || r < a) return;
		if(a <= l && r <= b) o->B = (v == 1), o->B_ = (v == 0), o->Htag = true;

		else
		{
			pushdown(o);
			modify(o->ls, l, mid, a, b, v),modify(o->rs, mid+1, r, a, b, v);
			pushup(o);
		}
	}

	inline node *prezero(node *o,int l,int r,int p)
	{
		pushdown(o);
		if(l == r && o->B == false) 
		{	//cout<<l<<endl;
			return o;}


		if(o->ls->B == true) return prezero(o->rs, mid+1, r, p);
		if(p < mid) return prezero(o->ls, l, mid, p);//if p == mid ? 
		else return prezero(o->rs, mid+1, r, p);
	}

	inline node *preone(node *o,int l,int r,int p)
	{
		pushdown(o);
		if(l == r && o->B == true)
		{//cout<<l<<endl;
			return o;
		}	

		if(o->ls->B_ == true) return preone(o->rs, mid+1, r, p);
		if(p < mid) return preone(o->ls, l, mid, p);
		else return preone(o->rs, mid+1, r, p);
	}
}

inline int lowbit(int x)
{
	return x&(-x);
}

using namespace Stree;
int main()
{
	//freopen("p3822.txt","r",stdin);
	init();
	cin>>N;

	node *root = newnode();
	int opt,a,b;
	while(N--)
	{
		scanf("%d",&opt);
		if(opt == 1)
		{
			scanf("%d%d",&a, &b);
			if(a == 0) continue;

			if(a > 0)
			{
				while(b > 0)
				{
					
					b -= lowbit(b);
				}
			}
		}
		if(opt == 2)
		{
			scanf("%d",&a);
			printf("%d",query(root,1,MAXB,a,a));
		}
	}
	return 0;
}
