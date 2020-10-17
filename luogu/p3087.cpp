#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXK = 1e9;
const int MAXN = 1e2 + 10;

int N, K;
map<string, int> s[32];
int cal[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>K;
	string tmp;
	for(int i = 1; i <= N; i++){
		int cnt = 0;
		while(cin>>tmp, tmp != "no") ;
		while(cin>>tmp, tmp != "cow.") {
			++cnt;
			if(s[cnt].find(tmp) == s[cnt].end()) s[cnt][tmp] = 0;
			s[cnt][tmp]++;
		}
	}
	cal[N + 1] = 1;
	for(int i = N; i >= 1; i--) 
		cal[i] = min(1LL * MAXK + 1, 
			(long long)s[i].size() * cal[i + 1]);

	for(int i = 1; i <= N; i++){
		map<string, int>::iterator it = s[i].begin();
		while(cal[i] + it->second < K) K -= cal[i], ++it;
		cout<<it->first<<" ";
	}
	return 0;
}
