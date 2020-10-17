#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, ll> P;
const int MAXN = 1e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, T; 
P a[MAXN];

namespace ufs
{
	int fa[MAXN];
	void init(){for(int i = 1; i <= N; i++) fa[i] = i;}
	int findfa(int x){return fa[x] == x ? x : findfa(fa[x]);}
	void unite(int x, int y){fa[findfa(x)] = findfa(y);}
}

bool vis[MAXN];
int main()
{
	freopen("p3111.in", "r", stdin);
	cin>>N>>T;
	for(int i = 1; i <= N; i++) 
		a[i].first = read(), a[i].second = read();
	for(int i = 1; i <= N; i++)
		a[i].second = 1LL * a[i].first + 1LL * T * a[i].second;
	ufs::init();
	for(int i = 1; i < N; i++)
		if(a[i].second >= a[i + 1].second)
			ufs::unite(i, i + 1);
	int ans = 0;
	for(int i = 1; i <= N; i++) if(!vis[ufs::findfa(i)]){
		vis[ufs::findfa(i)] = true; ans++;
	}
	cout<<ans<<endl;
	return 0;
}