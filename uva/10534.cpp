#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e4 + 20;
const int INF = 0x3f3f3f3f;

int a[MAXN];
int f[MAXN], d[MAXN];
int g[MAXN];
int N;

int main()
{
	while(cin>>N)
	{
		for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
		memset(g, 0x3f, sizeof(g));
		for(int i = 1; i <= N; i++)
		{
			int p = upper_bound(g, g + N, a[i]) - g;
			f[i] = (a[i] == g[*lower_bound(g, g + N, a[i])] ? p : p + 1);
			g[p] = min(g[p], a[i]);
		}
		for(int i = 1; i <= N; i++) cout<<f[i]<<" ";
		memset(g, 0x3f, sizeof(g));
		for(int i = N; i >= 1; i--)
		{
			int p = upper_bound(g, g + N, a[i]) - g;
			d[i] = (a[i] == g[p] ? p : p + 1);
			g[p] = min(g[p], a[i]);
		}
		int ans = 0;
		for(int i = 1; i <= N; i++)
			ans = max(ans, min(d[i], f[i]));
		cout<<(ans * 2 - 1)<<endl;
	}
	return 0;
}