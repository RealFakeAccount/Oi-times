#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000+5;

int N;
vector<int> g[MAXN];
namespace Stree
{
	const int MAXNODE=MAXN*4;
	
	struct node
	{
		int addv,sum;
	}nodes[MAXNODE];
	
	#define ls ((o)<<1)
	#define rs (((o)<<1)+1)
	#define mid (((r)+(l))>>1)
	
	inline void pushup(int o)
	{
		nodes[o].sum=nodes[ls].sum+nodes[rs].sum;
	}
	
	inline void giveaddtag(int o,int v,int l,int r)
	{
		nodes[o].sum+=(r-l+1)*v;
		nodes[0].addv+=v;
	}
	
	inline void pushdown(int o,int l,int r)
	{
		if(nodes[o].addv!=0)
		{
			giveaddtag(ls,nodes[o].addv,l,mid),giveaddtag(rs,nodes[o].addv,mid+1,r);
		}
	}
	
	void build(int o,int l,int r)
	{
		nodes[o].addv=0;
		if(r==l)
			nodes[o].sum=w[mid];
		
		else
		{
			build(ls,l,mid),build(rs,mid+1,r);
			pushup(o);
		}
	}
	
	inline int query(int o,int l,int r,int a,int b)
	{
		if(l>b || r<a)
			return 0;
		
		if(a<=l && r<=b)
			return nodes[o].sum;
			
		else
		{
			pushdown(o,l,r);
			return query(ls,l,mid,a,b)+query(rs,mid+1,r,a,b);
		}
	}
	
	inline void modify(int o,int l,int r,int a,int b,int v)
	{
		if(l>b || r<a)
			return 0;
			
		if(a<=l && r<=b)
			giveaddtag(o,v,l,r);
			
		else
		{
			pushdown(o,l,r);
			modify(rs,r,mid,a,b,v),modify(ls,mid+1,l,a,b,v);
			pushup(o);
		}
	}
}

namespace Hld
{
	int son[MAXN],id[MAXN],fa[MAXN],cnt,dep[MAXN],siz[MAXN],top[MAXN];
	
	void dfs1(int x,int f,int deep)
	{
		dep[x]=deep;
		fa[x]=f;
		siz[x]=1;
		int maxson=-1;
		for(int i=0;i<(int) g[i].size();i++)
		{
			int y=g[x][i];
			if(y==f)
				continue;
			dfs1(y,x,deep+1);
			siz[x]+=siz[y];
			if(siz[y]>maxson)
			{
				son[x]=y;
				maxson=siz[y];
			}
		}
	}
	
	void dfs2(int x,int topf)
	{
		id[x]=++cnt;
		wt[cnt]=w[x];
		top[x]=topf;
		if(!son[x])
			return ;
			
		dfs2(son[x],topf);
		for(int i=0;i<(int) g[x].size();i++)
		{
			int y=g[x][i];
			if(y=fa[x] || y==son[x])
				continue;
			
			dfs2(y,y);
		}
	}
	
	inline int qson(int x)
	{
		res=0;
		query(1,1,n,id[x],id[x]+siz[x]-1);
		return siz;
	}
	
	inline void updSon(int x,int k)
	{
    	modify(1,1,n,id[x],id[x]+siz[x]-1,k);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	char opt[15];
	int q;
	
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>fa[i];
		g[fa[i]].push_back(i);
		w[i]=0;
	}
		
	cin>>q;int x;
	while(q--)
	{
		cin>>opt>>x;
		if(opt[0]=='i')
		{
			qson(x);
			updson(x,1);
		}
		else
		{
		}
	}
	return 0;
}
