/*һ����n�������ͨ����ͼ����m�������ߣ�ÿ������һ���c��
��������ʽ��  
��һ������ n�� m ��1<=n<=1000,n-1<=m<=50 0000��
��� N �У�ÿ�������� x,y,c����ʾ�� x �� �� y ��һ������Ϊ c �������ߡ�0<c<=20
��������ʽ�� 
һ��һ�������������n��������С���Ⱥ͡� */

#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int maxm=50000+10;
int n,m;

struct edge
{
	int from,to,cost;
	edge(int u=0,int v=0, int c=0) : from(u),to(v),cost(c) {}
};

edge es[maxm];
bool comp(const edge& e1,const edge& e2)
{
	return e1.cost<e2.cost;
}


int par[maxn];
void init(int n)
{
	for(int i=1;i<=n;i++)
		par[i]=i;
}

int findgr(int x)
{
	if(par[x]==x)
		return x;
	else
	{
		par[x]=findgr(par[x]);
		return par[x];
	}
}

void unite(int x,int y)
{
	x=findgr(x);
	y=findgr(y);
	par[x]=y;
}

int kruskal()
{
	sort(es+1,es+m+1,comp);
	init(n);
	int res=0,i;
	for( i=1;i<=m;i++);
	{
		edge e=es[i];
		if(! findgr(e.to) == findgr(e.from))
		{
			unite(e.to,e.from);
			res+=e.cost;
		}
	}
	return res;
}
int main()
{
	cin>>n>>m;
	int x,y,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		edge(x,y,c);
	}	
	init(n);
	int ans=kruskal();
	cout<<ans<<endl;
	
	return 0;
}

