#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 2e5 + 20;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M;
int a[MAX << 1];
int d[MAXN], chg[MAXN];

inline int nxt(int j)
{
	if(j + 1 < M) return ++j;
	else return 0;
}

int main()
{
	cin>>N>>M;
	for(int i = 1; i <= N; i++) a[i] = read();
	
	a[0] = a[N];  a[N + 1] = a[1];
	for(int i = 1; i <= N; i++) ++d[a[i] % M];
	int cnt = 0, sh = N / M;
	for(int i = 0; i < M; i++) 
		if(d[i] != sh)
			if(d[i] > sh) 
			{
				d[i + 1] += d[i] - sh;
				cnt += d[i] - sh;
				chg[i] += d[i] - sh;
			}
			else
			{
				d[M] -= d[i] - sh;
				cnt += d[i] - sh;
				chg[M] += d[i] - sh;
			} 
	cout<<cnt<<endl;
	return 0;
}