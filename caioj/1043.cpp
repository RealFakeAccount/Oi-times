#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <time.h>  
using namespace std;
int a[11000],len;
int ans,n;
void yinshu(int x)
{
	int y=int(sqrt ( double(x+1) ) );
	for(int i=2;i<=y;i++)
	{
		if(x%i==0)
		{
			a[++len]=i;
			if(x/i !=i) a[++len]=x/i;
		}
	}
}
void dfs(int d)
{
	ans++;
	for(int i=1;i<=len;i++)
	{
		if(d*a[i]>n)break;
		if(n%(d*a[i])==0&&n!=d*a[i])
		{
			dfs(d*a[i]);
		}
	}
}
int main()
{
	clock_t  clockBegin, clockEnd; 
	while(1)
	{
	scanf("%d",&n);
	clockBegin = clock();
	len=0;yinshu(n);
	sort(a+1,a+len+1);
	ans=0;dfs(1);
	clockEnd = clock();
	printf("%d\n",ans);
	cout<<clockEnd - clockBegin<<endl;
	}
	return 0;
}
