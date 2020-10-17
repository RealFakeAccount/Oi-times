#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 100000 + 20;

inline ll read()
{
	ll x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

ll N;

struct rec
{
	ll l, h;
	rec(ll l = 0, ll h = 0) : l(l), h(h) {}
};

struct _stack
{
	stack<rec> sta;

	inline void init()
	{
		while(!sta.empty())
			sta.pop();
	}

	inline ll Pushin(rec cur)
	{
		if(sta.empty() || sta.top().h < cur.h)
		{
			sta.push(cur);
			return 0;
		}

		ll len = 0, area = 0;
		rec now;
		while(!sta.empty() && sta.top().h > cur.h)
		{
			now = sta.top();
			len += now.l;
			area = max(area, len * now.h);
			sta.pop();
		}
		sta.push(rec(len + cur.l, cur.h));
		return area;
	}
}Stack;

int main()
{
	while(cin>>N, N)
	{
		Stack.init();
		ll ans = 0;
		for(ll i = 1; i <= N; i++)
			ans = max(ans, Stack.Pushin(rec(1, read())));
		ans = max(ans, Stack.Pushin(rec(1, 0)));
		cout<<ans<<endl;
	}
	return 0;
}