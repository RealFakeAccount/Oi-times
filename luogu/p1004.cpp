#include <bits/stdc++.h>
using namespace std;
const int MAXN=10;

int f[MAXN][MAXN][MAXN][MAXN],a[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	int m,o;
	cin>>m;
	while(m!=0)
	{
		cin>>o;
		cin>>a[m][o];
		cin>>m;
	}	
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int x=1;x<=n;x++)
				for(int y=1;y<=n;y++)
				{
					f[i][j][x][y]=max(f[i-1][j][x-1][y],max(f[i][j-1][x-1][y],
								max(f[i-1][j][x][y-1],f[i][j-1][x][y-1])))+a[i][j];
					if(i!=x && j!=y)	f[i][j][x][y]+=a[x][y];
				}
	cout<<f[n][n][n][n];
	return 0;
}

