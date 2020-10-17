#include <iostream>
#include <algorithm>
using namespace std;

long long dp[10000], factor[10000];

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			factor[++cnt] = i;
			if(i * i != n) factor[++cnt] = n/i;
		}
	}
	factor[++cnt] = n;

	sort(factor + 1, factor + cnt + 1);

	for(int i = 1; i <= cnt; i++)
	{
		dp[i] = 1;
		for(int j = 1; j < i; j++)
		{
			if(factor[i] % factor[j] == 0)
				dp[i] += dp[j];
		}
	}

	cout << dp[cnt];
}

