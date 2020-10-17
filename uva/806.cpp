#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 64 + 5;

int N;

struct P
{
	int x, y;
	P(int x = 0, int y = 0) : x(x), y(y) {}
};

bool M[MAXN][MAXN];
vector<int> treenode;

namespace tools
{
	inline int get_sum()
	{

	}

	inline int get_size()
	{

	}

	inline int new_idx()
	{

	}

	inline int five_to_dec()
	{

	}

	inline int dec_to_five()
	{

	}

	inline void fill_squ()
	{

	}

	inline void upd_squ()
	{

	}
}

namespace solve
{
	void dfs(P p1, P p2, int idx, int dir)
	{
		using namespace tools;
		if(get_sum(p1, p2) == 0) return ;
		if(get_sum(p1, p2) == get_size(p1, p2)) 
		{
			treenode.push_back(new_idx(idx, dir));
			return ;
		}

		P mid = P((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
		dfs(p1, mid, new_idx(idx, 1), 1),
		dfs(P((p1.x + p2.x) / 2, p1.y), P(p2.x, ))
	}

	inline void pic_to_tree()
	{
		memset(M, 0, sizeof(M));
		treenode.clear();

		char ch;
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
			{
				ch = getchar();
				while(!isdigit(ch)) ch = getchar();
				M[i][j] = ch - '0';
			}
	}

	inline void tree_to_pic()
	{
		N = -N;
	}

}


int main()
{
	while(cin>>N, N != 0)
	{
		if(N > 0) solve::pic_to_tree();
		if(N < 0) solve::tree_to_pic();
	}
	return 0;
}