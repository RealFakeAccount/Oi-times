#include <bits/stdc++.h>
using namespace std;
const int MAXN=120+10;
int n,ans;
int land[MAXN][MAXN];
int mhei[MAXN][MAXN];

void init()
{
	for(int i=0;i<=n;i++)
	{
		mhei[0][i]=0;
		mhei[i][0]=0;
	}
}
void preop()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			mhei[i][j]=land[i][j]+mhei[i][j-1];
		}
	return;
}

void solve()
{
	int area;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{	
			area=0;
			for(int k=1;k<=n;k++)
			{
				area+=mhei[k][j]-mhei[k][i-1];
				if(area>ans)	ans=area;
				if(area<0)	area=0;
			}
		}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>land[i][j];
	init();
	preop();
	solve();
	cout<<ans;
	return 0;
}
