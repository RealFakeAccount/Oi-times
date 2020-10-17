#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 1e3 + 20;
const int MAXP = 3e2 + 20;

int N, p1, p2;
int cnt[MAXP << 1][2];
int all = 0;

namespace ufs
{
	int fa[MAXP << 1], d[MAXP << 1];

	void init(){
		for(int i = 0; i <= (p1 + p2); i++) fa[i] = i;
		memset(d, 0, sizeof(d));
	}

	int findfa(int x){
		if(fa[x] == x) return x;

		int tmp = findfa(fa[x]);
		d[x] ^= d[fa[x]];
		return fa[x] = tmp;
	}

	void unite(int x, int y, int t){
		int u = findfa(x),  v = findfa(u);
		fa[u] = v, d[u] = d[x] ^ d[y] ^ t;
	}
}

namespace idx
{
	map<int, int> M;
	void init(){
		M.clear(); all = 0;
	}

	inline int getnum(int x){
		if(M.find(x) == M.end()){
			M[x] = ++all; return all;
		} 
		else return M[x];
	}
}

int f[MAXN][MAXP], pre[MAXN][MAXP];
int main()
{
	while(cin>>N>>p1>>p2, (N + p1 + p2))
	{
		int x, y; char ch[5];
		for(int i = 1; i <= N; i++){
			scanf("%d %d %[^\n]", &x, &y, ch);
			if(ch[0] == 'n'){
				ufs::unite(x, y, 1);
			}
			else {
				ufs::unite(x, y, 0);
			}
		}
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= (p1 + p2); i++){
			cnt[idx::getnum(ufs::findfa(i))][ufs::d[i]]++;
		}

		memset(f, 0, sizeof(f)); f[0][0] = 1;
		for(int i = 1; i <= all; i++){
			for(int j = p1; j >= 0; j++){
				if(j - cnt[i][0] >= 0 && f[i - 1][j - cnt[i][0]]){
					f[i][j] += f[i - 1][j - cnt[i][0]];
					pre[i][j] = j - cnt[i][0];
				}
				if(j - cnt[i][1] >= 0 && f[i - 1][j - cnt[i][1]]){
					f[i][j] += f[i - 1][j - cnt[i][1]];
					pre[i][j] = j - cnt[i][1];
				}
			}
		}
		if(f[all][p1] != 1) {puts("no\n"); return 0;}
		
	}
	return 0;
}