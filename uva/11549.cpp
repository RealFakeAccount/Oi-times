#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 9;

int N, K;
ll Dec[15];

inline int nxt(int x)
{
	ll tmp = 1LL * x * x;
	while(tmp >= Dec[N]) tmp /= 10;
	return (int) tmp;
}

int main()
{
	int T; cin>>T;
	Dec[0] = 1;
	for(int i = 1; i < 14; i++) Dec[i] = Dec[i - 1] * 10;
	while(T--)
	{
		cin>>N>>K;
		int ans = K, p1 = K, p2 = K;
		do{
			p1 = nxt(p1);
			for(int i = 1; i <= 2; i++)
				p2 = nxt(p2), ans = max(ans, p2);
		}while(p1 != p2);
		cout<<ans<<endl;
	}
	return 0;
}
