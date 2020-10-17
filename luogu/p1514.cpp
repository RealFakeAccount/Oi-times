#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 5e2 + 10;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int S[MAXN][MAXN], vis[MAXN][MAXN];
int N, M;
P c[MAXN];

P bfs(int u)
{
	queue<P> q; memset(vis, false, sizeof(vis));
	q.push(P(u, 1)); vis[u][1] = true;
	P ans = P(INF, -INF);
	while(!q.empty())
	{
		P p = q.front(); q.pop();

		if(p.first == N) 
			ans.first = min(ans.first, p.first),
			ans.second = max(ans.second, p.first);
		for(int i = 0; i < 4; i++)
			if(S[p.first  + dx[i]][p.second + dy[i]] < 
				S[p.first][p.second] && !vis[p.first  + dx[i]][p.second + dy[i]])
				{
					q.push(P(p.first  + dx[i], p.second + dy[i]));
					vis[p.first  + dx[i]][p.second + dy[i]] = true;
				}
	}
	return ans;
}

P calc()
{
	sort(c + 1, c + M + 1); 
	int r = 1, ans = 0;
	if(c[1].first != 1) return P(0, 0);
	for(int i = 1; i < N; i++)
		if(c[i + 1].first > c[i].second) return P(0, 0);
		else 
		{
			int j = i + 1;
			while(c[j].first <= c[i].second) j++;
			j--;ans++;
				r = max(r, c[j].second);
			if(r >= M) return P(1, ans);
		}
	return P(0, 0);
}

int main()
{
	cin>>N>>M;
	memset(S, 0x3f, sizeof(S));
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%d", &S[i][j]);
	for(int i = 1; i <= M; i++) c[i] = bfs(i);
	for(int i = 1; i <= M; i++)
		cout<<c[i].first<<" "<<c[i].second<<endl;
	P res = calc();
	if(res.first) cout<<res.second<<endl;
	return 0;
}
