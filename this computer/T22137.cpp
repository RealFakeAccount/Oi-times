#include <bits/stdc+.h>
using namespace std;
const int MAXN=1000000+2;

int N,M;
struct node 
{
	vector<int> to;
	int val; 
}g[MAXN];

namespace Stree
{

}

int dfn][MAXN],siz[MAXN],
void dfs1(int u)
{

}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&g[i].val);
	}	

	int u,v;
	for(int i=1;i<=N-1;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].to.push_back(v);
		g[v].to.push_back(u);
	}

	while(M--)
	{

	}
	return 0;
}