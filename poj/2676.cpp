#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int s[9][9], t[9][9], cnt[(1 << 9)], num[(1 << 9)];
int line[9], row[9], bl[9];

inline int getbl(int x, int y)
{return ((x / 3) * 3) + (y / 3);}

inline void flip(int x, int y, int v)
{
	line[x] ^= v;
	row[y] ^= v;
	bl[getbl(x, y)] ^= v;
}

bool dfs(int cur)
{
	if(cur == 0) return true;

	int tmp = 10, x, y, al;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			if(s[i][j] != 0) continue;
			al = (line[i] & row[j] & bl[getbl(i, j)]);
			if(al == 0) return false;
			
			if(cnt[al] <= tmp) x = i, y = j;
		}

	for(int i = (line[x] & row[y] & bl[getbl(x, y)]); i; i -= (i & (-i)))
	{
		int v = i & (-i);
		s[x][y] = num[v];
		flip(x, y, v);
		if(dfs(cur - 1)) return true;
		flip(x, y, v);
		s[x][y] = 0;
	}
	return false;
}

int main()
{
	//freopen("test.out", "r", stdin);
	for(int i = 0; i < (1 << 9); i++)
		for(int j = i; j ; j -= (j & (-j))) ++cnt[i];
	for(int i = 0; i < 9; i++) num[(1 << i)] = i + 1;
	while(T--)
	{
		char buf[12]; int tot = 0;
		for(int i = 0; i < 9; i++) bl[i] = line[i] = row[i] = ((1 << 9) - 1);
		for(int i = 0; i < 9; i++)
		{
			cin>>buf;
			for(int j = 0; j < 9; j++)
			{
				s[i][j] = buf[j] - '0';
				if(s[i][j]) flip(i, j, (1 << (s[i][j] - 1)));
				else ++tot;
			}
		}
		dfs(tot);
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0;j < 9; j++)
				cout<<s[i][j];
			cout<<'\n';
		}
	}
	return 0;
}
