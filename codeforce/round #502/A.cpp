#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N;

struct peo
{
	int val, idx;
	bool operator <(const peo &rhs) const{
		if(val == rhs.val) return idx < rhs.idx;
		return val > rhs.val;
	}
}p[MAXN];

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= 4; j++) p[i].val += read();
		p[i].idx = i;
	}
	sort(p + 1, p + N + 1);
	for(int i = 1; i <= N; i++) if(p[i].idx == 1){
		cout<<i<<endl;
		return  0;
	}
	return 0;
}