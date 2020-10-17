#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n,w[11],f[101];
int main()
{
	memset(f,550,sizeof(f));
	f[0]=0;
	for(int i=1;i<=10;i++)
		scanf("%d",&w[i]);
	cin>>n;
	for(int i=1;i<=10;i++)
		for(int j=i;j<=n;j++)
			if(f[j-i]+w[i]<f[j])
				f[j]=f[j-i]+w[i];
	cout<<f[n]<<endl;
	return 0;
}
