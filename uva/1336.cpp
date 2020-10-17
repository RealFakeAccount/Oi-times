#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 20;

int N, V, X;

struct point
{
	int x, c, t;
	point(int x = 0, int c = 0, int t = 0) : 
	x(x), c(c), t(t) {} 
	bool operator <(const point &rhs) const{
		return x < rhs.x;
	}
}p[MAXN];

int f[MAXN][MAXN][2], sum[MAXN];

void dp(int i, int j, int k)
{
	int t;

	t = ( k == 0 ?  ((p[i].x - p[i - 1].x) / V) : ((p[j].x - p[i - 1].x) / V)  );
	f[i - 1][j][0] = min(f[i - 1][j][0],  
		f[i][j][0] + ((sum[i - 1] - sum[1]) + (sum[N] - sum[j + 1])) * t + p[i - 1].c);

	t = ( k == 0 ?  ((p[j + 1].x - p[i].x) / V) : ((p[j + 1].x - p[j].x) / V) );
	f[i][j + 1][1] = min(f[i][j + 1][1],
		f[i][j][0] + ((sum[i - 1] - sum[1]) + (sum[N] - sum[j + 1])) * t + p[j + 1].c);

	if(i - 1 >= 1) dp(i - 1, j, 0);
	if(j + 1 <= N) dp(i, j + 1, 1);
}

int main()
{
	freopen("1336.in", "r", stdin);
	while(cin>>N>>V>>X, (N != 0))
	{
		for(int i = 1; i <= N; i++)
			scanf(" %d %d %d", &p[i].x, &p[i].c, &p[i].t);
		sort(p + 1, p + N + 1);

		for(int i = 1; i <= N; i++)
			sum[i] = sum[i - 1] + p[i].c;

		point s;
		s.x = X;
		p[0].x = -INF, p[N + 1].x = INF;

		int i = lower_bound(p + 1, p + N + 1, s) - p - 1,
		j = upper_bound(p + 1, p + N + 1, s) - p;

		int ans = INF;
		
		if(j != N)
		{
			memset(f, 0x7f, sizeof(f));
			f[i][j][0] = (X - p[i].x) / V * sum[N];
			dp(i, j, 0);
			ans = min(f[1][N][0], f[1][N][1]);
		}
		else ans = (X - p[i].x) / V * sum[N];

		if(i != 1)
		{
			memset(f, 0x7f, sizeof(f));
			f[i][j][1] = (p[j].x - X) / V * sum[N];
			dp(i, j, 1);
			ans = min(ans, min(f[1][N][0], f[1][N][1]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
