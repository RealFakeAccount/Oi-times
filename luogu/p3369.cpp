#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline int readInt() {
	static int n, ch;
	static bool flag;
	n = 0, ch = getchar(), flag = false;
	while (!isdigit(ch)) flag |= ch == '-', ch = getchar();
	while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
	return flag ? -n : n;
}

const int MAX_N = 100000 + 3;

struct Treap {
	struct Node {
		Node *ls, *rs;
		int val, key, s;
				
		inline void maintain() {
			s = ls->s + rs->s + 1;
		}
	} pool[MAX_N + 3], *pit, *null, *root;
	
	inline Node *newNode(int key) {
		pit->ls = pit->rs = null;
		pit->val = rand(), pit->key = key, pit->s = 1;
		return pit++;
	}
	
	void init() {
		pit = pool;
		null = newNode(0), null->s = 0;
		root = null;
	}
	
	inline Node *merge(Node *a, Node *b) {
		if (a == null) return b;
		if (b == null) return a;
		
		if (a->val < b->val) {
			a->rs = merge(a->rs, b);
			a->maintain();
			return a;
		} else {
			b->ls = merge(a, b->ls);
			b->maintain();
			return b;
		}
	}
	
	inline void split(Node *o, int k, Node *&l, Node *&r) {
		if (o == null) {
			l = r = null;
			return;
		}
		
		if (k <= o->ls->s) {
			split(o->ls, k, l, r);
			o->ls = r;
			r = o;
		} else {
			split(o->rs, k - o->ls->s - 1, l, r);
			o->rs = l;
			l = o;
		}
		
		o->maintain();
	}

	int lowerCount(const Node *o, int key) {
		if (o == null) return 0;
		return key <= o->key ? lowerCount(o->ls, key) : lowerCount(o->rs, key) + o->ls->s + 1;
	}
	
	int upperCount(const Node *o, int key) {
		if (o == null) return 0;
		return key < o->key ? upperCount(o->ls, key) : upperCount(o->rs, key) + o->ls->s + 1;
	}
	
	int findKth(const Node *o, int k) {
		if (k == o->ls->s + 1) return o->key;
		return k <= o->ls->s ? findKth(o->ls, k) : findKth(o->rs, k - o->ls->s - 1);
	}
	
	inline void insert(int key) {
		Node *l, *r;
		split(root, lowerCount(root, key), l, r);
		root = merge(merge(l, newNode(key)), r);
	}
	
	inline void erase(int key) {
		Node *pred, *tmp, *target, *succ;
		split(root, lowerCount(root, key), pred, tmp);
		split(tmp, 1, target, succ);
		root = merge(pred, succ);
	}
	
	inline int rank(int key) {
		return lowerCount(root, key) + 1;
	}
	
	inline int select(int k) {
		return findKth(root, k);
	}
	
	inline int pred(int key) {
		return findKth(root, lowerCount(root, key));
	}
	
	inline int succ(int key) {
		return findKth(root, upperCount(root, key) + 1);
	}
} treap;

int main() {
	int n = readInt();
	
	treap.init();

	for (int i = 0; i < n; ++i) {
		int type = readInt(), x = readInt();
		if (type == 1) treap.insert(x);
		else if (type == 2) treap.erase(x);
		else if (type == 3) printf("%d\n", treap.rank(x));
		else if (type == 4) printf("%d\n", treap.select(x));
		else if (type == 5) printf("%d\n", treap.pred(x));
		else if (type == 6) printf("%d\n", treap.succ(x));
	}
	
//	for (int i = 1; i <= treap.root->s; ++i)
//		cout << treap.select(i) << ' '; cout << endl;
	return 0;
}
