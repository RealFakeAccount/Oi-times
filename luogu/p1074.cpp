#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int score[9][9] = {
6, 6, 6, 6, 6, 6, 6, 6, 6,
6, 7, 7, 7, 7, 7, 7, 7, 6,
6, 7, 8, 8, 8, 8, 8, 7, 6,
6, 7, 8, 9, 9, 9, 8, 7, 6,
6, 7, 8, 9, 10,9, 8, 7, 6,
6, 7, 8, 9, 9, 9, 8, 7, 6,
6, 7, 8, 8, 8, 8, 8, 7, 6,
6, 7, 7, 7, 7, 7, 7, 7, 6,
6, 6, 6, 6, 6, 6, 6, 6, 6};

int s[9][9];
int bl[9], line[9], row[9], tot = 0, res = -(0x3f3f3f3f);
int n[(1 << 9)], f[(1 << 9)];

inline int getbl(int x, int y)
{return ((x / 3) * 3) + y / 3;}

inline void flip(int x, int y, int v)
{
	line[x] ^= v;
	row[y] ^= v;
	bl[getbl(x, y)] ^= v;
}

inline int ok(int i, int j)
{return (line[i] & row[j] & bl[getbl(i, j)]);}

inline int getrank()
{
	int ans = 0;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			ans += score[i][j] * s[i][j];
	return ans;
}

void dfs(int cnt)
{
	if(cnt == 0) return (res = max(res, getrank()), void()); 
	
	int tmp = 10, x, y;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(s[i][j]) continue;
			else 
			{
				int num = n[ok(i, j)];
				if(num == 0) return;
				if(num <= tmp) 
					x = i, y = j, tmp = num;
			}
	int cur = ok(x, y);
	for(int i = cur; i; i -= (i & (-i)))
	{
		int v = (i & (-i));
		s[x][y] = f[v];
		flip(x, y, v);
		dfs(cnt - 1);
		s[x][y] = 0;
		flip(x, y, v);
	}
	return;
}

int main()
{
	for(int i = 0; i < 9; i++) 
		line[i] = row[i] = bl[i] = (1 << 9) - 1;
	for(int i = 0; i < (1 << 9); i++)
		for(int j = i; j; j -= (j & -j)) ++n[i];
	for(int i = 0; i < 9; i++) f[(1 << i)] = i + 1;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			scanf("%d", &s[i][j]);
			if(s[i][j]) flip(i, j, (1 << (s[i][j] - 1)));
			else tot++;
		}
	dfs(tot);
	if(res >= 0) cout<<res<<endl;
	else puts("-1");
	return 0;
}