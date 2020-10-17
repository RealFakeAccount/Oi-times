#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 20;
const int MAXK = 50 + 2;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int N, K, P;
int col[MAXN], minc[MAXN];
int sum[MAXK], cnt[MAXK];

int main()
{
	cin>>N>>K>>P;
	for(int i = 1; i <= N; i++)
		col[i] = read(), minc[i] = read();
	for(int i = 1; i <= N; i++) ++sum[col[i]];
	long long ans = 0;
	for(int i = 1; i <= N; i++){
		++cnt[col[i]];
		--sum[col[i]];
		if(minc[i] <= P){
			for(int j = 0; j <= K; j++){
				if(j == col[i]) ans += cnt[j] * (sum[j] + 1) - 1;
				else ans += cnt[j] * sum[j];
				cnt[j] = 0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
