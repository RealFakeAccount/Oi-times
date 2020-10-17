#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 5e4 + 20;

int N;

namespace treap
{
	extern struct Node *null;
	struct Node
	{
		char ch[60]; int val;
		Node *ls, *rs;
		Node() : val(0), ls(null), rs(null) {}

		inline bool operator <(const Node &rhs){
			return strcmp(ch, rhs.ch) < 0;
		}
	}node[MAXN], *null;
}using namespace treap;

Node *build()
{
	int sta[MAXN], top = 1;
	sta[top] = 1;
	for(int i = 2; i <= N; i++){
		while(top > 0 && node[sta[top]].val < node[i].val) --top;
		if(top) {
			node[i].ls = node[sta[top]].rs;
			node[sta[top]].rs = &node[i];
		}
		else node[i].ls = &node[sta[1]];
		sta[++top] = i;
	}
	return &node[sta[1]];
}

void dfs(Node *cur)
{
	putchar('(');
	if(cur->ls != null) dfs(cur->ls);
	printf("%s/%d", cur->ch, cur->val);;
	if(cur->rs != null) dfs(cur->rs);
	putchar(')');
}

int main()
{
	while(cin>>N, N)
	{
		for(int i = 1; i <= N; i++) 
			node[i] = Node(),
			scanf(" %[a-z]/%d", node[i].ch, &node[i].val);
		sort(node + 1, node + N + 1);
		dfs(build());
		putchar('\n');
	}
	return 0;
}