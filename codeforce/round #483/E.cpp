#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 2e3 + 20;

int N;
P pe[MAXN];

struct sit
{
	P q[4];
	int l, t, f, p; 
	sit() {for(int i = 0; i < 4; i++) q[i] = P(0, 0);}
};

void bfs()
{
	queue<sit> que;

	sit s();
	s.l = 1, s.t = 0, s.f = 1, s.p = 0;
	que.push(s);
	while(!que.empty())
	{
		sit cur = que.front(); que.pop();

		if(cur.p < 4)
		{
			if(pe[cur.l + 1].first == cur.f)
			{
				sit nxt = cur;
				nxt.p++;
				nxt.t++;
				nxt.l++;
				q.push(nxt);
			}
		}
		if(cur.p > 0)
		{
			for(int i = 1; i < cur.p; i++)
				if()
		}
	}
}

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
		scanf(" %d %d", &pe[i].first, &pe[i].second);
	bfs();
	return 0;
}