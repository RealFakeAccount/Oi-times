#include <cstring>
#include <iostream>
using namespace std;
const int maxn=100000+10;

int fa[maxn];

int find_gr(int x)
{
	int  gr;
	if(fa[x]!=x)
		gr=find_gr;
	else
		gr=x;
	fa[x]=gr;
	return gr;
}

int main()
{
	int n,m,x,y;
	cin>>n>>m
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		int fx=find_gr(x);
		int fy=find_gr(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(fa[i]==i)
			ans++;
	cout<<ans;
}