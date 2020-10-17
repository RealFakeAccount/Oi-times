#include <bits/stdc++.h>
using namespace std;
const int MAXT = 5e5 + 20;
const int MAXN = 3e4 + 20;

namespace ufs
{
	int fa[MAXN], d[MAXN], siz[MAXN];

	void init()
	{
		for(int i = 1; i <= MAXN; i++)
			fa[i] = i, siz[i] = 1;
	}

	int get(int x)
	{
		if(x == fa[x]) return x;
		int root = get(fa[x]);
		d[x] += d[fa[x]];
		return fa[x] = root;
	}

	inline void unite(int x, int y)
	{
		x = get(x), y = get(y);
		fa[x] = y, d[x] = siz[y];
		siz[y] += siz[x];
	}
}


int main()
{
	//freopen("p1196.txt", "r", stdin);
	int T;
	cin>>T;
	using namespace ufs;
	init();

	char opt;int i, j;
	while(T--)
	{
		scanf(" %c ", &opt);
		if(opt == 'M')
		{
			scanf("%d%d", &i, &j);
			unite(i, j);
		}
		else
		{
			scanf("%d%d", &i, &j);
			if(get(i) != get(j)) puts("-1");
			else printf("%d\n", abs(d[i] - d[j]) - 1);
		}
	}
	return 0;
}
