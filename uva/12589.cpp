#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
#define x first
#define y second
const int MAXN = 50 + 2;

P v[MAXN];
int N, K;

inline bool cmp(const P &lhs, const P &rhs)
{
	return (double) ((double)lhs.y / (double)lhs.x) > 
	(double) ((double)rhs.y / (double)rhs.x);
}

int f[MAXN][MAXN][MAXN * MAXN];

int main()
{
	//freopen("12589.in", "r", stdin);
	int T;
	cin>>T;
	int cnt = 0;
	while(T--)
	{
		cnt++;
		cin>>N>>K;
		register int a, b;
		for(int i = 1; i <= N; i++)
		{
			scanf(" %d %d", &a, &b);
			v[i] = P(a, b);
		}
		
		sort(v + 1, v + N + 1, cmp);
		
		memset(f, -0x3f, sizeof(f));
		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= K; j++)
				f[i][j][0] = 0;

		register int mxh[2] = {0}, d = 0;
		for(int i = 1; i <= N; i++)
		{
			d ^= 1;
			for(int j = 0; j <= min(i, K); j++)
				for(int h = 0; h <= mxh[d]; h++)
				{
					f[i + 1][j + 1][h + v[i].y] = max(f[i + 1][j + 1][h + v[i].y], 
					f[i][j][h] + (v[i].x * v[i].y) + 2 * (v[i].x * h));
					f[i + 1][j][h] = max(f[i + 1][j][h], f[i][j][h]);
					mxh[d ^ 1] = max(mxh[d ^ 1], h + v[i].y);
				}
		}

		int ans = 0;
		for(int i = 1; i <= max(mxh[0], mxh[1]); i++)
			ans = max(ans, f[N + 1][K][i]);
		printf("Case %d: %d\n", cnt, ans);
	}
	return 0;
}
