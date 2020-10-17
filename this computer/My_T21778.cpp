#include <bits/stdc++.h>
using namespace std;

const int MAXN=100000+5;

namespace Stree
{
	vector<int> v[MAXN];
	#define mid (((l)+(r))>>1)
	struct node 
	{
		pair<int,int> val;
		node *ls,*rs;
		void pushup()
		{
			val=max(ls->val,rs->val);
		}
	}pool[MAXN<<1],*null;
	
	node *newnode()
	{
		static int cnt=0;
		return &pool[cnt++];
	}

	node *build(int l,int r)
	{
		node *cur=newnode();
		if(l==r)
		{
			cur->val=make_pair(0,-l);
			cur->ls=cur->rs=null;
		}	
		else
		{
			cur->ls=build(l,mid);
			cur->rs=build(mid+1,r);
			cur->pushup();
		}
		return cur;
	}

	void add(node *cur,int l,int r,int p,int v)
	{
		if(l==r)
			cur->val.first+=v;
		else
		{
			if(p<=mid)
				add(cur->ls,l,mid,p,v);
			else
				add(cur->rs,mid+1,r,p,v);
			cur->pushup();
		}
	}
}

using namespace Stree;

int main()
{
	int N,M ;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int l,r,k;
		scanf("%d %d %d" , &l,&r,&k);
		v[l].push_back(k);
		v[r+1].push_back(-k);
	}

	node *root=build(1,100000);
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<(int ) v[i].size();j++)
		{
			int cur=v[i][j];
			if(cur>0)
				add(root,1,100000,cur,1);
			else
				add(root,1,100000,-cur,-1);
		}
		int ans;
		if(root->val.first) 
			ans= -root->val.second;
		else
			ans=-1;
		printf("%d\n", ans);
	}
		
	return 0;
}