#include <bits/stdc++.h>
using namespace std;
const int MAXN=80000+10;
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<ctime>
#define MAX 999999999
#define MOD 1000000
using namespace std;
int n,m=0,answer=0,pod=0;
struct node{
    node* son[2];
    int v,w,s,flag;
    node(){
        son[0]=son[1]=NULL;
        w=rand();
        v=0;
        s=flag=1;
    }
};
node* rt;
inline int read(){
    int date=0,w=1;char c=0;
    while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
    while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
    return date*w;
}
void maintain(node* &u){
    u->s=u->flag;
    if(u->son[0]!=NULL)u->s+=u->son[0]->s;
    if(u->son[1]!=NULL)u->s+=u->son[1]->s;
}
void turn(node* &u,int f){
    node* t=u->son[f^1];
    u->son[f^1]=t->son[f];
    t->son[f]=u;
    maintain(u);
    maintain(t);
    u=t;
}
void insert(node* &u,int x){
    if(u==NULL){
        u=new node;
        u->v=x;
        return;
    }
    else if(u->v==x){
        u->flag++;
        maintain(u);
        return;
    }
    int y=x>u->v?1:0;
    insert(u->son[y],x);
    if(u->son[y]->w>u->w)turn(u,y^1);
    else maintain(u);
}
void remove(node* &u,int x){
    if(u==NULL)return;
    if(u->v==x){
        if(u->flag>1)u->flag--;
        else{
            if(u->son[0]==NULL&&u->son[1]==NULL)u=NULL;
            else if(u->son[0]!=NULL&&u->son[1]!=NULL){
                if(u->son[0]->w>u->son[1]->w){
                    turn(u,1);
                    remove(u->son[1],x);
                }
                else{
                    turn(u,0);
                    remove(u->son[0],x);
                }
            }
            else{
                if(u->son[0]==NULL)u=u->son[1];
                else u=u->son[0];
            }
        }
        if(u!=NULL)maintain(u);
    }
    else{
        if(x<u->v)remove(u->son[0],x);
        else if(x>u->v)remove(u->son[1],x);
        if(u!=NULL)maintain(u);
    }
}
void front(node* u,int k,int &ans){
    if(u==NULL)return;
    if(u->v<k){
        if(u->v>ans)ans=u->v;
        if(u->son[1]!=NULL)front(u->son[1],k,ans);
    }
    else if(u->v==k){
        if(u->flag>=1)ans=u->v;
        else if(u->son[0]!=NULL)front(u->son[0],k,ans);
    }
    else if(u->v>k)
    if(u->son[0]!=NULL)front(u->son[0],k,ans);
}
void next(node* u,int k,int &ans){
    if(u==NULL)return;
    if(u->v>k){
        if(u->v<ans)ans=u->v;
        if(u->son[0]!=NULL)next(u->son[0],k,ans);
    }
    else if(u->v==k){
        if(u->flag>=1)ans=u->v;
        else if(u->son[1]!=NULL)front(u->son[1],k,ans);
    }
    else if(u->v<k)
    if(u->son[1]!=NULL)next(u->son[1],k,ans);
}

int main()
{
	freopen("p2286.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int a,b,ans=0;
	while(n--)
	{
		cin>>a>>b;
		cout<<a<<" "<<b<<endl;
		if(!a)
		{
			node *p;
			p=newnode(b);
			insert(root,p);
			treap(p);
		}
		if(a)
		{
			node *p=find(root,b);
			if(p)
				del(p);
			else
			{
				node *p=kth(root,getrank(root,b)-1);
				ans+=abs(b - p->d)%1000000;
				del(p);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
