#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
long long a[110],s[110][110];
long long f[110][110];
int main()
{
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		s[i][i]=a[i];
		for(int j=i+1;i<=n;j++)
			s[i][j]=s[i][j-1]+a[j];
	}
	memset(f,-1,sizeof(f));
	for(int i=0;i<=n;i++)
		f[i][0]=s[1][i];
	for(int k=1;k<=m;k++)
		for(int i=k+1;i<=n;i++)
			for(int j=i;j>=k+1;j--)
				f[i][k]=max( max(f[i][k],f[j-1][k-1]+s[j][i]) ,f[j-1][k-1]*s[j][i]);
	cout<<f[n][m]<<endl;
	return 0;
}
