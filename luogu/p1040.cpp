#include <bits/stdc++.h> 
using namespace std;
const int MAXN=30+5;
int root[MAXN][MAXN],f[MAXN][MAXN],d[MAXN];

void dfs(int l,int r)
{
	if(l<=r)
	{
		cout<<" "<<root[l][r];
		dfs(l,root[l][r]-1);
		dfs(root[l][r]+1,r);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	
	for(int i=0;i<=MAXN;i++)
		for(int j=0;j<=MAXN;j++)
			f[i][j]=1;
	
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		root[i][i]=i;
		f[i][i]=d[i];
	}
	for(int k=2;k<=n;k++)
		for(int L=1;L<=n-k+1;L++)
		{
			int R=k+L-1;
			for(int mid=L;mid<=R;mid++)
			{
				if(f[L][R] < f[L][mid-1]*f[mid+1][R]+d[mid])
				{
					f[L][R]=f[L][mid-1]*f[mid+1][R]+d[mid];
					root[L][R]=mid;
				}
			}
		}
	cout<<f[1][n]<<endl;
	cout<<root[1][n];
	dfs(1,root[1][n]-1);
	dfs(root[1][n]+1,n);
	
	return 0;
}
