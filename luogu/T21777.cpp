#include <bits/stdc++.h>
using namespace std;
const int MAXN=500000+2;
long long a[MAXN],sett[MAXN],setv[MAXN];

namespace Segment_tree
{
	const long long MAXNODE = MAXN<<2;
	struct node
	{
		long long ld,tag,tagt,growsp,heisum,maxhei,minhei;
	}tree[MAXNODE];

	#define ls ((o)<<1)
	#define rs (((o)<<1)+1)
	#define mid (((l)+(r))>>1)

	inline void pushdown(long long o,long long l,long long r)
	{
		if(!tree[o].tag)
		{
			tree[ls].heisum=tree[o].tag*(mid-l+1),
			tree[rs].heisum=tree[o].tag*(r-mid);
			tree[ls].maxhei=tree[ls].minhei=tree[rs].maxhei=tree[rs].minhei=tree[o].tag;
			tree[ls].tagt=tree[rs].tagt=tree[ls].ld=tree[rs].ld=tree[o].tagt;
			tree[ls].tag=tree[rs].tag=tree[o].tag;
			tree[o].tag=-1;
		}
	}

	void build(long long o,long long l,long long r)
	{
		tree[o].tag=-1;
		if(l==r)
			tree[o].growsp=a[mid];
		else
		{
			build(ls,l,mid),build(rs,mid+1,r);
			tree[o].growsp=tree[ls].growsp+tree[rs].growsp;
		}
	}

	long long getsum(long long o,long long l,long long r,long long d,long long b)
	{
	    long long ret;
	    tree[o].heisum+=(d-tree[o].ld)*tree[o].growsp;
	    tree[o].minhei+=a[l]*(d-tree[o].ld);
	    tree[o].maxhei+=a[r]*(d-tree[o].ld);
	    tree[o].ld=d;
	    if(tree[o].maxhei<=b)
	        return 0;
	    if(tree[o].minhei>b)
	    {
	        ret=tree[o].heisum-b*(r-l+1);
	        tree[o].tagt=tree[o].ld=d;
	        tree[o].tag=b;
	        tree[o].heisum=(r-l+1)*b;
	        tree[o].maxhei=tree[o].minhei=b;
	        return ret;
	    }
	    pushdown(o,l,r);
	    ret=getsum(ls,l,mid,d,b)+getsum(rs,mid+1,r,d,b);
	    tree[o].heisum=tree[ls].heisum+tree[rs].heisum;
	    tree[o].minhei=tree[ls].minhei,tree[o].maxhei=tree[rs].maxhei;
	    return ret;
	}
}

using namespace Segment_tree;

int main()
{
	ios::sync_with_stdio(false);
	long long M,N;
	cin>>N>>M;
	for(long long i=1;i<=N;i++)
		cin>>a[i];

	sort(a+1,a+N+1);
	build(1,1,N);

	long long d,b;
	long long ans;
	while(M--)
	{
		cin>>d>>b;
		ans=getsum(1,1,N,d,b);
		cout<<ans<<endl;
	}
	return 0;
}