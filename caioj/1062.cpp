#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

char st[110];
char cc[110][110];

bool tf(int x,int j)
{
	for(int i=1;i<=strlen(cc[j]+1);i++)
		if(cc[j][i]!=st[x+i])
			return false;
	return true;
}
int f[110];
int main()
{
	scanf("%s",st+1);
	int len,n;
	len=strlen(st+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",cc[i]+1);
	for(int i=1;i<=len;i++)
		f[i]=9999999;
	f[0]=0;
	bool bk=false;
	for(int i=0;i<len;i++)
	{
		if(f[i]!=9999999)
			for(int j=1;j<=n;j++)
			{
				int clen=strlen(cc[j]+1);
				if(i+clen<=len)
					if(tf(i,j))
						f[i+clen]=min(f[i]+1,f[i+clen]);
			}
	}
	printf("%d\n",f[len]);
	return 0;
}
