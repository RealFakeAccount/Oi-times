#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 10 + 2;
typedef pair<int, int> P;

int N, M;
int A[MAXN][MAXN], B[MAXN][MAXN];

struct State
{
	int line[MAXN];
	int score;

	bool isfinal()
	{
		for(int i = 1; i <= N; i++) 
			if(line[i] != M) return false;
		return true;
	}

	State copy()
	{
		State cur;
		memscpy(&cur, this, sizeof(cur));
		return cur;
	}

	void expand(int player, vector<State> &ret)
	{
		for(int i = 1; i <= N; i++)
		{
			if(i == 1 && line[i] != M)
			{
				State s = copy();
				
			}
		}
	}
};

int alphabeta(State &s, int player, int alpha, int beta)
{
	if(s.isfinal()) return s.score;

	vector<State> ch;
	s.expand(player, ch);

	int n = ch.size();
	for(int i = 0; i < n; i++)
	{
		int v = alphabeta(ch[i], player ^ 1, alpha, beta);
		if(!player) alpha = max(alpha, v);
		else beta = min(beta, v);
		if(beta <= alpha) break;
	}
	return !player ? alpha : beta; 
}

int main()
{
	cin>>N>>M;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%d", &A[i][j]);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%d", &B[i][j]);


	return 0;
}