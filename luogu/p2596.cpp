#include <bits/stdc++.h>
using namespace std;
const int MAXN=80000+10;

int opbook,a[MAXN];

namespace Treap
{
	struct node
	{
		int key,val,s,booknum;
		node *ls, *rs;
		
		inline void maintain()
		{
			s=ls->s+rs->s+1;
		}
	}pool[MAXN],*pit,*null;
	
	void init()
	{
		pit=pool;
		null=new node();
		null->s=0;
		null->booknum=0;
	}
	
	inline node *newnode(int v)
	{
		pit->key=v,pit->val=rand();
		pit->ls=pit->rs=null;
		pit->s=1,pit->booknum=opbook;
		return pit++;
	}
	
	node *merge(node *a,node *b)
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
			return o->booknum;
		else if(k<=s)
			return findkth(o->ls,k);
		else
			return findkth(o->rs,k-s-1);
	}
	
	int lowercount(const node *o,int v)
	{
		if(o==null)
			return 0;
		return v<=o->key ? lowercount(o->ls,v) : lowercount(o->rs,v)+o->ls->s+1;
	}
	
	int uppercount(const node *o,int v)
	{
		if(o==null)
			return 0;
		return v<o->key ? uppercount(o->ls,v) : uppercount(o->rs,v)+o->ls->s+1;
	}
	
	inline void insert(node *&root,int v)
	{
		int x=lowercount(root, v);
		droot l=split(root, x);
		root=merge(merge(l.first, newnode(v)), l.second);
	}
	
	inline void erase(node *&root,int v)
	{
		int x=lowercount(root,v);
		droot l=split(root,x),r=split(l.second,1);
		root=merge(l.first,r.second);
	}
	
	inline int pred(const node *root,int v)
	{
		return findkth(root,lowercount(root,v));
	}
	
	inline int succ(const node *root,int v)
	{
		return findkth(root,uppercount(root,v)+1);
	}
}

using namespace Treap;

int innum[MAXN];

int main()
{
//	freopen("p2596.txt","r",stdin);
	ios::sync_with_stdio(false);
	int M,N;
	cin>>N>>M;
	int l=1,r=N;
	init();
	node *root=null;
	
	for(int i=1;i<=N;i++)
	{
		cin>>opbook;
		a[opbook]=i;
		insert(root,i);
	}
//	for(int i=1;i<=N;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	
	string in;int x,y;
	while(M--)
	{
		cin>>in;
		if(in=="Top")
		{
			cin>>x;
			erase(root,a[x]);
			opbook=x;
			insert(root,--l);
			a[x]=l;
		}
		if(in=="Bottom")
		{
			cin>>x;
			erase(root,a[x]);
			opbook=x;
			insert(root,++r);
			a[x]=r;
		}
		if(in=="Insert")
		{
			cin>>x>>y;
			if(y!=0)
			{
				int rank2=uppercount(root,a[x]);
				int rank1=rank2+y;
				int s2=findkth(root,rank1);
				erase(root,a[x]);
				erase(root,a[s2]);
				swap(a[x],a[s2]);
				opbook=x;
				insert(root,a[x]);
				opbook=s2;
				insert(root,a[s2]);
			}
		}
		if(in=="Query")
		{
			cin>>x;
			cout<<findkth(root,x)<<endl;
		}
		if(in=="Ask")
		{
			cin>>x;
			cout<<lowercount(root,a[x])<<endl;
		}
	//	for(int i=1;i<=N;i++)
	//		cout<<a[i]<<" ";
	//	cout<<endl;
	//	cout<<l<<" "<<r<<endl;
	}
	return 0;
}


