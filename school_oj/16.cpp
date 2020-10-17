#include <bits/stdc++.h>
using namespace std;

const int MAXN=100000+2;

inline int read()
{
	static int T;
	scanf("%d",&T);
	return T;
}

int N,a[MAXN],P;

namespace Segment_tree
{
	typedef long long ll;
	struct  node
	{
		ll sum,addv,mulv;
		node *ls,*rs;
		node () : sum(0),addv(0),mulv(1),ls(NULL),rs(NULL) {}
		inline void pushup()
		{
			this->sum=(this->ls->sum+this->rs->sum)%P;
		}
	}pool[MAXN<<2];

	#define mid (((l)+(r))>>1)

	inline node *newnode()//实际没什么用的动态开点
	{
		static int cnt=0;
		if(cnt<(MAXN<<2))
			return &pool[cnt++];
		else return new node;
	}

	node *build(node *o,int l,int r)
	{
		if(!o)
			o=newnode();
		if(l==r)
			o->sum=a[mid];
		else
		{
			o->ls=build(o->ls,l,mid),o->rs=build(o->rs,mid+1,r);
			o->pushup();
		}
		return o;
	}

	inline void givetagmul(node *o,int v)
	{
		(o->sum *= v)%=P;
		(o->mulv *= v)%=P;
		(o->addv *= v)%=P;
	}

	inline void givetagadd(node *o,int v,int l,int r)
	{
		(o->sum += (ll) (r-l+1)*v%P ) %=P;
		(o->addv += v) %=P;
	}

	inline void pushdown(node *o,int l,int r)
	{
		if(o->mulv!=1 && o)
		{
			givetagmul(o->ls,o->mulv),givetagmul(o->rs,o->mulv);
			o->mulv=1;
		}
		if(o->addv!=0 && o)
		{
			givetagadd(o->ls,o->addv,l,mid),givetagadd(o->rs,o->addv,mid+1,r);
			o->addv=0;
		}
	}

	int query(node *o,int l,int r,int a,int b)
	{
		if(l>b || r<a) return 0;
		if(a<=l && r<=b) return o->sum;
		else
		{
			pushdown(o,l,r);
			return (ll)(query(o->ls,l,mid,a,b)+query(o->rs,mid+1,r,a,b))%P;
		}
	}

	void modify(node *o,int l,int r,int a,int b,int v,bool type)//0-*,1->+
	{
		if(l>b || r<a) return ;
		if(a<=l && r<=b)
		{
			if (type == 0) givetagmul(o, v);
			else givetagadd(o, v, l, r);
		}
		else
		{
			pushdown(o, l, r);
			modify(o->ls, l, mid, a, b, v, type),
			modify(o->rs, mid+1, r, a, b, v, type);
			o->pushup();	
		}
	}
}

using namespace Segment_tree;

int main()
{
	N=read(),P=read();
	for(int i=1;i<=N;i++)
		a[i]=read();
	int Q=read();
	node *root=newnode();
	build(root,1,N);
	while(Q--)
	{
		int opt=read(),a=read(),b=read();
		switch (opt)
		{
			case 1: {modify(root,1,N,a,b,read(),0);break;}
			case 2: {modify(root,1,N,a,b,read(),1);break;}
			case 3: {printf("%d\n", query(root,1,N,a,b));break;}
		}
	}
	return 0;
}
