#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
typedef pair<int, int> P;
#define fir first
#define sec second
using namespace std;
const int MAXN = 32;

struct t
{
	P tar, emp; 
	t(P a, P b) : 
	tar(a), emp(b) {}
};

bool C[MAXN][MAXN];
int N, M, Q;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
P S, E, T;

int bfs()
{
	queue<t> q;

	t s; s.tar = S, s.emp = E;
	q.push(s);
	while(!q.empty())
	{
		t u = q.front(); q.pop();
		P p = u.emp;

		for(int i = 0; i < 4; i++)
		{
			P nxt(p.fir + dx[i], p.sec + dy[i]);
			if(C[nxt.fir][nxt.sec]) 
			{
				if(nxt == )
			}
		}
	}
}

int main()
{
	cin>>N>>M>>Q;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf(" %d", &C[i][j]);

	while(Q--)
	{
		cin>>E.fir>>E.sec>>S.fir>>S.sec>>T.fir>>T.sec;
		bfs();
	}
	return 0;
}