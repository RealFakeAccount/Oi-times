#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e3 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, R;
int w[MAXN];
bool vis[MAXN];

inline bool check(int x)
{
	memset(vis, false, sizeof(vis));
	int cnt = 0, ans = 0;
	while(cnt < N){
		int wei = 0;
		for(int i = N; i >= 1; i--) if(!vis[i] && wei + w[i] <= x){
			vis[i] = true;
			wei += w[i]; ++cnt;
			if(wei == x) break;
		}
		++ans;
	}
	return ans <= R;
}

int main()
{
	cin>>N>>R;
	int l = 0, r = 0;
	for(int i = 1; i <= N; i++) w[i] = read(), r += w[i];
	sort(w + 1, w + N + 1); l = w[N];
	while(l < r){
		int mid = ((l + r) >> 1);
		if(!check(mid)) l = mid + 1;
		else r = mid;
	}
	cout<<l<<endl;
	return 0;
}
