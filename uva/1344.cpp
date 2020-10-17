#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 2e3 + 20;

int N;
int a[MAXN], b[MAXN];

int main()
{
	//freopen("1344.in", "r", stdin);
	//freopen("1344.out", "w", stdout);
	while(cin>>N, N)
	{
		multiset<int> S;
		multiset<int>::iterator it;
		for(int i = 1; i <= N; i++)
			scanf("%d", &a[i]), S.insert(a[i]);
		for(int i = 1; i <= N; i++)
			scanf("%d", &b[i]);
		int ans = 0;
		for(int i = 1; i <= N; i++)
		{
			if(b[i] > *S.rbegin()) {
				ans -= 200;
				it = S.begin(), S.erase(it);
				continue;
			}
			it = S.upper_bound(b[i]);
			if(it != S.end()) ans += 200;
			else it--;
			S.erase(it);
		}
		cout<<ans<<endl;
	}
	return 0;
}
