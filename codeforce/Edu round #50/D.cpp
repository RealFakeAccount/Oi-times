#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 10;
inline int read()
{
	int x = 0; char ch = getchar(); bool f = false;
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}

struct Node
{
	ll val;
	Node *ls, *rs;
}a[MAXN], b[MAXN];

int N, M;

inline void unite(Node *cur){
	cur->val += cur->rs->val;
	cur->rs = cur->rs->rs;
	cur->rs->rs->ls = cur;
}

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++){
		a[i].val = read();
		if(i != 1) a[i].ls = &a[i - 1];
		a[i].rs = &a[i + 1];
	}
	a[N + 1].val = -1, a[N + 1].ls = &a[N];
	cin>>M;
	for(int i = 1; i <= M; i++){
		b[i].val = read();
		if(i != 1) b[i].ls = &b[i - 1];
		b[i].rs = &b[i + 1];
	}
	b[M + 1].val = -1, b[M + 1].ls = &b[M];
	ll sum1 = 0;
	for(int i = 1; i <= N; i++) sum1 += a[i].val;
	ll sum2 = 0;
	for(int i = 1; i <= M; i++) sum2 += b[i].val;
	if(sum1 != sum2) puts("-1");
	else{
		int cnt = 0;
		Node *p1 = &a[1], *p2 = &b[1];
		while(p1->val != -1 && p2->val != -1){
			if(p1->val == p2->val) 
				p1 = p1->rs, p2 = p2->rs, ++cnt;
			else {
				if(p1->val < p2->val) unite(p1);
				else unite(p2);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
