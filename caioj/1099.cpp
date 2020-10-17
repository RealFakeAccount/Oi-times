#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<string>

using namespace std;
#define in = read()
typedef long long ll;
const ll size = 1000000 + 10000;

#define left (rt<<1)
#define right (rt<<1|1)
#define mid ((l + r)>>1)
#define lson l,mid,left
#define rson mid + 1,r,right
#define len (r - l + 1)

ll n,m;
ll tree[size];

inline ll read()
{
	ll num = 0 , f = 1;
	char ch = getchar();

	while(!isdigit(ch))
	{
		if(ch == '-')   f = -1;
		ch = getchar();
	}

	while(isdigit(ch))
	{
		num = num*10 + ch - '0';
		ch = getchar();
	}

	return num*f;
}

inline void pushup1(ll rt)
{
	tree[rt] = max(tree[left] , tree[right]);
}

void buildtree(ll l, ll r, ll rt)
{
	if(l == r)
	{
		tree[rt] in;
		return;
	}
	buildtree(lson);
	buildtree(rson);
	pushup1(rt);
}

ll query(ll from,ll to,ll l,ll r,ll rt)
{
	if(from <= l && to >= r)    return tree[rt];
	ll ans = 0;
	if(from <= mid)   ans = max(ans , query(from,to,lson));
	if(to > mid)    ans = max(ans , query(from,to,rson));
	return ans;
}

void update(ll num,ll dis,ll l,ll r,ll rt)
{
	if(l == r)
	{
		tree[rt] = dis;
		return;
	}
	if(num <= mid)    update(num,dis,lson);
	else    update(num,dis,rson);
	pushup1(rt);
}

int main()
{
	n in;
	m in;
	buildtree(1,n,1);

	for(int i=1; i<=m; i++)
	{
		string s;
		cin>>s;
		ll x,y;
		x in;
		y in;
		if(s[0] == 'P')
		{
			if(x <= y)
				printf("%lld\n",query(x,y,1,n,1));
			if(y < x)
				printf("%lld\n",query(y,x,1,n,1));
		}
		else if(s[0] == 'C')
			update(x,y,1,n,1);
	}
}


