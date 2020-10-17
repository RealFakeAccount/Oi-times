#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 500 + 10;
const int MAXX = (10000 + 10);
int C, N;

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int lx, ly;
vector<int> cp;
namespace stree
{
	#define mid (((l) + (r)) >> 1)
	#define ls ((o) << 1)
	#define rs (((o) << 1) | 1)

	struct nodes
	{
		int sum, addv;
		nodes() : sum(0), addv(0) {}
	}node[MAXN << 2];

	inline void init()
	{
		for(int i = 0; i <= ((int) cp.size() << 2); i++)
			node[i].sum = 0, node[i].addv = 0;
	}

	inline void givetag(int o, int l, int r, int v)
	{
		node[o].addv += (r - l + 1) * v;
		node[o].sum += v;
	}

	inline void pushdown(int o, int l ,int r)
	{
		if(node[o].addv)
		{
			int &v = node[o].addv;
			givetag(ls, l, mid, v),
			givetag(rs, mid + 1, r, v);
			v = 0;
		}
	}

	inline void pushup(int o)
	{
		node[o].sum = max(node[ls].sum, node[rs].sum);
	}

	void modify(int o, int l, int r, int a, int b, int v)
	{
		if(l > b || r < a) return ;
		if(a <= l && r <= b) {givetag(o, l, r, v); return ;}

		pushdown(o, l, r);
		modify(ls, l, mid, a, b, v),
		modify(rs, mid + 1, r, a, b, v);
		pushup(o);
		return ;
	}

	int query(int o, int l, int r, int a, int b)
	{
		if(l > b || r < a) return 0;
		if(a <= l && b <= r) return node[o].sum;

		pushdown(o, l, r);
		return max(query(ls, l, mid, a, b), query(rs, mid + 1, r, a, b));
	}

	inline void Modify(int a, int b, int v)
	{
		modify(1, 1, cp.size(), a, b, v);
	}

	inline int Query(int a, int b)
	{
		return query(1, 1, cp.size(), a, b);
	}
	#undef mid
	#undef ls
	#undef rs
}

struct seg
{
	int y1, y2, c;
	seg(int a, int b, int c) : y1(a), y2(b), c(c) {}
};

struct P
{
	int x, y;
	P(int x = 0, int y = 0) : x(x), y(y) {}
}p[MAXN];

inline void compress(int len)
{
	for(int i = 1; i <= N; i++)
	{
		cp.push_back(p[i].x);
		cp.push_back(p[i].x + len - 1);
		cp.push_back(p[i].y);
		cp.push_back(p[i].y + len - 1);
	}
	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());
}

inline int get_coo(int x)//coordinate
{
	return upper_bound(cp.begin(), cp.end(), x) - cp.begin();
}

vector<seg> v[MAXN];
inline bool check(int len)
{
	cp.clear();
	compress(len);

	stree::init();
	for(int i = 0; i <= (int) cp.size(); i++)
		v[i].clear();
	
	for(int i = 1; i <= N; i++)
	{
		v[get_coo(p[i].x)].push_back(seg(get_coo(p[i].y), get_coo(p[i].y + len - 1), 1));
		//cout<<get_coo(p[i].x)<<endl;
		v[get_coo(p[i].x + len - 1)].push_back(seg(get_coo(p[i].y), get_coo(p[i].y + len - 1), -1));
		//cout<<get_coo(p[i].x + len - 1)<<endl;
	}

	int ans = 0;
	for(int i = 1; i <= (int) cp.size(); i++)
		for(int j = 0; j < (int) v[i].size(); j++)
		{
			seg s = v[i][j];
			stree::Modify(s.y1, s.y2, s.c);
			ans = max(ans, stree::node[1].sum);
		}

	return ans >= C;
}

int main()
{
	freopen("p2862.txt", "r", stdin);

	cin>>C>>N;

	int x, y;
	lx = 0, ly = 0;
	for(int i = 1; i <= N; i++)
	{
		x = read(), y = read();
		lx = max(lx, x);
		ly = max(ly, y);
		p[i] = P(x, y);
	}

	int l = 0, r = 1000;
	#define mid ((((l) + (r))) >> 1)
	while(l < r)
	{
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	#undef mid

	cout<<l<<endl;
	return 0;
}