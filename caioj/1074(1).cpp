#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[210],s[210],f[210][210];
int main()
{
	int n,ans=999999;
	scanf("%d",&n);
	s[0]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int k=1;k<n;k++)
	{
		int t=a[k];a[k]=a[k+1];a[k+1]=t;
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		int g=a[k+1];a[k+1]=a[k];a[k]=g;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=n-i+1;j++)
			{
				int x=j,y=j+i-1;
				f[x][y]=999999;
				for(int k=x;k<=y;k++)//其实此处k重复了，但巧合的没有影响
					f[x][y]=min(f[x][y],f[x][k]+f[k+1][y]+s[y]-s[x-1]);
			}
			ans=min(ans,f[1][n]);
	}
	printf("%d\n",ans);
	return 0;
}
