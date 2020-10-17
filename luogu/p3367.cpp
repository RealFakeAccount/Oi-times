#include <bits/stdc++.h>
using namespace std;
const int MAXN=10000+10;
int par[MAXN],rankt[MAXN];
void init(int n)
{
	for(int i=1;i<=n;i++)
		par[i]=i;
		memset(rankt,0,sizeof(rankt));
}

int find(int x)
{
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}

void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	if(rankt[x]<rankt[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(rankt[x]==rankt[y])
			rankt[y]++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m,z,x,y;
	cin>>n>>m;
	init(n);
	for(int i=1;i<=m;i++)
	{
		cin>>z>>x>>y;
		if(z==1)
			unite(x,y);
		else
		{
			if(find(x)==find(y))
				cout<<"Y"<<endl;
			else
				cout<<"N"<<endl;
		}
	}
	return 0;
}
