#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int a[1100],b[1100],n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		b[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			if(a[i]>a[j])
				if(b[j]+1>b[i])
					b[i]=b[j]+1;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(b[i],ans);
	printf("%d\n",ans);
	return 0;
}
