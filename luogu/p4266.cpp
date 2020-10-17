#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 20;
typedef pair<int, int> P;
typedef long long ll;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

priority_queue<P> q; 
int L, N, rf, rb;

int main()
{
	cin>>L>>N>>rf>>rb;
	for(int i = 1; i <= N; i++){
		P pos;
		pos.second = read(), pos.first = read();
		q.push(pos);
	}

	int pb = 0; ll ans = 0;
	while(!q.empty()){
		P pos = q.top(); q.pop();
		if(pos.second <= pb) continue;
		ans += (1LL * rf - rb) * (1LL * pos.second - pb) * pos.first;
		pb = pos.second;
	}
	cout<<ans<<endl;
	return 0;
}