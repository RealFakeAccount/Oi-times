#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int N, K;
multiset<int> S;

int main()
{
	multiset<int>::iterator it;
	while(cin>>N, N)
	{
		int ans = 0;
		for(int i = 1, x; i <= N; i++)
		{
			cin>>K;
			for(int j = 1; j <= K; j++) scanf("%d", &x), S.insert(x);
			it = S.begin(), ans += *it;
			it = S.end(), it--, ans += *it;
			if(!S.empty()) S.erase(S.begin());
			if(!S.empty()) S.erase(--S.end());
			for(it = S.begin(); it != S.end(); ++it) cout<<*it<<" ";
			cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}