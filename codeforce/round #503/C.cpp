#include <set>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3e3 + 20;
typedef long long ll;
typedef pair<int, int> P;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M;
int par[MAXN];
int p[MAXN], c[MAXN];

priority_queue<P> cnt;
vector<int> cp;

priority_queue<int, greater<int> > beg[MAXM];

int main()
{
	cin>>N>>M;
	for(int i = 1; i <= N; i++) 
		p[i] = read(), c[i] = read(), ++par[p[i]];
	for(int i = 1; i <= N; i++) 
		beg[p[i]].push(c[i]);

	for(int i = 2; i <= M; i++) if(par[i]) 
		cnt.push(P(par[i], 1));
	
	for(int i = 2; i <= M; i++) if(par[i]) cp.push_back(i);

	ll ans = 0;
	while(true){
		P tmp(0, 0);
		for(int i = 0; i < (int) cp.size(); i++) if(tmp.second < par[cp[i]])
			tmp.second = par[cp[i]], tmp.first = i;
		if(tmp.second < par[1]) break;

		P res((1 << 29), 0);
		for(int i = 0; i < (int) cp.size(); i++){
			if(i == tmp.first){
				if(res.first < beg[cp[i]].top()) res.first = beg[cp[i]].top(), res.second = cp[i];
			}
			else 
		}
	}
	return 0;
}