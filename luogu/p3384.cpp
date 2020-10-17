#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000+2;
const int MAXM=100000+2;

int P,n,m,r;
int w[MAXN],wt[MAXN];
//w[]��wt[]��ʼ��Ȩ���� 

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
//��ʽǰ�������飬w[]��wt[]��ʼ��Ȩ���� 
int a[MAXN<<2],laz[MAXN<<2];
//�߶������顢lazy���� 
int son[MAXN],id[MAXN],fa[MAXN],cnt,dep[MAXN],siz[MAXN],top[MAXN]; 
//son[]�ض��ӱ��,id[]�±��,fa[]���׽ڵ�,cnt dfs_clock/dfs��,dep[]���,siz[]������С,top[]��ǰ�����˽ڵ� 
int res=0;
//��ѯ�� 
inline int qRange(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){//�������㲻��ͬһ������ 
        if(dep[top[x]]<dep[top[y]])swap(x,y);//��x���Ϊ���������˵���ȸ�����Ǹ���
        res=0;
        Stree::query(1,1,n,id[top[x]],id[x]);//ans����x�㵽x���������� ��һ������ĵ�Ȩ��
        ans+=res;
        ans%=P;//������ȡģ 
        x=fa[top[x]];//��x����x���������˵��Ǹ��������һ����
    }
    //ֱ�������㴦��һ������
    if(dep[x]>dep[y])swap(x,y);//��x����ȸ�����Ǹ���
    res=0;
    Stree::query(1,1,n,id[x],id[y]);//��ʱ�ټ��ϴ�ʱ�����������ͼ���
    ans+=res;
    return ans%P;
}

inline void updRange(int x,int y,int k){//ͬ�� 
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
    Stree::query(1,1,n,id[x],id[x]+siz[x]-1);//���������Ҷ˵�Ϊid[x]+siz[x]-1 
    return res;
}

inline void updSon(int x,int k){//ͬ�� 
    Stree::modify(1,1,n,id[x],id[x]+siz[x]-1,k);
}

inline void dfs1(int x,int f,int deep){//x��ǰ�ڵ㣬f���ף�deep��� 
    dep[x]=deep;//���ÿ�������� 
    fa[x]=f;//���ÿ����ĸ��� 
    siz[x]=1;//���ÿ����Ҷ�ӽڵ��������С 
    int maxson=-1;//��¼�ض��ӵĶ����� 
    for(int i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==f)continue;//��Ϊ������continue 
        dfs1(y,x,deep+1);//dfs����� 
        siz[x]+=siz[y];//�����Ķ������ӵ������� 
        if(siz[y]>maxson)son[x]=y,maxson=siz[y];//���ÿ����Ҷ�ӽڵ���ض��ӱ�� 
    }
}

inline void dfs2(int x,int topf){//x��ǰ�ڵ㣬topf��ǰ������˵Ľڵ� 
    id[x]=++cnt;//���ÿ������±�� 
    wt[cnt]=w[x];//��ÿ����ĳ�ʼֵ�����±������ 
    top[x]=topf;//������������Ķ��� 
    if(!son[x])return;//���û�ж����򷵻� 
    dfs2(son[x],topf);//���ȴ����ض��ӣ��ٴ�������ӵ�˳��ݹ鴦�� 
    for(int i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);//����ÿһ������Ӷ���һ�������Լ���ʼ���� 
    }
}
inline void add(int x,int y){//��ʽǰ���Ǽӱ� 
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

