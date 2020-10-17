#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
int a[110],f[110][65];
int main()
{
	int n,k;
	cin>>n>>k;
	k+=3;
	if (k*2>n)  
    {  
        printf("-1");  
        return 0;  
    }  
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	memset(f,63,sizeof(f));
	for(int i=0;i<=n;i++)
		f[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
		{
			f[i][j]=f[i-1][j];
			for(int ii=1;ii<i;ii++)
				f[i][j]=min( f[i][j] , f[ii-1][j-1] + (a[ii]-a[i])*(a[ii]-a[i]) );
		}
	printf("%d",f[n][k]);
	return 0;
}

