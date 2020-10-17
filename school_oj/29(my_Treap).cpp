#include <bits/stdc++.h>
using namespace std;

struct node
{
	node *ch[2];
	int r;
	int v;
	int cmp(int x) const 
	{
		if(x==v)
			return -1;
		return x<y ? 0 : 1;
	}
};
//---------treap
void rotate(node* &o,int d)//d:0 -> left rotate ; 1 -> right rotate
{
	node* k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o=k;
}

void insert(node* &o,int x)
{
	if(o==NULL)
	{
		o=new node();
		o->ch[0]=o->ch[1]=NULL;
		o->v=x;
		o->r=rand();
	}
	
	else
	{
		int d=o->cmp(x);
		insert(o->ch[d],x);
		if(o->ch[d] ->r > o->r)
			rotate(o,d^1);
	}
}

void remove(node* &o,int x)
{
	int d=o->cmp(x);
	if(d==-1)
	{
		if(o->ch[0]==NULL)
			o=o->ch[1];
		else if(o->ch[1]==NULL)
			o=o->ch[0];
		else
		{
			int d2=(o->ch[0] ->r > o->ch[1] ->r ? 1 : 0);
			rotate(o,d2);
			remove(o->ch[d2],x);
		}
	}
	else
		remove(o->ch[d],x);
}

int find(node* o,int x)
{
	while(o!=NULL)
	{
		int d=o->cmp(x);
		if(d==-1)
			return 1;
		else
			o=o->ch[d];
	}
	return 0;
}
