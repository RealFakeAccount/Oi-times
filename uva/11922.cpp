#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 20;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return x;
}

int N, M;

namespace Treap
{
	struct Node *null;
	struct Node
	{
		int key, val, siz;
		bool tag;
		Node *ls, *rs;

		Node(int key = 0, int val = rand()) : 
		key(key), val(val), siz(1), 
		tag(false), ls(null), rs(null) {};

		inline void pushup(){
			this->siz = ls->siz + rs->siz + 1;
		}

		inline void givetag(){
			this->tag ^= 1;
			swap(this->ls, this->rs);
		}

		inline void pushdown(){
			if(this->tag){
				ls->givetag(), rs->givetag();
				this->tag = false;
			}
		}
	}pool[MAXN], *pit = pool;

	void init()
	{
		null = new (pit++) Node(); 
		null->siz = 0; //null->ls = null->rs = null;
	}

	Node *sta[MAXN];
	Node *build()
	{
		int top = 0;
		sta[++top] = new (pit++) Node(1);
		for(int i = 2; i <= N; i++){
			Node *cur = new (pit++) Node(i);
			while(top > 0 && sta[top]->val > cur->val) sta[top--]->pushup();
			if(top){
				cur->ls = sta[top]->rs;
				sta[top]->rs = cur;
			}
			else 
				cur->ls = sta[1];
			sta[++top] = cur;
		}
		return sta[1];
	}

	Node *merge(Node *a, Node *b)
	{
		if(a == null) return b;
		if(b == null) return a;
		if(a->val < b->val){
			a->pushdown();
			a->rs = merge(a->rs, b);
			return a->pushup(), a;
		}
		else {
			b->pushdown();
			b->ls = merge(a, b->ls);
			return b->pushup(), b;
		}
	}

	typedef pair<Node*, Node*> Droot;
	Droot spilt(Node *cur, int k)
	{
		Droot d(null, null);
		if(cur == null) return d;
		cur->pushdown();
		if(k <= cur->ls->siz){
			d = spilt(cur->ls, k);
			cur->ls = d.second;
			cur->pushup();
			d.second = cur;
		}
		else {
			d = spilt(cur->rs, k - cur->ls->siz - 1);
			cur->rs = d.first;
			cur->pushup();
			d.first = cur;
		}
		return d;
	}
}using namespace Treap;

void dfs(Node *cur)
{
	cur->pushdown();
	if(cur->ls != null) dfs(cur->ls);
	printf("%d\n", cur->key);
	if(cur->rs != null) dfs(cur->rs);
}

int main()
{
	srand(19260817);
	cin>>N>>M;
	init(); Node *root = build();
	while(M--){
		int l = read(), r = read();
		Droot a = spilt(root, l - 1), b = spilt(a.second, r - l + 1);
		b.first->givetag();
		root = merge(merge(a.first, b.second), b.first);
	}
	dfs(root);
	return 0;
}