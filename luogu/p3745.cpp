#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 20;
const ll INF = LONG_LONG_MAX;

ll A, B, C, N, M;
ll t[MAXN], b[MAXN];
ll lastt = 0;

inline ll check(ll T)
{
	ll unh = 0, bef = 0, aft = 0;
	if(B <= A) 
	{
		for(int i = 1; i <= M; i++)
			if(b[i] > T)
				unh += (b[i] - T) * B;

		for(int i = 1; i <= N; i++)
			if(t[i] < T)
				unh += (T - t[i]) * C;

		return unh;
	}
	else
	{
		for(int i = 1; i <= N; i++)
			if(t[i] < T)
				unh += (T - t[i]) * C;

		for(int i = 1; i <= M; i++)
		{
			if(b[i] > T) aft += (b[i] - T);
			if(b[i] < T) bef += (T - b[i]);
		}

		if(aft <= bef) return unh += aft * A;
		else//bef < aft
		{
			unh += bef * A;
			unh += (aft - bef) * B;
			return unh;
		}
	}
}

int main()
{
	//freopen("p3745.txt", "r", stdin);
	cin>>A>>B>>C;
	cin>>N>>M;

	ll firstt = INF;
	for(int i = 1; i <= N; i++)
		{scanf("%lld", &t[i]); lastt = max(t[i], lastt); firstt = min(firstt, t[i]);}
	for(int i = 1; i <= M; i++)
		{scanf("%lld", &b[i]); lastt = max(b[i], lastt);}

	if(C==1e16){cout<<check(firstt)<<endl;return 0;} 

	ll cnt = 0, l = 0, r = lastt;
	while(true)
	{
		ll m1 = l + (r - l) / 3;
		ll m2 = r - (r - l) / 3;
		if((r - l) <= 8 || cnt >= 100) break;
		if(check(m1) < check(m2)) r = m2;
		else l = m1;
	}

	ll ans = INF;
	for(ll i = l; i <= r; i++)
		ans = min(ans, check(i));
	//cout<<INF<<endl;
	cout<<ans<<endl;
	return 0;
}
