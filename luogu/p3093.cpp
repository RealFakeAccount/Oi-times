#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e4 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
P a[MAXN]; int mxt;

namespace ufs
{
	int fa[MAXN];

	void init(){for(int i = 1; i <= mxt; i++) fa[i] = i;}
	int findfa(int x){return fa[x] == x ? x : findfa(fa[x]);}
}

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
		a[i].first = read(), a[i].second = read() + 1, mxt = max(mxt, a[i].second);
	sort(a + 1, a + N + 1, greater<P>());
	ufs::init(); int ans = 0;

	for(int i = 1; i <= N; i++){
		using namespace ufs;
		int tmp = findfa(a[i].second - 1);
		if(tmp == 0) continue; 
		
		ans += a[i].first;
		fa[tmp] = findfa(tmp - 1);
	}
	cout<<ans<<endl;
	return 0;
}
