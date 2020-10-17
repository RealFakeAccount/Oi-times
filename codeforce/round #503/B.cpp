#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
int p[MAXN];

int incir[MAXN];

namespace SCC
{
	int low[MAXN], dfn[MAXN];
	stack<int> sta; bool ins[MAXN];

	int tarjan(int cur){
		static int dfsclock = 0;
		low[cur] = dfn[cur] = ++dfsclock;
		sta.push(cur), ins[cur] = true;

		int v = p[cur];
		if(!dfn[v]) low[cur] = min(low[cur], tarjan(v));
		else if(ins[v]) low[cur] = min(low[cur], dfn[v]);

		if(low[cur] == dfn[cur]){
			vector<int> tmp;
			do{
				v = sta.top(); sta.pop();
				ins[v] = false; tmp.push_back(v);
			}while(v != cur);

			if(tmp.size() > 1){
				for(int i = 0; i < (int) tmp.size(); i++) 
					incir[tmp[i]] = -1;
			}
		}
		return low[cur];
	}

	void calc(){
		for(int i = 1; i <= N; i++) if(!dfn[i]) tarjan(i);
	}
}

int dfs(int cur){
	if(incir[cur] == -1 || p[cur] == cur) return cur;
	if(incir[cur] != 0) return incir[cur];
	else return incir[cur] = dfs(p[cur]);
}

int ans[MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++) p[i] = read();
	SCC::calc();
	for(int i = 1; i <= N; i++) ans[i] = dfs(i);
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]); 
	return 0;
}
