#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, M;
int a[MAXN];

map<int, int> mp;
int main()
{
	cin>>N>>M;
	for(int i = 1; i <= N; i++) a[i] = read();
	for(int i = 1; i <= N; i++) 
		mp[i - a[i]]++, mp[i + a[i]]++;

	ll ans = 0;
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
		ans += 1LL * it->second * (it->second - 1) / 2;

	cout<<ans<<endl;
	return 0;
}