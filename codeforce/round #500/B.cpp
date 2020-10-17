#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 1e5 + 20;
typedef pair<int, bool> P;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int N, X;
int a[MAXN];
map<int, bool> M;

int main()
{
	cin>>N>>X; int ans = (1 << 29);
	M.clear();
	for(int i = 1; i <= N; i++) a[i] = read();
	//sort(a + 1, a + N + 1);
	for(int i = 1, u; i <= N; i++){
		u = a[i];
		if(M.find(u) != M.end()){
			if(M[u]) ans = min(ans, 1);
			else ans = min(ans, 0);
		}
		if(M.find(u & X) != M.end()){
			if(M[u & X]) ans = min(ans, 2);
			else ans = min(ans, 1);
		}
		if(M.find(u) == M.end() || M[u] == true) M[u] = false;
		if((u & X) != u && M.find(u & X) == M.end()) M.insert(P(u & X, true));
	} 
	if(ans == (1 << 29)) puts("-1");
	else printf("%d\n", ans);
	return 0;
}
