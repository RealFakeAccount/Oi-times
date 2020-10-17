#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 100;
const int MAXM = 2e5 + 100;
const int INF = 0x7f7f7f7f;
int N,M;

struct interval
{
	int first, second, length;
	interval(int f=0, int s=0,int l=0) : first(f), second(s), length(l) {}
};
typedef interval P;

vector<P> iv;//interval;
vector<int> in;//compress
bool cmp(const P &x, const P &y)
{
	return x.length < y.length;
}

namespace segt
{
	#define mid (((l) + (r)) >>1 ) 

	struct node *null;
	struct node 
	{
		int mx,addv;
		node *ls, *rs;
		node() : mx(0), addv(0), ls(null), rs(null) {}
	}pool[MAXN<<3],*pit = pool;

	inline node *newnode()
	{
		static int cnt = 0;
		if(cnt < (MAXN << 3))
			return new (pit++) node();
		else return new node();
	}

	void init()
	{
		null = newnode();
		null->ls = null->rs = null;
		null->mx = null->addv = 0;
	}

	inline void givetagadd(node *o, int v)
	{
		o->addv += v,o->mx += v;
	}

	inline void pushdown(node *o)
	{
		if(o->ls == null) o->ls = newnode();
		if(o->rs == null) o->rs = newnode();

		if(o->addv != 0) 
			givetagadd(o->ls, o->addv),
			givetagadd(o->rs, o->addv),
			o->addv = 0;
	}

	inline void pushup(node *o)
	{
		o->mx = max(o->ls->mx, o->rs->mx);
	}

	inline node *insert(node *o, int l, int r, int a, int b, int v)
	{
		if(o == null) o = newnode();
		if(l > b || r < a) return o;
		if(a <= l && r <= b) 
		{
			o->addv += v, o->mx += v;
			return o;
		}

		pushdown(o);
		o->ls = insert(o->ls, l, mid, a, b, v);
		o->rs = insert(o->rs, mid+1, r, a, b, v);
		pushup(o);
		return o;
	}

	inline int query(node *o, int l, int r, int a, int b)
	{
		if(l > b || r < a) return 0;
		if(a <= l && r <= b) return o->mx;

		pushdown(o);
		return max(query(o->ls, l, mid, a, b),
				   query(o->rs, mid+1, r, a, b));
	}

}

int E = 0;
void compress()
{
	sort(in.begin(), in.end());
	in.erase(unique(in.begin(), in.end()), in.end());
	for(int i = 0; i < (int) iv.size(); i++)
	{
		iv[i].first = lower_bound(in.begin(), in.end(), iv[i].first) - in.begin() + 1;
		iv[i].second = lower_bound(in.begin(), in.end(), iv[i].second) - in.begin() + 1;
		E = max(E, max(iv[i].first, iv[i].second));
	}

}


int work()
{
	compress();
	sort(iv.begin(), iv.end(),cmp);
//		cout<<iv[0].first<<" "<<iv[0].second<<endl;
	segt::init();
	int h = 0, t = 0;//head,tail
	int ans = INF;
	bool haveans = false;
	segt::node *root = segt::newnode();

//	segt::insert(root, 1, E, iv[0].first, iv[0].second, 1);
	while(true)
	{
		while(( h < ( (int)iv.size() ) ) && (root->mx < M))
		{
			segt::insert(root, 1, E, iv[h].first, iv[h].second, 1);h++;
		}	
		if(root->mx < M) break;
		haveans = true;
		
		ans = min(ans, iv[h - 1].length - iv[t].length);
		
		segt::insert(root, 1, E, iv[t].first, iv[t].second, -1);t++;
		
	}

	if(haveans) return ans;
	else return -1;
}

int main()
{
	//freopen("p1712.txt","r",stdin);
	cin>>N>>M;

	int l, r;
	for(int i = 1; i <= N; i++)
	{
		scanf("%d%d",&l, &r);
		iv.push_back(P(l,r,r - l));
		in.push_back(l);
		in.push_back(r);
	}

	cout<<work()<<endl;
	return 0;
}
