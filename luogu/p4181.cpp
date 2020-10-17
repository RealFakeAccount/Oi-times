#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int MAXN = 1e5 + 20;

inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M, R;
int buy[MAXN]; P shop;
int cow[MAXN];
priority_queue<P> q;

int main()
{
	cin>>N>>M>>R;
	for(int i = 1; i <= N; i++) cow[i] = read();
	for(int i = 1; i <= M; i++) 
		shop.second = read(), shop.first = read(), q.push(shop);
	for(int i = 1; i <= R; i++) buy[i] = read();
	sort(cow + 1, cow + N + 1);
	sort(buy + 1, buy + R + 1);

	int l = 1, r = N, b = R; 
	ll ans = 0, tmp = -1; 
	for(int i = 1; i <= N; i++){
		if(tmp == -1) while(!q.empty() && cow[r]) {
			if(tmp == -1) tmp = 0;
			if(q.top().second > cow[r]) {
				P p = q.top(); q.pop();
				tmp += 1LL * cow[r] * p.first,
				p.second -= cow[r], cow[r] = 0;
				q.push(p);
			}
				
			else 
				tmp += 1LL * q.top().first * q.top().second,
			    cow[r] -= q.top().second, q.pop();
		} 
		if(tmp != -1 && tmp >= buy[b])
			ans += tmp, tmp = -1, --r;
		else if(b != 0) ans += buy[b--], ++l;
	}
	cout<<ans<<endl;
	return 0;
}
