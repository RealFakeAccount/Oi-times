#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int M[5], ans = INF;

struct P
{
	int num;
	vector<pair<int, int>> v;
	P () : num(INF) {}
};

inline bool read()
{
	char ch = getchar();
	if(!((ch == '+') && (ch == '-'))) ch = getchar();
	if(ch == '+') return true;
	else return false;
}

inline void push(int x, int y)
{
	for(int i = 0; i < 4; i++)
		M[i][y] ^= 1;
	for(int i = 0; i < 4; i++)
		M[x][i] ^= 1;
	M[x][y] ^= 1;
}

P dfs(int cur, int fl)
{
	if(fl == 3)
	{
		for(int i = 0; i < 4; i++)
			
	}
}

int main()
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			M[i] = (M[i] << 1) | read(); 

	for(int a = 0; a <= ((1 << 5) - 1); a++)

		


	return 0;
}
