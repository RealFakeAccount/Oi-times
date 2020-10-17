//  Created by Sengxian on 3/28/16.
//  Copyright (c) 2016年 Sengxian. All rights reserved.
//  BZOJ 1798 线段树
#include <bits/stdc++.h>
using namespace std;

inline int readInt() {
	static int n, ch;
	n = 0, ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
	return n;
}

const int MAX_N = 100000 + 3;
typedef long long ll;
int n, a[MAX_N], MOD;

namespace segment_tree {
	const int MAX_NODE = (1 << 17) * 2; // 1 << 17 > MAX_N
	struct node {
		ll sum, mulV, addV;
	} nodes[MAX_NODE];
	#define ls (((o) << 1) + 1)
	#define rs (((o) << 1) + 2)
	#define mid (((l) + (r)) >> 1)

	inline void pushUp(int o) {
		nodes[o].sum = (nodes[ls].sum + nodes[rs].sum) % MOD;
	}

	void build(int o, int l, int r) {
		nodes[o].mulV = 1, nodes[o].addV = 0;

		if (r - l == 1) nodes[o].sum = a[l];
		else {
			build(ls, l, mid), build(rs, mid, r);
			pushUp(o);
		}
	}

	inline void giveTagMul(int o, int v) {
		(nodes[o].sum *= v) %= MOD;
		(nodes[o].mulV *= v) %= MOD;
		(nodes[o].addV *= v) %= MOD;
	}

	inline void giveTagAdd(int o, int v, int l, int r) {
		(nodes[o].sum += (ll)(r - l) * v % MOD) %= MOD;
		(nodes[o].addV += v) %= MOD;
	}

	inline void pushDown(int o, int l, int r) {
		if (nodes[o].mulV != 1) {
			giveTagMul(ls, nodes[o].mulV), giveTagMul(rs, nodes[o].mulV);
			nodes[o].mulV = 1;
		}

		if (nodes[o].addV != 0) {
			giveTagAdd(ls, nodes[o].addV, l, mid), giveTagAdd(rs, nodes[o].addV, mid, r);
			nodes[o].addV = 0;
		}
	}

	inline int query(int o, int l, int r, int a, int b) {
		if (r <= a || l >= b) return 0;
		if (l >= a && r <= b) return nodes[o].sum;
		else {
			pushDown(o, l, r);
			return (query(ls, l, mid, a, b) + query(rs, mid, r, a, b)) % MOD;
		}
	}

	inline void modify(int o, int l, int r, int a, int b, bool type, int v) {
		if (r <= a || l >= b) return;
		if (l >= a && r <= b) {
			if (type == 0) giveTagMul(o, v);
			else giveTagAdd(o, v, l, r);
		} else {
			pushDown(o, l, r);
			modify(ls, l, mid, a, b, type, v);
			modify(rs, mid, r, a, b, type, v);
			pushUp(o);	
		}
	}
}

using namespace segment_tree;


int main() {
#ifdef DEBUG
	freopen("test.in", "r", stdin);
#endif
	n = readInt(), MOD = readInt();
	for (int i = 0; i < n; ++i) a[i] = readInt();

	build(0, 0, n);	
	int q = readInt();

	while (q--) {
		int oper = readInt(), l = readInt() - 1, r = readInt();
		if (oper == 1) {
			modify(0, 0, n, l, r, 0, readInt());
		} else if (oper == 2) {
			modify(0, 0, n, l, r, 1, readInt());
		} else if (oper == 3) {
			printf("%d\n", query(0, 0, n, l, r));
		} else assert(false);
	}
	return 0;
}
