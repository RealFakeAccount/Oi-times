#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

struct edge{
    int to, cost;
};

int N, M;
vector<edge> g[MAXN];

struct stree{
    #define mid ((l + r) >> 1)
    #define ls (o << 1)
    #define rs ((o << 1) | 1)

    int node[MAXN << 2];

    inline void pushup(){
        node[o] = max(node[ls], node[rs]);
    }
}

int main()
{

	return 0;
}
