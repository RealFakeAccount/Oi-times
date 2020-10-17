#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int MAXN = 1e5 + 20;

int N, M;

namespace SCC
{
	vector<int> g[MAXN];
	stack<int> sta;
	bool ins[MAXN]; 
	int idx[MAXN], dfn[MAXN], low[MAXN];
	vector<int> scc[MAXN]; int cnt = 0;

	void tarjan(int cur)
	{
		static int num = 0;
		dfn[cur] = low[cur] = ++num;
		sta.push(cur), ins[cur] = true;
		for(int i = 0; i < (int) g[cur].size(); i++){
			int v = g[cur][i];
			if(!dfn[v]) {
				tarjan(v);
				low[cur] = min(low[cur], low[v]);
			}
			else if(ins[v]) low[cur] = min(low[cur], dfn[v]);
		}
		if(dfn[cur] == low[cur]){
			++cnt; int tmp;
			do{
				tmp = sta.top(); sta.pop(); ins[tmp] = false;
				idx[tmp] = cnt, scc[cnt].push_back(tmp);
			}while(tmp != cur);
		}
	}
}

int main()
{
	cin>>N>>M;
	for(int i = 1, u, v; i <= M; i++){
		scanf("%d%d", &u, &v);
		SCC::g[u].push_back(v);
	}

	for(int i = 1; i <= N; i++)
		if(!SCC::dfn[i]) SCC::tarjan(i);
	int ans = 0;
	for(int i = 1; i <= SCC::cnt; i++)
		if(SCC::scc[i].size() > 1) ++ans;
	cout<<ans<<endl;
	return 0;
}