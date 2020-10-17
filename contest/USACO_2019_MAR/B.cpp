#include <cstdio>
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 7500 + 100;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

const long long MOD = 2019201997;
ll N, K, fa[MAXN], ans;

ll calc(ll i, ll j) {
	return max((1LL * 2019201913 * i % MOD + 1LL * 2019201949 * j % MOD) % MOD,
    (1LL * 2019201913 * j % MOD + 1LL * 2019201949 * i % MOD) % MOD);
}

ll find_fa(ll x){ return fa[x] = (fa[x] == x) ? x : find_fa(fa[x]); }


bool check(ll mid){
    for(ll i = 1; i <= N; i++) fa[i] = i; ll cnt = N;
    for(ll i = 1; i <= N; i++) 
    	for(ll j = 1; j < i; j++){
        ll fx = find_fa(i), fy = find_fa(j);
        if(calc(i, j) < mid && fx != fy) fa[fx] = fy, cnt--;
        if(cnt < K)  return false;
    } return true;
}


int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	N = read(), K = read(); ll l = 2e8, r = MOD;
	while(l <= r) {
		ll mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout<<ans<<endl;
	return 0;
}