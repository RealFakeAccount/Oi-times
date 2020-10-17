#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100000+5;


int a[MAXN];

namespace segment_tree
{
#define ls ((o) << 1 )
#define rs ( ( (o) << 1 ) +1 )
#define mid (( (l) + (r) ) >> 1)

	struct node
	{
		ll add,sum;
	} nodes[MAXN*4];

	inline void pushup(ll o)
	{
		nodes[o].sum=nodes[ls].sum+nodes[rs].sum;
	}

	void build(ll o,ll l,ll r)
	{
		nodes[o].add=0;
		nodes[o].sum=0;

		if(l==r)
			nodes[o].sum=a[l];
		else
		{
			build(ls,l,mid);
			build(rs,mid+1,r);
			pushup(o);
		}
	}


	inline void Add(ll o,ll l,ll r,ll v)
	{
		nodes[o].add+=v;
		nodes[o].sum+=(r-l+1)*v;
	}

	inline void pushdown(ll o,ll l,ll r)
	{
		if(nodes[o].add!=0)
		{
			Add(ls,l,mid,nodes[o].add);
			Add(rs,mid+1,r,nodes[o].add);
			nodes[o].add=0;
		}
	}

	inline void modify(ll o,ll l,ll r,ll a,ll b,ll v)
	{
		if(r<a || l>b)
			return;
		if(a<=l && r<=b)
			Add(o,l,r,v);
		else
		{
			pushdown(o,l,r);
			modify(ls,l,mid,a,b,v);
			modify(rs,mid+1,r,a,b,v);
			pushup(o);
		}
	}

	inline ll query(ll o,ll l,ll r,ll a,ll b)
	{
		if(r<a || l>b)
			return 0;
		if(a<=l && r<=b)
			return nodes[o].sum;
		else
		{
			pushdown(o,l,r);
			return query(ls,l,mid,a,b)+query(rs,mid+1,r,a,b);
		}
	}
}

using namespace segment_tree;

int main()
{
	ios::sync_with_stdio(false);
	int N,M;
	cin>>N>>M;
	for(int i=1; i<=N; i++)
		cin>>a[i];
	build(1,1,N);

	int t,x,y,z;
	while(M--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>x>>y>>z;
			modify(1,1,N,x,y,z);
		}
		if(t==2)
		{
			cin>>x>>y;
			cout<<query(1,1,N,x,y)<<endl;
		}
	}
	return 0;
}
