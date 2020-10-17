#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 20;
const int MAXP = 1e4 + 20;
const int MAXL = 1000000 + 20;

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, P, K;

namespace edges
{
	struct edge
	{
		int from, to, cost;
		edge(int u = 0, int v = 0, int c = 0) : from(u), to(v), cost(c) {}

		bool operator <(const edge &rhs) const{
			return c < rhs.c;
		}
	}E[MAXP];

	inline void addedge(int u, int v, int c)
	{
		static int cnt = 1;
		E[cnt++] = edge(u, v, c);
	}

	inline void init()
	{
		sort(E + 1, E + P + 1);
	}
}

inline bool check(int fare)
{
	for(int i = 1; i <= P; i++)
	{
		
	}
}

int main()
{
	cin>>N>>P>>K;

	int u, v;
	for(int i = 1; i <= P; i++)
	{
		u = read(), v = read();
		addedge(u, v, read());
	}

	edges::init();

	int l = 0; r = MAXL;
	#define mid (((l) + (r)) >> 1)
	while(l < r)
	{
		if(check(mid)) r = mid;
		else l = mid + 1;
	}

	cout<<l<<endl;
	return 0;
}