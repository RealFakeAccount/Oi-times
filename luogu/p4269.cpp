#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

int N, B;
struct Node
{
	int val;
	Node *pre, *nxt;
}node[MAXN];

struct boot
{
	int dep, dis, idx, ans;
	inline bool operator >(const boot &rhs) const {
		return dep > rhs.dep;
	}
	inline bool operator <(const boot &rhs) const {
		return idx < rhs.idx;
	}
}b[MAXN];
struct Floor
{
	int dep, idx;
	Node *pos;
	inline bool operator >(const Floor &rhs) const {
		return dep > rhs.dep;
	}
	inline bool operator <(const Floor &rhs) const {
		return idx < rhs.idx;
	}
}f[MAXN];


void build(){
	f[1].pos = &node[1]; node[1].val = 1;
	for(int i = 2; i <= N; i++){
		node[i].pre = &node[i - 1], node[i - 1].nxt = &node[i];
		node[i].val = 1, f[i].pos = &node[i];
	}
}

int main()
{
	cin>>N>>B;
	for(int i = 1; i <= N; i++) f[i] = (Floor){read(), i};
	for(int i = 1; i <= B; i++) 
		b[i].dep = read(), b[i].dis = read(), b[i].idx = i;
	
	build();
	sort(f + 1, f + N + 1, greater<Floor>());
	sort(b + 1, b + B + 1, greater<boot>());

	int p = 1, maxs = 1;
	for(int i = 1; i <= B; i++){
		while(p <= N && f[p].dep > b[i].dep) {
			Node *cur = f[p].pos;
			cur->pre->nxt = cur->nxt;
			cur->nxt->pre = cur->pre;
			maxs = max(maxs, cur->pre->val += cur->val);
			++p;
		}
		if(maxs > b[i].dis) b[i].ans = 0;
		else b[i].ans = 1;
	}
	sort(b + 1, b + B + 1);
	for(int i = 1; i <= B; i++) printf("%d\n", b[i].ans);
	return 0;
}
