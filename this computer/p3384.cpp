#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100000+2;

int b[MAXN];
int N,M;
namespace Stree
{
	const int MAXNODE=MAXN*4;
	struct node 
	{
		int addv,sum;	
	}nodes[MAXNODE];
	
	#define ls ((o)<<1)
	#define rs (((o)<<1)+1)
	#define mid (((l)+(r))>>1)
	
	inline void pushup(int o)
	{
		nodes[o].sum=nodes[ls].sum+nodes[rs].sum;
	}
	
	inline void givetagadd(int o,int v,int l,int r)
	{
		nodes[o].sum+=(r-l+1)*v;
		nodes[o].addv+=v;
	}
	
	inline void pushdown(int o,int l,int r)
	{
		if(nodes[o].addv!=0)
		{
			givetagadd(ls,nodes[o].addv,l,mid),givetagadd(rs,nodes[o].addv,mid+1,r);
			nodes[o].addv=0;
		}
	}
	
	void build(int o,int l,int r)
	{
		nodes[o].addv=0;
		
		if(l==r) 
			nodes[o].sum=b[mid];
		
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
			return ;
		
		if(a<=l && r<=b)
			givetagadd(o,v,l,r);
			
		else
		{
			pushdown(o,l,r);
			modify(ls,l,mid,a,b,v),modify(rs,mid+1,r,a,b,v);
			pushup(o);
		}
	}
} 

namespace Hld
{
	int deep[MAXN],fa[MAXN],son[MAXN],tot[MAXN];
	vector<int> g[MAXN];
	
	int dfs1(int now,int f,int dep)
	{
		deep[now]=dep;
		fa[now]=f;
		tot[now]=1;
		int maxson=-1;
		for(int i=0;i<(int) g[now].size();i++)
		{
			int y=g[now][i];
			if(y==f)
				continue;
				
			tot[now]+=dfs1(y,now,dep+1);
			if(tot[y]>maxson)
				maxson=tot[y],son[now]=y;
		}
		return tot[now];
	}
	
	int idx[MAXN],cnt,a[MAXN],top[MAXN];
	void dfs2(int now,int topf)
	{
		idx[now]=++cnt;
		a[cnt]=b[now];
		top[now]=topf;
		if(!son[now])
			return;
		dfs2(son[now],topf);
		for(int i=0;i<(int) g[now].size();i++)
		{
			int y=g[now][i];
			if(!idx[y])
				dfs2(y,y);
		}
	}
	
	void updp(int x,int v)
	{
		Stree::modify(1,1,N,idx[x],idx[x],v);
		return;
	}
	
	
	void updr(int x,int v)
	{
		Stree::modify(1,1,N,idx[x],idx[x]+tot[x]-1,v);
		return; 
	}
	
	int quep(int x)
	{
		return Stree::query(1,1,N,idx[x],idx[x]);
	}
	
	int quer(int x)
	{
		int res=0;
		if(deep[top[x]]==1)
			return Stree::query(1,1,N,idx[top[x]],idx[x]);
		
		while(deep[x]!=1)
		{
			res+=Stree::query(1,1,N,idx[top[x]],idx[x]);
			x=fa[top[x]];
		}
		res+=Stree::query(1,1,N,idx[top[x]],idx[x]);
		return  res;
	}
	
}
using namespace Hld;
main()
{
//	freopen("p3384.txt","r",stdin);
	ios::sync_with_stdio(false);
	int M;
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
		cin>>b[i];
	
	int x,y,z;
	for(int i=1;i<=N-1;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs1(1,1,1);
	dfs2(1,1);
	Stree::build(1,1,N);
	

	while(M--)
	{
		cin>>x;
		switch(x)
		{
			case 1:
				cin>>y>>z;
				updp(y,z);
				break;
			case 2:
				cin>>y>>z;
				updr(y,z);
				break;
			case 3:
				cin>>y;
				cout<<quer(y)<<endl;
				break;
		}
	//	cout<<"============="<<endl;
	//	for(int i=1;i<=N;i++)
	//		cout<<quep(i)<<" ";
	//		cout<<endl;
	//	cout<<"============="<<endl;
	}
	return 0;
}
