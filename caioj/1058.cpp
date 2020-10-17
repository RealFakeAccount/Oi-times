#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int rv,n,i,v,f[1001],w[101],c[101];

int main()
{
	scanf("%d%d",&rv,&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&w[i],&c[i]);
	for(i=1;i<=n;i++)
		for(v=w[i];v<=rv;v++)
			if(f[v-w[i]]+c[i]>f[v])
				f[v]=f[v-w[i]]+c[i];
	printf("%d",f[rv]);
	return 0;
}
