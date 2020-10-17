#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int n,m,sum[10001];
int a[110],len,tot;
bool f[10001];
int main()
{
	scanf("%d",&n);
	for(int x=1;x<=n;x++)
	{
		len=0;
		while(true)
		{
			scanf("%d",&m);
			if(m==-1)
				break;
			a[++len]=m;
		}
		tot=0;
		memset(f,0,sizeof(f));
		f[0]=1;
		for(int i=1;i<=len;i++)
		{
			for(int j=tot;j>=0;j--)
			{
				if(f[j]==true)
				{
					f[j+a[i]]=true;
					tot=max(tot,j+a[i]);
				}
			}
		}
		for(int i=0;i<=tot;i++)
			if(f[i])
				sum[i]++;
	}
	for(int i=tot;i>=0;i--)
		if(sum[i]==n)
		{
			cout<<i<<endl;
			break;
		}
	return 0;
}
