#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 20;
typedef long long ll;
typedef pair<int, int> P;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int N; ll M;
int a[MAXN], b[MAXN];
int c[MAXN];

int main()
{
	cin>>N>>M; ll sum = 0;
	for(int i = 1; i <= N; i++) 
		a[i] = read(), b[i] = read(), 
		c[i] = a[i] - b[i], sum += a[i];
	sort(c + 1, c + N + 1, greater<int>());
	int cnt = 0;
	for(int i = 1; i <= N; i++){
		if(sum <= M) break;
		++cnt; sum -= c[i];
	}
	if(sum > M) puts("-1");
	else cout<<cnt<<endl;
	return 0;
}