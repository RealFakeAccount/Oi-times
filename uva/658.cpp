#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 20 + 1;
const int MAXM = 1e2 + 10;

int N, M;
int t_pat[MAXM], f1[MAXM], f2[MAXM], b[MAXM], _b[MAXM];
string Patch[2][MAXM];

inline bool ok(int sit, int i)
{
	return (sit | _b[i]) == b[i];
}

inline int chg(int sit, int i)
{
	sit &= f1[i];
	sit |= f2[i];
	return sit;
}

namespace SP
{
	int d[(1 << 21) - 1];

	inline bool tension(const int &st, int &lg)
	{
		return st < lg ? (lg = st, true) : false;
	}

	int dijkstra()
	{
		priority_queue<P, vector<P>, greater<P> > q; 
		memset(d, 0x7f, sizeof(d));
		d[(1 << N) - 1] = 0;
		q.push(P(0, (1 << N) - 1));

		while(!q.empty())
		{
			P p = q.top(); q.pop();
			if(p.second == 0) return p.first;

			for(int i = 1; i <= M; i++)
				if(ok(p.second, i) && tension(d[p.second] + t_pat[i], d[chg(p.second, i)])) 
					q.push(P(p.first + t_pat[i], chg(p.second, i)));
		}
		return -1;
	}
}

inline void init()
{
	memset(f1, 0, sizeof(f1));
	memset(f2, 0, sizeof(f2));
	memset(t_pat, 0, sizeof(t_pat));
	memset(b, 0, sizeof(b));
	memset(_b, 0, sizeof(_b));
}

int main()
{
	//freopen("658.in", "r", stdin);
	//freopen("658.out", "w", stdout);
	int T = 0;
	while(cin>>N>>M, N != 0)
	{
		init();
		T++;
		for(int i = 1; i <= M; i++)
			cin>>t_pat[i]>>Patch[0][i]>>Patch[1][i];
	
		char ch;
		for(int i = 1; i <= M; i++)
			for(int j = 0; j <= 1; j++)
				for(int k = 0; k < (int) Patch[j][i].length(); k++)
				{
					ch = Patch[j][i][k];
					if(j == 0)
					{
						(_b[i]) |= ((ch == '0') << k);
						(b[i]) |= ((ch != '-') << k);
					}
					if(j == 1) 
					{
						(f1[i]) |= ((ch != '-') << k);
						(f2[i]) |= ((ch == '+') << k);
					}
				}
		int ans = SP::dijkstra();
		printf("Product %d\n", T);
		if(ans != -1) printf("Fastest sequence takes %d seconds.\n", ans);
		else puts("Bugs cannot be fixed.");
		puts("");
	}
	return 0;
}
