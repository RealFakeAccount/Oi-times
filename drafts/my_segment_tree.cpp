#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=200000+5;
#define ls (( (o) << 1 ) + 1)
#define rs (( (o) << 1 ) + 2)
#define mid (( (l) + (r) ) >> 1 )
ll N,M,P;

struct STREE//start from 0
{

	ll sumv[MAXN];
	ll mulv[MAXN];
	ll addv[MAXN];
	
	void T_init()
	{
		memset(addv,0,sizeof(addv));
		memset(mulv,1,sizeof(mulv));
		memset(addv,0,sizeof(sumv));
	}
	
	inline void pushup(ll o)
	{
		sumv[o]=sumv[ls]+sumv[rs];
	}
	
	void Build(ll o,ll l,ll r)
	{
		if(l==r)
		{
			cin>>sumv[o];//why can`t cin sumv[o] directly?
			addv[o]=0;
			mulv[o]=1;
			return ;
		}
		else
		{
			sumv[o]=0;
			addv[o]=0;
			mulv[o]=1;
			Build(ls,l,mid);
			Build(rs,mid+1,r);
			pushup(o);
		}
	}
	
	inline void Mul(ll o,ll v)
	{
		sumv[o]*=v;
		mulv[o]*=v;
		addv[o]*=v;
	}
	
	inline void Add(ll o,ll l,ll r,ll v)
	{
		sumv[o]+=(r-l)*v;
		addv[o]+=v;
	}
	
	inline void pushdown(ll o,ll l,ll r)
	{
		if(mulv[o]!=1)
		{
			Mul(ls,mulv[o]);
			Mul(rs,mulv[o]);
			mulv[o]=1;
		}
		if(addv[o]!=0)
		{
			Add(ls,l,mid,addv[o]);
			Add(rs,mid+1,r,addv[o]);
			addv[o]=0;
		}
	}
	
	inline int query(ll o,ll l,ll r,ll a,ll b)
	{
		if(r<=a || l>=b)
			return 0;
		if(a<=l && r<=b)
			return sumv[o];
		else
		{
			pushdown(o,l,r);
			return query(ls,l,mid,a,b)+query(rs,mid+1,r,a,b);
		}
	}
	
	inline void modify(ll o,ll l,ll r,ll a,ll b,char type,ll v)
	{
		if(r<=a || l>=b)
			return ;
		if(a<=l && r<=b)
		{
			if(type == '*')
				Mul(o,v);
			if(type == '+')
				Add(o,l,r,v);
		}
		else
		{
			pushdown(o,l,r);
			modify(ls,l,mid,a,b,type,v);
			modify(rs,mid+1,r,a,b,type,v);
			pushup(o);
		}
	}
}tree;

int main()
{
	freopen("segment_tree.txt","r",stdin);
	//ios::sync_with_stdio(false);
	cin>>N>>P;
	tree.Build(0,0,N);
	for(int i=0;i<=N*3;i++)
		cout<<tree.sumv[i]<<" ";
	cout<<endl;
	cin>>M;
	ll k;
	while(M--)
	{
		cin>>k;
		if(k==1 || k==2)
		{
			char type;
			if (k==1)
				type='*';
			else
				type='+';
			ll l,r,v;
			cin>>l>>r>>v;
			tree.modify(0,0,N,l,r,type,v);
		}
		if(k==3)
		{
			ll l,r;
			cin>>l>>r;
			cout<<tree.query(0,0,N,l,r)<<endl;
		}
	}
	return 0;
}
