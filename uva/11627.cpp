#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#define X first
#define Y second
typedef pair<int, int> P;
using namespace std;
const int MAXN = 1e5 + 20;


int W, V, N, S;
P a[MAXN];
int bo[MAXN];

bool cmp(const P &lhs, const P &rhs)
{return lhs.Y < rhs.Y;}

bool calc(int u)
{
	
}

int main()
{
	int T; cin>>T;
	for(int t = 1; t <= T; t++)
	{
		cin>>W>>V>>N;
		for(int i = 1; i <= N; i++) 
			scanf("%d%d", &a[i].X, &a[i].Y);
		cin>>S;
		for(int i = 1; i <= S; i++)
			scanf("%d", &bo[i]);
		sort(bo + 1, bo + S + 1);
		sort(a + 1, a + N + 1, cmp);

		int l = 0, r = N;
		while(l < r)
		{
			if(calc( (((l) + (r)) >> 1) )) r = mid;
			else l = mid + 1;
		}
		if(l = 0) puts("IMPOSSIBLE");
		else {}
	}
	return 0;
}