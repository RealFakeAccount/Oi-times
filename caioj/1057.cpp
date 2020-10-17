#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int t[110],m[110],f[1100];
int rt,n,i,j;
int main()
{
	scanf("%d%d",&rt,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&m[i]);
	}
	memset(f,-1,sizeof(f));
	f[0]=0;
	
	for(i=1;i<=n;i++)
		for(j=rt;j>=t[i];j--)
			f[j]=max(f[j],f[j-t[i]]+m[i]);
	
	printf("%d\n",f[rt]);
	return 0;
}
