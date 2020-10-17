#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8;
const int MAXN = 12 + 1;

inline int read()
{
	static int x;
	scanf(" %d", &x);
	return x;
}

int M, N;
bool ok[1 << 13];
int f[13][1 << 13], m[MAXN];

int main()
{
	cin>>M>>N;

	for(int i = 1; i <= M; i++)
		for(int j = 0; j < N; j++)
			m[i] |= (read() << j);

	bool flag;
	for(int i = 0; i < (1 << N); i++)
	{
		flag = false;
		for(int j = 1; j < 13; j++)
			if( ((i >> j) & 1) & ( (i >> (j - 1)) & 1) ) flag = true;
		ok[i] = (flag == false);
	}

	f[0][0] = 1;
	for(int i = 1; i <= M; i++)
		for(int j = 0; j < (1 << N); j++)
		{
			if(ok[j] && ((m[i] | j) == m[i]))
				for(int k = 0; k < (1 << N); k++)
					if((j & k) == 0)
						f[i][j] = (f[i - 1][k] + f[i][j]) % mod;
		}

	int ans = 0;
	for(int i = 0; i < (1 << N); i++)
		ans = (ans + f[M][i]) % mod;
	cout<<ans<<endl;
	return 0;
}