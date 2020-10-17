#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M, K;

int main()
{
	ios::sync_with_stdio(false);
	int Q; cin>>Q;
	while(Q--){
		cin>>N>>M>>K;
		if(min(N, M) + abs(N - M) > K) cout<<-1<<endl;
		else{
			ll ans = 0;
			ans += min(N, M), K -= ans;
			if(N == M) {
				if(!(K & 1)) cout<<ans + K<<endl;
				else cout<<ans + K - 2<<endl;
				continue;
			}
			ll res = abs(N - M);
			if(res & 1) ans += res - 1, K -= res;
			else ans += res, K -= res;

			if(K == 0) cout<<ans<<endl;
			else {
				if(!(K & 1)) cout<<ans + K<<endl;
				else cout<<ans + K - 2<<endl;
			}
		}
	}
	return 0;
}