#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 20;
inline ll read()
{
	ll x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int N, M;
map<ll, int> ma;

inline bool check(ll x)
{
	for(ll i = 2; i * i <= x; i++) if(x % i == 0) return false;
	return true;
}

int main()
{
	int T; cin>>T;
	while(T--)
	{
		cin>>N>>M;
		ma.clear();
		int n = 0, m = 0; bool flag = true;
		for(int i = 1, x; i <= N; i++){
			x = read();
			if(x == 1) continue;
			++n; ma[x]++; 
		}
		for(int i = 1, x; i <= M; i++){
			x = read();
			if(x == 1) continue;
			++m; ma[x]--;
		}
		if(n <= m) flag = false;
		else {
			map<ll, int>::iterator it;
			int cnt = 0;
			for(it = ma.begin(); it != ma.end(); ++it){
				if(it->second >= 2) {flag = false; break;}
				if(it->second == 0) continue;
				cnt++; if(cnt >= 2) {flag = false; break;}
				if(!check(it->first)) {flag = false; break;}
			}
		}
		
			
		if(!flag || M == N) puts("NO");
		else puts("YES");
	}
	return 0;
}