#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 100 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
vector<int> g[MAXN], cg[MAXN];

namespace SCC
{
	int dfn[MAXN], low[MAXN];
	stack<int> sta; bool ins[MAXN];
	int col[MAXN], cntscc; 

	int tarjan(int cur){
		static int dfsclock = 0;
		dfn[cur] = low[cur] = ++dfsclock;
		sta.push(cur), ins[cur] = true;
		for(int i = 0; i < (int) g[cur].size(); i++){
			int v = g[cur][i];
			if(!dfn[v]) low[cur] = min(low[cur], tarjan(v));
			else if(ins[v]) low[cur] = min(low[cur], dfn[v]);
		}
		if(dfn[cur] == low[cur]) {
			++cntscc; int v;
			do{
				v = sta.top(); sta.pop();
				ins[v] = false, col[v] = cntscc;
			}while(cur != v);
		}
		return low[cur];
	} 

}


bool no_indeg[MAXN], no_outdeg[MAXN];
void solve()
{
	memset(no_indeg, true, sizeof(no_indeg));
	memset(no_outdeg, true, sizeof(no_outdeg));
	using namespace SCC;
	for(int i = 1; i <= N; i++) if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= N; i++)
		for(int j = 0; j < (int) g[i].size(); j++) {
			int v = g[i][j];
			if(col[i] != col[v]) 
				cg[col[i]].push_back(col[v]), 
				no_indeg[col[v]] = false, no_outdeg[col[i]] = false;
		}
	int ans1 = 0;
	for(int i = 1; i <= cntscc; i++) if(no_indeg[i]) ++ans1;
	cout<<ans1<<endl;
	if(cntscc == 1) return puts("0"), void();

	int ans2 = 0;
	for(int i = 1; i <= cntscc; i++) if(no_outdeg[i]) ++ans2;
	cout<<max(ans1, ans2)<<endl;
	return void();  
}

int main()
{
	cin>>N;
	for(int i = 1, x; i <= N; i++)
		while(x = read(), x) g[i].push_back(x);
	solve();
	return 0;
}