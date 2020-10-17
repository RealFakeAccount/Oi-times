#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

int a[35];
bool f[20001];
int main()
{
	int v,n;
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,0,sizeof(f));
	f[0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=v;j>=a[i];j--)
		{
			if(f[j]==false)
			{
				f[j]=f[j-a[i]];
			}
		}
	}
	int x=v;
	while(f[x]==false)
		x--;
	printf("%d\n",v-x);
	return 0;
}