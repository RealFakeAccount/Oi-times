#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e2 + 5;

int N, M;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int x[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, 
	y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

inline bool check(int i, int j)
{
	if(b[i][j] == 1)
	{
		for(int k = 0; k < 8; k++)
			if(b[i + x[k]][j + y[k]] == 2) 
				return false;
	}
	else if(b[i][j] == 0)
	{
		int cnt = 0;
		for(int k = 0; k < 8; k++)
				cnt += (b[i + x[k]][j + y[k]] == 2) ;
		if(cnt != a[i][j]) return false;
	}
	return true;
}

int main()
{
	cin>>N>>M;
	char ch;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
		{
			scanf(" %c", &ch);
			a[i][j] = isdigit(ch) ? ch - '0' : 0;
			if(ch == '.') b[i][j] = 1;
			else if(ch == '*') b[i][j] = 2;
		}

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			if(!check(i, j)) {puts("NO"); return 0;}
	puts("YES");
	return 0;
}