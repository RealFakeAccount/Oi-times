#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN=1000+10;

int f[MAXN],a[MAXN],n;

int main()
{
//	freopen("269.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	fill(f,f+n+1,INT_MAX);
	for(int i=1;i<=n;i++)
	{
		int p=lower_bound(f+1,f+n+1,a[i])-f;
		if(f[p]>a[i])
			f[p]=a[i];
	//	cout<<p<<" ";
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(f[i]!=INT_MAX)
			cnt++;
			
	cout<<cnt;
	return 0;
}
