#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 5e3 + 20;
int N;
P a[MAXN];

inline bool check(int x)
{
	int w = 0, e = 0, res = 0;
	for(int i = 1; i <= N; i++)
	{
		w += a[i].first, e += a[i].second;
		if(max(w - x, 0) + max(e - x, 0) > res) return false;
		if(w == 0 && e > 0) --e;
		else if(e == 0 && w > 0) --w;
		else if(e && w && e + w > res) ++res;
	}
	return true;
}

int main()
{
	//freopen("1450.in", "r", stdin);
	int T; cin>>T;
	while(T--)
	{
		cin>>N;
		int l = 0, r = 0;
		for(int i = 1; i <= N; i++)
			scanf("%d%d", &a[i].first, &a[i].second),
			r += a[i].first + a[i].second;

		while(l < r)
		{
			int mid = ((l + r) >> 1);
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		cout<<((l - 1) < 0 ? 0 : (l - 1))<<endl;
	}
	return 0;
}