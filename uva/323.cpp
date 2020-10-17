#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 20;
const int MAXM = 21;
const int INF = 0x7f7f7f7f;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M;
int a[MAXN], b[MAXN];
int f[MAXN][MAXN];

inline void clean()
{

}

int main()
{
	while(cin>>N>>M, (N != 0 && M != 0))
	{
		clean();
		for(int i = 1; i <= N; i++)
			a[i] = read(), b[i] = read();
		read();

		f[0][0] = 0;
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= M; j++)
				for(int k = 1; k <= )
	}
	return 0;
}