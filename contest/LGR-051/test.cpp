#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MAXN = 5e5 + 10;

ll N, M, S, Q;
P a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>M>>S>>Q;
	bool flag = false;
	for(int i = 1; i <= S; i++){
		int u, v; cin>>u>>v;
		if((v - u + 1) > N) flag = true;
		--u, --v; a[i] = P(u % N, v % N);
	}
	sort(a + 1, a + S + 1);
	for(int i = 1; i <= S; i++) if(a[i].first > a[i].second) {
		flag = true; break;
	}
	if(flag) {
		puts("Impossible!"); return 0;
	}

	if(a[S].second != N - 1 || a[1].first != 0){
		puts("Uncertain!"); return 0;
	}



	return 0;
}
