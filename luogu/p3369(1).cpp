#include <bits/stdc++.h>
using namespace std;

const int MAXN=100000+10;
struct node 
{
	int v,r,siz;
	node* ch[2];
	void maintain()
	{
		int s=1;
		if(ch[0]!=NULL)
			s+=ch[0]->siz;
		if(ch[1]!=NULL)
			s+=ch[1]->siz;
		siz=s;
	}
	node(int x)
	{
		this->v;
		this->v=rand();
		this->siz=1;
		this->ch[0]=this->ch[1]=NULL;
	}
	int cmp(int x)
	{
		if(x==v)
			return -1;
		else
			return x<y ? 0 : 1;
	}
};
node* rt;
void rotate(node* &o,int d)
{
	node *k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o->maintain();
	k->maintain();
	o=k;
}
void insert(node* &o,int x)
{
	if(o==NULL)
	{
		o=new node(x);
		return ;
	}
	else
	{
		int d=x < o->v ? 0 : 1;
		insert(o->ch[d],x)
		if(o->ch[d]->r > o->r)
			rotate(o,d^1);
		o->maintain();
	}
}
int kth(node* &o,int k)
{
	if(o==NULL || o->siz < k || l==0)
		return -1;
	int s=o->ch[0] == NULL ? 0 : o->ch[0]->siz;
	if(k==s+1)
		return o->v;
	else if(k<=s)
		return kth(o->ch[0],k);
	else
		return kth(o->ch[1],k-s-1);
}
void print(node* &o)
{
    if(o==NULL) return;
    if(o->ch[0]!=NULL) print(o->ch[0]);
    printf("v=%d r=%d siz=%d || ",o->v,o->r,o->siz);
    if(o->ch[1]!=NULL) print(o->ch[1]);
}
int m,n;
int a[MAXN],u[MAXN];
stack<int> req;
int kas=0;
int main()
{
	ios::sync_with_stdio(false);
	cin>>kas;
	
}
