#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000+5;
//--------Treap
struct node
{
	int d,rank,size;
	node *ch[2],*pa;
};
node *root,pool[MAXN];
int tot=0;
node *newnode(int d)
{
	node *p=&pool[++tot];
	p->d=d;
	p->rank=rand();
	p->size=1;
	p->ch[0]=p->ch[1]=NULL;
	return p;
}

inline int size(node *p)
{
	return p ? p->size : 0;
}

void update(node *p)
{
	p->size=size(p->ch[0])+size(p->ch[1])+1;
}

void rotate(node *p,int t)
{
	node *pa=p->pa,*gp=pa->pa,*son=p->ch[t^1];
	pa->ch[t]=son;
	if(son)
		son->pa=pa;
	if(gp)
		gp->ch[pa==gp->ch[1]]=p;

	p->pa=gp;
	p->ch[t^1]=pa;
	pa->pa=p;
	if(pa==root)
		root=p;

	update(pa);
	update(p);
}

void treap(node *p)
{
	while(true)
	{
		if(p==root || p->rank >= p->pa->rank)
			break;
		rotate(p,p==p->pa->ch[1]);
	}
}

void insert(node *r,node *p)
{
	if(!r)
	{
		root=p;
		return;
	}
	int f=(p->d >= r->d);
	if(!r->ch[f])
	{
		r->ch[f]=p;
		p->pa=r;
	}
	else
		insert(r->ch[f],p);
	update(r);
}

node* find(node *r,int x)
{
    if(r->d==x)
		return r;
    if(x<r->d)
		return find(r->ch[0],x);
    else 
		return find(r->ch[1],x);
}

void del(node *p)
{
	if(!p->ch[0] && !p->ch[1])
	{
		if(p==root)
		{
			root=NULL;
			return;
		}
		node *pa=p->pa;
		if(pa)
			pa->ch[p==pa->ch[1]]=NULL;
		while(p!=root)
			update(p=p->pa);
		return;
	}
	if(p->ch[0] && p->ch[1])
	{
		int f=(p->ch[1]->rank < p->ch[0]->rank);
		rotate(p->ch[f],f);
	}
	else
	{
		int f=1;
		if(p->ch[0])
			f=0;
		rotate(p->ch[f],f);
	}
	del(p);
}

int kth(node *r,int x)
{
	if(x<=size(r->ch[0]))
		return kth(r->ch[0],x);
	if(x==size(r->ch[0])+1)
		return r->d;
	return kth(r->ch[1],x-size(r->ch[0])-1);
}

int getrank(node *r,int d)
{
    if(!r)
		return 1;
    if(d <= r->d)
		return getrank(r->ch[0],d);
    return getrank(r->ch[1],d)+size(r->ch[0])+1;
}
//------end
int main()
{
	srand((int)time(NULL));
	ios::sync_with_stdio(false);
	int n,opt,x;
	cin>>n;
	while(n--)
	{
		cin>>opt>>x;
		if(opt==1)//insert
		{
			node *p=newnode(x);
			insert(root,p);
			treap(p);
		}
		if(opt==2)//delect
		{
			node *p=find(root,x);
			del(p);
		}
		if(opt==3)//find rank
			cout<<getrank(root,x)<<endl;
		if(opt==4)//find the number that rank x
			cout<<kth(root,x)<<endl;
		if(opt==5)//first number < x
			cout<<kth(root,getrank(root,x)-1)<<endl;
		if(opt==6)//first number > x
			cout<<kth(root,getrank(root,x+1))<<endl;
	}
	return 0;
}
