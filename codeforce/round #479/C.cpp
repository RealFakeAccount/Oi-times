#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 20;

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int a[MAXN], N, K;

int main()
{
	cin>>N>>K;
	for(int i = 1; i <= N; i++)
		a[i] = read();

	sort(a + 1, a + N + 1);
	if(K == 0 && a[1] == 1)
	{
		puts("-1");
		return 0;
	}

	if(K == 0)
	{
		puts("1");
		return 0;
	}

	if(a[K] == a[K + 1])
	{
		puts("-1");
		return 0;
	}

	cout<<a[K]<<endl;
	//k == 0!
	return 0;
}