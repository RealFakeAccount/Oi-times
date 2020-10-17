#include <bits/stdc++.h>
using namespace std;
const int MAXN=20000+5;
int par[MAXN*2],rankt[MAXN*2];

struct angry
{
	int x,y,a;
	angry(int n=0,int m=0,int v=0) : x(n),y(m),a(v) {
	}
}in[100010];

bool cmp(angry x,angry y)
{
	return x.a>y.a;
}
void init(int n)
{
	for(int i=1;i<=n;i++)
		par[i]=i;
	memset(rankt,1,sizeof(rankt));
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
	int n,m,a,b,c;
	cin>>n>>m;
	init(n*2);
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		in[i]=angry(a,b,c);
	}
	sort(in+1,in+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		a=in[i].x;b=in[i].y;c=in[i].a;
		int fa=find(a),fb=find(b);
		if(fa==fb)
		{
			cout<<c<<endl;
			return 0;
		}
		if(fa==find(b+n) || fb==find(a+n))
			continue;
		unite(a,b+n);
		unite(b,a+n);
		
	}
	cout<<0<<endl;
	return 0;
}
