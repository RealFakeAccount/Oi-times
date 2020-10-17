#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 2e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M, D;
int a[MAXN];

set<int> S;
map<int, int> mp;

int main()
{
	cin>>N>>M>>D;
	for(int i = 1; i <= N; i++) a[i] = read();
	for(int i = 1; i <= N; i++) 
		mp[a[i]] = 0, S.insert(a[i]);

	int ans = 1, p = 0;
	while(!S.empty()){
		set<int>::iterator it = S.lower_bound(p);
		if(it == S.end()) ++ans, p = 0;
		else {
			p = *it + 1 + D, mp[*it] = ans;
			S.erase(it);
		}
	}
	cout<<ans<<endl;
	for(int i = 1; i <= N; i++)
		printf("%d ", mp[a[i]]);
	return 0;
}