#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 20;
const int INF = 0x3f3f3f3f;

inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N;
int a[MAXN], f[MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
		a[read()] = i;

	memset(f, 0x3f, sizeof(f));
	int cur;
	for(int i = 1; i <= N; i++)
	{
		cur = a[read()];
		*lower_bound(f, f + N + 1, cur) = cur;
	}

	cout<<(lower_bound(f, f + N + 1, INF) - f)<<endl;
	return 0;
}