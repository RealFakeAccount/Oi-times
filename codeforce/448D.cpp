#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int N, M, K;

inline bool check(ll cur)
{
	ll sum = 0;
	for(int i = 1; i <= N; i++)
		sum += min(1LL * M, cur / (1LL * i));
	return sum < K;
}

int main()
{
	cin>>N>>M>>K;
	ll l = 0, r = N * M;
	while(l < r)
	{
		ll mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	cout<<l<<endl;
	return 0;
}