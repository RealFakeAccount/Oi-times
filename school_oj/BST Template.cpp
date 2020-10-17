#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	node *ch[2]; // 0 left, 1 right
	int r;
	int v;
	int s;
	int cmp (int x) const
	{
		if(x == v) return -1;
		return x < v ? 0 : 1;
	}
	void maintain ()
	{
		s = 1;
		if(ch[0] != NULL) s += ch[0]->s;
		if(ch[1] != NULL) s += ch[1]->s;
	}
};
node* root;
void rotate (node* &o, int d)   // 0 left, 1 right
{
	node *k = o->ch[d^1];
	o->ch[d^1] = k->ch[d];
	k->ch[d] = o;
	o->maintain();
	k->maintain();
	o = k;
}

void insert (node* &o, int x)
{
	if(o == NULL)
	{
		o = new node();
		o->ch[0] = o->ch[1] = NULL;
		o->v = x;
		o->r = rand();
	}
	else
	{
		int d = o->cmp(x);
		insert(o->ch[d], x);
		if(o->ch[d]->r > o->r) rotate(o, d^1);
	}
}

void remove (node* &o, int x)
{
	int d = o->cmp(x);
	if(d == -1)
	{
		if(o->ch[0] == NULL) o = o->ch[1];
		else if(o->ch[1] == NULL) o = o->ch[0];
		else
		{
			int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
			rotate(o, d2);
			remove(o->ch[d2], x);
		}
	}
	else
	{
		remove (o->ch[d], x);
	}
}

bool find (node* &o, int x)
{
	while(o != NULL)
	{
		int d = o->cmp(x);
		if(d == -1) return true;
		else o = o->ch[d];
	}
	return false;
}

void splay(node* &o, int k)
{
	int d = o->cmp(k); // left 0, right 1, equal -1
	if(d == 1) k -= o->ch[0]->s + 1;
	if(d != -1)
	{
		node* p = o->ch[d];
		int d2 = p->cmp(k);
		int k2 = (d2 == 0 ? k : k - p->ch[0]->s - 1);
		if(d2 != -1)
		{
			splay(p->ch[d2], k2);
			if(d == d2) rotate(o, d^1);
			else rotate(o->ch[d], d);
		}
		rotate(o, d^1);
	}
}

node *merge (node *left, node *right)
{
	splay(left, left->s);
	left->ch[1] = right;
	left->maintain();
	return left;
}

void split (node *o, int k, node* &left, node* &right)
{
	splay(o, k);
	left = o;
	right = o->ch[1];
	o->ch[1] = NULL;
	left->maintain();
}

int main ()
{
	ios::sync_with_stdio(false);
	int n,x,y;
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		if(x==1)
			insert(root,y);
		if(x==2)
			remove(root,y);
		if(x==3)
			
			
	}
	return 0;
}

