#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXM = 1e5 + 20;
const int ODD = 1;
const int EVEN = 0;

struct query
{
	int l, r, type;
	query(int l = 0, int r = 0, int t = 0) :
	l(l), r(r), type(t) {}
}Q[MAXM];

int N, M;

vector<int> vec;
void discrete()
{
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int i = 1; i <= M; i++)
		Q[i].l = upper_bound(vec.begin(), vec.end(), Q[i].l - 1) - vec.begin(),
		Q[i].r = upper_bound(vec.begin(), vec.end(), Q[i].r) - vec.begin();

}
int fa[MAXM << 1], d[MAXM << 1];
namespace ufs
{
	void init()
	{
		memset(d, 0, sizeof(d));
		for(int i = 1; i <= N; i++) fa[i] = i;
	}
	int findfa(int x)
	{
		if(x == fa[x]) return x;
		int root = findfa(fa[x]); d[x] ^= d[fa[x]];
		return fa[x] = root;
	}
}

int main()
{
	cin>>N>>M;
	char ch[10];
	for(int i = 1; i <= M; i++)
	{	
		scanf("%d%d%s", &Q[i].l, &Q[i].r, ch);
		vec.push_back(Q[i].l - 1);
		vec.push_back(Q[i].r);
		Q[i].type = (ch[0] == 'o' ? 1 : 0);
	}
	discrete(); ufs::init();
	for(int i = 1; i <= M; i++)
	{
		int p = ufs::findfa(Q[i].l), 
		    q = ufs::findfa(Q[i].r);
		if(p == q){
			if((d[Q[i].l] ^ d[Q[i].l]) != Q[i].type)
				{cout<<i - 1<<endl; return 0;}
		}
		else{
			fa[p] = q, d[p] = d[Q[i].l] ^ d[Q[i].r] ^ Q[i].type;
		}
	}
	cout<<M<<endl;
	return 0;
}
