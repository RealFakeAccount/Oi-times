#include <bits/stdc++.h>
using namespace std;
const int MAXM=200000+5;

int M,D;

namespace segment_tree
{
	struct node
	{
		int ans;
	}nodes[MAXM*4];
	
#define ls ( ( (o) << 1 ) )
#define rs ( ( (o) << 1 ) + 1 )
#define mid ( ( (l) + (r) ) >> 1)

	inline void pushup(int o)
	{
		nodes[o].ans=max(nodes[ls].ans,nodes[rs].ans);
	}
	
	void build(int n)
	{
		while(n--)
		{
			nodes[n].ans=-INT_MAX;
		}
	}
	
	inline void change(int o,int v)
	{
		nodes[o].ans=max(nodes[o].ans,v);
	}
	
	inline void pushdown(int o)
	{
		nodes[ls].ans=max(nodes[o].ans,nodes[ls].ans);
		nodes[rs].ans=max(nodes[o].ans,nodes[rs].ans);
	}
	
	inline int query(int o,int l,int r,int a,int b)
	{
		if(b<l || a>r)
			return -INT_MAX;
		if(a<=l && b<=r)
			return nodes[o].ans;
		else
		{
			pushdown(o);
			return max(query(ls, l, mid, a, b) , query(rs, mid+1, r, a, b) )%D;
		}
	}
	
	inline void modify(int o,int l,int r,int a,int b,int v)
	{
		if(b<l || a>r)
			return ;
		if(a<=l && b<=r)
			change(o,v);
		else
		{
			pushdown(o);
			modify(ls, l, mid, a, b, v);
			modify(rs, mid+1, r, a, b, v);
			pushup(o);
		}
	}
}

using namespace segment_tree;
int main()
{
	ios::sync_with_stdio(false);
	
	cin>>M>>D;
	build(200000*4);
	
	char t;int cache=0,n,L=0;
	int m=M;
	while(m--)
	{
		cin>>t;
		if(t=='Q')
		{
			cin>>n;
			cache=query(1,1,M,L-n+1,L);
			cout<<cache<<endl;
		}
		if(t=='A')
		{
			L++;
			cin>>n;
			int num=((long long)n+cache) %D;
			modify(1,1,M,L,L,num);
		}
	}
	return 0;
}
