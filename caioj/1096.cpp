#include <bits/stdc++.h>
using namespace std;
const int  MAXN=50000+10;

int par[MAXN],r[MAXN];
vector<int> eat[MAXN];

void init(int n)
{
	for(int i=1;i<=n;i++)
		par[i]=i;
	memset(r,1,sizeof(r));
}

int findpa(int n)
{
	return par[n]==findpa(par[n]);
}

void unite(int x,int y)
{
	x=findpa(x);
	y=findpa(y);
	if(x==y)
		continue;
	if(r[x]>r[y])
		par[y]=par[x];
	else
	{
		par[x]=par[y];
		if(r[x]==r[y])
			r[x]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int N,K;
	cin>>N>>K;
	init(N);
	int k,x,y,ans=0;
	for(int i=1;i<=K;i++)
	{
		cin>>k>>x>>y;
		if(x>n || y>n || y==x)
		{
			ans++;
			continue;
		}
		if(k==1)
		{
			for(int i=0;i<(int) eat[x].size();i++)
				if(eat[x][i]==y)
				{
					ans++;
					continue;
				}
			unite(x,y);
		}
		if(k==2)
		{
			
		}
	}
	return 0;
}
