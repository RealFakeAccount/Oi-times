#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e3 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;
P a[MAXN];

vector<P> cp;
void compress(){
	for(int i = 1; i <= N; i++) cp.push_back(P(a[i].first, 0));
	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());
	for(int i = 1; i <= N; i++)
		*lower_bound(cp.begin(), cp.end(), a[i].first).second++;
}

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
		a[i].first = read(), a[i].second = read();
	compress();
	int ans = (1 << 29), siz = 0;
	for(int i = 0; i < (int) cp.size(); i++){
		siz += cp[i].second;
		
	}
	return 0;
}