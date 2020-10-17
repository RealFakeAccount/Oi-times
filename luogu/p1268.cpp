#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 30 + 2;

int N;
int M[MAXN][MAXN];

int main()
{
	while(cin>>N, N)
	{
		for(int i = 1; i < N; i++)
			for(int j = i + 1; j <= N; j++)
				scanf("%d", &M[i][j]);
		int ans = M[1][2];
		for(int i = 3; i <= N; i++){
			int tmp = (1 << 29);
			for(int j = 2; j < i; j++)
				tmp = min(tmp, M[1][i] - ((M[1][j] + M[1][i] - M[j][i]) >> 1));
			ans += tmp;
		}
		cout<<ans<<endl;
	}
	return 0;
}