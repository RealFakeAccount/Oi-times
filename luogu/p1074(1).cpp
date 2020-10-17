#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int st[11][11];
int score[11][11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 6, 6, 6, 6, 6, 6, 6, 6, 6,
					 0, 6, 7, 7, 7, 7, 7, 7, 7, 6,
					 0, 6, 7, 8, 8, 8, 8, 8, 7, 6,
					 0, 6, 7, 8, 9, 9, 9, 8, 7, 6,
					 0, 6, 7, 8, 9, 10,9 ,8, 7, 6, 
					 0, 6, 7, 8, 9, 9, 9, 8, 7, 6,
					 0, 6, 7, 8, 8, 8, 8, 8, 7, 6,
					 0, 6, 7, 7, 7, 7, 7, 7, 7, 6,
					 0, 6, 6, 6, 6, 6, 6, 6, 6, 6,
					 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


inline int getsq(int x, int y)
{
	if(x <= 3)
	{
		if(y <= 3) return 1;
		if(y <= 6) return 2;
		if(y <= 9) return 3;
	}
	if(x <= 6)
	{
		if(y <= 3) return 4;
		if(y <= 6) return 5;
		if(y <= 9) return 6;
	}
	if(x <= 9)
	{
		if(y <= 3) return 7;
		if(y <= 6) return 8;
		if(y <= 9) return 9;
	}
	return -1;
}

inline int lowbit(int x)
{
	return x & (-x);
}

int ans = 0;
bool dfs(int x, int y)
{

}

int main()
{
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 9; j++)
		{
			scanf("%d", &st[i][j]);
			int p = 10 - st[i][j];
			st[i][j] == 0 ? continue : ( (sq[getsq(i, j)] ^= (1 << p)),
										 (li[i] ^= (1 << p)),
										 (ro[j] ^= (1 << p)),
										 (nsq[getsq(i, j)]++),
										 (nli[i]++),
										 (nro[j]++));
		}

	dfs(5, 5);

	return 0;
}