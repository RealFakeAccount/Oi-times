#include <bits/stdc++.h>
using namespace std;
inline int readInt()
{
	static int n, ch;
	n = 0, ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
	return n;
}

const int MAX_N = 100000 + 3;
typedef long long int;
int n, a[MAX_N], MOD;

namespace segment_tree
{
	const int MAX_NODE = (1 << 17) * 2; // 1 << 17 > MAX_N
	struct node
	{
		int sum, mulV, addV;//mul refer to multiply(*)
	} nodes[MAX_NODE];
#define ls (((o) << 1) + 1)//O*2+1 left son
#define rs (((o) << 1) + 2)//o*2+2 right son
#define mid (((l) + (r)) >> 1)//l+r/2 mid

	inline void pushUp(int o)//use inline to avoid wasting space. To learn more,Baidu it.
	{
		nodes[o].sum = (nodes[ls].sum + nodes[rs].sum) % MOD;//Up the tag !!!
	}

	void build(int o, int l, int r)
	{
		nodes[o].mulV = 1, nodes[o].addV = 0;

		if (r - l == 1) nodes[o].sum = a[l];
		else
		{
			build(ls, l, mid), build(rs, mid, r);
			pushUp(o);
		}
	}

	inline void giveTagMul(int o, int v)//update the multiply tag
	{
		(nodes[o].sum *= v) %= MOD;//example:suppose the value is a;
		(nodes[o].mulV *= v) %= MOD;//and a is tagged as a+b+c
		(nodes[o].addV *= v) %= MOD;//so when i want to multiply v,the final value
									//is (a+b+c)*v = a*v+b*v+c*v
	}

	inline void giveTagAdd(int o, int v, int l, int r)//update the add tag
	{
		(nodes[o].sum += (int)(r - l) * v % MOD) %= MOD;
		(nodes[o].addV += v) %= MOD;
	}

	inline void pushDown(int o, int l, int r)//Down the tag !!!
	{
		if (nodes[o].mulV != 1)//operation about the tag of multiply
		{                      //the default munber is 1,so when it is NOT 1,
							   //the tag must have been changed
			giveTagMul(ls, nodes[o].mulV); giveTagMul(rs, nodes[o].mulV);//down to its left son and right son
			nodes[o].mulV = 1;//initialize it.
		}

		if (nodes[o].addV != 0)//similar to operation about the tag of multiply
		{
			giveTagAdd(ls, nodes[o].addV, l, mid), giveTagAdd(rs, nodes[o].addV, mid, r);
			nodes[o].addV = 0;//initialize it.
		}
	}

	inline int query(int o, int l, int r, int a, int b)
	{
		if (r <= a || l >= b) return 0;
		if (l >= a && r <= b) return nodes[o].sum;
		else
		{
			pushDown(o, l, r);
			return (query(ls, l, mid, a, b) + query(rs, mid, r, a, b)) % MOD;
		}
	}

	inline void modify(int o, int l, int r, int a, int b, bool type, int v)
	 //example:in [a,b],a<=i<=b,ai=ai*c
	{//(num of node,max left,max right,a,b,type zero,c)
	 //maybe..type zero refer to *,type one refer to +
		if (r <= a || l >= b) return; //beyond the  interval
		if (l >= a && r <= b)
		{
			if (type == 0) giveTagMul(o, v);//when *
			else giveTagAdd(o, v, l, r);//when +
		}
		else
		{
			pushDown(o, l, r);
			modify(ls, l, mid, a, b, type, v);
			modify(rs, mid, r, a, b, type, v);
			pushUp(o);
		}
	}
}

using namespace segment_tree;


int main()
{
//#ifdef DEBUG
//	freopen("test.in", "r", stdin);
//#endif
	n = readInt();
	int q = readInt();
	MOD = INT_MAX;
	for (int i = 0; i < n; ++i) a[i] = readInt();

	build(0, 0, n);


	while (q--)
	{
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
