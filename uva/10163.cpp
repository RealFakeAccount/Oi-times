#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 30 + 5;

int N, M;
int p[MAXM];

inline bool check(int x)
{
	register int cnt = 0, a = 0;

	for(int i = 1; i <= M; i++)
	{
		a = 1;
		while((p[i] / a) >= x) a++;
		a--;
		cnt += a;
	}

	return cnt >= N;

}

int main()
{
	freopen("10163.in", "r", stdin);
	while(cin>>N>>M, N != 0)
	{
		register int l = 0, r = 0;
		for(int i = 1; i <= M; i++)
			scanf(" %d", &p[i]),
			r += p[i];

		while(l < r)
		{
			int mid = (l + r + 1) / 2;
			if(check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}
