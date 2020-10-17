#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000 + 20;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int N, M, S;
int a[MAXN];
bool vis[MAXN];
vector<int> ans;

int main()
{
	cin>>N>>M>>S;
	for(int i = 1; i <= M; i++) a[i] = read();
	int cnt = 0; int p = 0; a[M + 1] = N;
	for(int i = 1; i <= M + 1; i++){
		if(a[i] - a[p] < S) continue;
		vis[i] = true;
		p = i; ++cnt;
		ans.push_back(i);
	}
	p = M + 1;
	for(int i = M; i >= 0; i--){
		if(a[p] - a[i] < S || vis[i]) continue;
		vis[i] = true;
		p = i; ++cnt;
		ans.push_back(i);
	}
	if(cnt != M + 2) puts("NO");
	else {
		puts("YES");
		for(int i = 0; i < (int) ans.size(); i++) {
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}