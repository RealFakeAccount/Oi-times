#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 5e3 + 20;

set<int> S;
vector<int> g[MAXN];
int N, M, s;

int c[MAXN], c_cnt = 0;
void dfs(int u)
{
	if(c[u]) return ;
	c[u] = c_cnt;
	for(int i = 0; i < (int) g[u].size(); i++)
		dfs(g[u][i]);
}

int main()
{
	cin>>N>>M>>s;
	for(int i = 1, u, v; i <= M; i++)
	{
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}
	for(int i = 1; i <= N; i++)
		if(!c[i]) c_cnt++, dfs(i);
	//for(int i = 1; i <= N; i++)
		//cout<<c[i]<<" ";
	int cnt = 0;
	for(int i = 1; i <= N; i++)
		if(S.find(c[i]) == S.end())
			cnt++, S.insert(c[i]);

	cout<<cnt - 1<<endl;
	return 0;
}