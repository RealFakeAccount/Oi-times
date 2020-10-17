#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
const int MAXN = 1e5 + 20;
inline int read()
{
	int x = 0; char ch = getchar(); bool flag = false;
	while(!isdigit(ch)) flag |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return flag ? -x : x;
}

int N, M;
int a[MAXN];

namespace Treap
{
	struct Node *null;
	struct Node
	{
		int key, val, siz;
		bool rot;
		Node *ls, *rs;

		Node(int key = 0, int val = rand()) : 
		key(key), val(val), siz(1), 
		rot(false), ls(null), rs(null) {} 

		inline void pushup(){
			this->siz = ls->siz + rs->siz + 1;
		}

		inline void givetag(){
			this->rot ^= 1;
			swap(this->ls, this->rs);
		}

		inline void pushdown(){
			if(this->rot){
				ls->givetag(), rs->givetag();
				this->rot = false;
			}
		}
	}pool[MAXN], *pit = pool;

	void init()
	{
		null = new (pit++) Node();
		null->siz = 0;
		null->ls = null->rs = null;
	}

	Node *sta[MAXN];
	Node *build()
	{
		int top = 0;
	    sta[++top] = new (pit++) Node(1);
		for(int i = 2; i <= N; i++){
			Node *cur = new (pit++) Node(i);
			while(top > 0 && sta[top]->val > cur->val) 
				sta[top--]->pushup();
			if(top){
				cur->ls = sta[top]->rs;
				sta[top]->rs = cur;
			}
			else cur->ls = sta[1];
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

	typedef pair<Node *, Node *> Droot;
	Droot spilt(Node *o, int k)
	{
		Droot d(null, null);
		if(o == null) return d;

		o->pushdown();
		if(k <= o->ls->siz) {
			d = spilt(o->ls, k);
			o->ls = d.second;
			o->pushup();
			d.second = o;
		}
		else {
			d = spilt(o->rs, k - o->ls->siz - 1);
			o->rs = d.first;
			o->pushup();
			d.first = o;
		}
		return d;
	}
}using namespace Treap;

void dfs(Node *cur)
{
	cur->pushdown();
	if(cur->ls != null) dfs(cur->ls);
	printf("%d ", cur->key);
	if(cur->rs != null) dfs(cur->rs);
}

int main()
{
	cin>>N>>M; init();
	Node *root = build();
	while(M--)
	{
		//assert(null->rot == false);
		int l = read(), r = read();
		Droot a = spilt(root, l - 1), b = spilt(a.second, r - l + 1);
		b.first->givetag();
		root = merge(a.first, merge(b.first, b.second));
	}
	dfs(root);
	return 0;
}