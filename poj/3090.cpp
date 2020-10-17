#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int MAXN = 1e3 + 20;

int N, C;

int phi[MAXN];

void euler(int n)
{
	for(int i = 2; i <= n; i++) phi[i] = i;
	for(int i = 2; i <= n; i++)
		if(phi[i] == i)
			for(int j = i; j <= n; j += i)
				phi[j] = phi[j] / i * (i - 1);
}

int main()
{
	cin>>C; euler(1010);
	int cnt = 0;
	while(C--)
	{
		cnt++;
		cin>>N;
		long long ans = 0;
		for(int i = 2; i <= N; i++) ans += phi[i];
		ans *= 2, ans += 3;
		cout<<cnt<<" "<<N<<" "<<ans<<endl;
	}
	return 0;
}