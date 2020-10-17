#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, H;
P a[MAXN], b[MAXN << 1];


int main()
{
	cin>>N>>H;
	for(int i = 1; i <= N; i++)
		a[i].first = read(), a[i].second = read();

	sort(a + 1, a + N + 1);
	int p = 0;
	for(int i = 1; i < N; i++){
		b[++p].first = 0, 
		b[p].second = a[i].second - a[i].first;
		b[++p].first = a[i + 1].first - a[i].second, 
		b[p].second = a[i + 1].first - a[i].second;
	}
	b[++p].first = 0, b[p].second = a[N].second - a[N].first;
	b[++p].first = INF, b[p].second = INF;

	int l = 0, ans = 0, tmp = 0, dis = 0;
	for(int r = 1; r <= p; r++){
		while(tmp > H) {
			tmp -= a[l].first, dis -= a[l].second;
			++l;
		}
		ans = max(ans, H - tmp + dis);
		tmp += a[r].first, dis += a[r].second;
	}
	cout<<ans<<endl;
	return 0;
}