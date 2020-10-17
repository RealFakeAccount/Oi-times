#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000+2;
const int MAXM=100000+2;

int P,n,m,r;
int w[MAXN],wt[MAXN];
//w[]、wt[]初始点权数组 

namespace Stree
{
	const int MAXNODE=MAXN*4;
	struct node
	{
		int sum,addv;
	}nodes[MAXNODE];
	
	#define ls ((o)<<1)
	#define rs (((o)<<1)+1)
	#define mid (((l)+(r))>>1)
	
	inline void pushup(int o)
	{
		nodes[o].sum=nodes[ls].sum+nodes[rs].sum;
		nodes[o].sum%=P;
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
	
	inline void givetagadd(int o,int v,int l,int r)
	{
		(nodes[o].sum+=(r-l+1) *v %P ) %=P;
		(nodes[o].addv+=v ) %=P;
	}
	
	inline void push_down(int o,int l,int r)
	{
		if(nodes[o].addv!=0)
		{
			givetagadd(ls,nodes[o].addv,l,mid),givetagadd(rs,nodes[o].addv,mid+1,r);
			nodes[o].addv=0;
		}
	}
	
	inline int query(int o,int l,int r,int a,int b)
	{
		if(r<a || l>b)
			return 0;
		if(a<=l && r<=b)
			return nodes[o].sum;
			
		else
		{
			push_down(o,l,r);
			return (query(ls,l,mid,a,b)+query(rs,mid+1,r,a,b))%P;
		}
	}
	
	inline void modify(int o,int l,int r,int a,int b,int v)
	{
		if(r<a || l>b)
			return ;
		if(a<=l && r<=b)
			givetagadd(o,v,l,r);
			
		else
		{
			push_down(o,l,r);
			modify(ls,l,mid,a,b,v),modify(rs,mid+1,r,a,b,v);
			pushup(o);
		}
	}
	
}
namespace Hld//Heavy_light_Decomposition
{
int e,beg[MAXN],nex[MAXN],to[MAXN];
//链式前向星数组，w[]、wt[]初始点权数组 
int a[MAXN<<2],laz[MAXN<<2];
//线段树数组、lazy操作 
int son[MAXN],id[MAXN],fa[MAXN],cnt,dep[MAXN],siz[MAXN],top[MAXN]; 
//son[]重儿子编号,id[]新编号,fa[]父亲节点,cnt dfs_clock/dfs序,dep[]深度,siz[]子树大小,top[]当前链顶端节点 
int res=0;
//查询答案 
inline int qRange(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){//当两个点不在同一条链上 
        if(dep[top[x]]<dep[top[y]])swap(x,y);//把x点改为所在链顶端的深度更深的那个点
        res=0;
        Stree::query(1,1,n,id[top[x]],id[x]);//ans加上x点到x所在链顶端 这一段区间的点权和
        ans+=res;
        ans%=P;//按题意取模 
        x=fa[top[x]];//把x跳到x所在链顶端的那个点的上面一个点
    }
    //直到两个点处于一条链上
    if(dep[x]>dep[y])swap(x,y);//把x点深度更深的那个点
    res=0;
    Stree::query(1,1,n,id[x],id[y]);//这时再加上此时两个点的区间和即可
    ans+=res;
    return ans%P;
}

inline void updRange(int x,int y,int k){//同上 
    k%=P;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        Stree::modify(1,1,n,id[top[x]],id[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    Stree::modify(1,1,n,id[x],id[y],k);
}

inline int qSon(int x){
    res=0;
    Stree::query(1,1,n,id[x],id[x]+siz[x]-1);//子树区间右端点为id[x]+siz[x]-1 
    return res;
}

inline void updSon(int x,int k){//同上 
    Stree::modify(1,1,n,id[x],id[x]+siz[x]-1,k);
}

inline void dfs1(int x,int f,int deep){//x当前节点，f父亲，deep深度 
    dep[x]=deep;//标记每个点的深度 
    fa[x]=f;//标记每个点的父亲 
    siz[x]=1;//标记每个非叶子节点的子树大小 
    int maxson=-1;//记录重儿子的儿子数 
    for(int i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==f)continue;//若为父亲则continue 
        dfs1(y,x,deep+1);//dfs其儿子 
        siz[x]+=siz[y];//把它的儿子数加到它身上 
        if(siz[y]>maxson)son[x]=y,maxson=siz[y];//标记每个非叶子节点的重儿子编号 
    }
}

inline void dfs2(int x,int topf){//x当前节点，topf当前链的最顶端的节点 
    id[x]=++cnt;//标记每个点的新编号 
    wt[cnt]=w[x];//把每个点的初始值赋到新编号上来 
    top[x]=topf;//这个点所在链的顶端 
    if(!son[x])return;//如果没有儿子则返回 
    dfs2(son[x],topf);//按先处理重儿子，再处理轻儿子的顺序递归处理 
    for(int i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);//对于每一个轻儿子都有一条从它自己开始的链 
    }
}
inline void add(int x,int y){//链式前向星加边 
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
}
}


using namespace Hld;
int main()
{
	freopen("p3384.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n>>m>>r>>P;
	for(int i=1;i<=n;i++)
		cin>>w[i];
		
	int a,b;
	for(int i=1;i<=n-1;i++)
	{
		cin>>a>>b;
		add(a,b);add(b,a);
	}
	
	dfs1(r,0,1);
    dfs2(r,r);
    Stree::build(1,1,n);
//    	cout<<"==========="<<endl;
//		for(int i=1;i<=n;i++)
//			cout<<Stree::Stree::query(1,1,n,i,i)<<" ";
//		cout<<endl<<"=========="<<endl;
//	son[MAXN],id[MAXN],fa[MAXN],cnt,dep[MAXN],siz[MAXN],top[MAXN]

    while(m--)
	{
        int k,x,y,z;
        cin>>k;
        switch (k)
        {
			case (1):
				cin>>x>>y>>z;
				updRange(x,y,z);
				break;
				
			case(2):
				cin>>x>>y;
				cout<<qRange(x,y)<<endl;
				break;
				
			case(3):
				cin>>x>>y;
				updSon(x,y);
				break;
				
			case(4):
				cin>>x;
				cout<<qSon(x)<<endl;
				break;
		}
    }
	return 0;
}

