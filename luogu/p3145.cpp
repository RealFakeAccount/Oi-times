#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std; 
typedef long long ll;
typedef pair<int, int> P;
const int MAXN = 5e4 + 20;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
P a[MAXN], b[MAXN];
int ym[2][MAXN]; ll siz = 0;

ll calc(bool ty){
	memcpy(a, b, sizeof(a));

	if(ty) for(int i = 1; i <= N; i++) swap(a[i].first, a[i].second); 

	sort(a + 1, a + N + 1);
	for(int i = N; i >= 1; i--) if(a[i].first == a[i + 1].first)
		a[i].second = a[i + 1].second;
	int n = unique(a + 1, a + N + 1) - (a + 1);

	memset(ym[0], -0x3f, sizeof(ym[0])); memset(ym[1], 0x3f, sizeof(ym[1]));
	for(int i = n; i >= 1; i--) 
		ym[0][i] = max(ym[0][i + 1], a[i].second),
		ym[1][i] = min(ym[1][i + 1], a[i].second);
	siz = (1LL * ym[0][1] - ym[1][1]) * (a[n].first - a[1].first);

	int tmp[2] = {-INF, INF}; ll ans = (1LL << 60);
	for(int i = 1; i < n; i++){
		tmp[0] = max(tmp[0], a[i].second), tmp[1] = min(tmp[1], a[i].second);
		ans = min(ans, (1LL * a[i].first - a[1].first) * (1LL * tmp[0] - tmp[1]) +
		 (1LL * a[n].first - a[i + 1].first) * (1LL * ym[0][i + 1] - ym[1][i + 1]));
	}
	return ans;
}

int main()
{
	freopen("p3145.in", "r", stdin);
	cin>>N;
	for(int i = 1; i <= N; i++)
		 b[i].first = read(), b[i].second = read();

	ll ans = min(calc(0), calc(1));
	cout<<siz - ans<<endl;
	return 0;
}