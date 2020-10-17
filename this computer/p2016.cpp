#include <bits/stdc++.h>
using namespace std;
const int MAXN=2000+5;

int f[MAXN][MAXN];
int head[MAXN],mnext[MAXN],w[MAXN];

int dfs(int x)
{
    if (head[x]==-1) 
		return 0;
		
    int sum=0;
    for (int i=head[x];i!=-1;i=mnext[i])
	{
        int t=dfs(i);
        sum+=t+1;
        for (int j=sum;j>=0;j--)
		{
            for (int k=0;k<=t;k++)
                if (j-k-1>=0) 
					f[x][j]=max(f[x][j],f[x][j-k-1]+f[i][k]);
        }
    }
    return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	cin>>n>>m;

	memset(f,0,sizeof(f));
	memset(head,-1,sizeof(head));

	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a>>w[i];
		mnext[i]=head[a];
	//	cout<<"mnext["<<i<<"]="<<mnext[i]<<endl;
		head[a]=i;
	//	cout<<"head["<<a<<"]="<<i<<endl;
	}
	
	for(int i=1;i<=n;i++)
		f[i][0]=w[i];
	
	f[0][0]=0;
	dfs(0); 
	cout<<f[0][m]<<endl;
	return 0;
}
