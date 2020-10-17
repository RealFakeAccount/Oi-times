#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100000+10;

long long m,n;
long long bit[MAXN];
long long sum(long long i)
{
	long long a=0;
	while(i)
	{
		a+=bit[i];
		i-=i&(-i);
	}
	return a;
}

void add(long long i,long long x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&(-i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(bit,0,sizeof(bit));
	char x;long long y,z;
	while(m--)
	{
		cin>>x>>y>>z;
		if(x=='C')
			add(y,z);
		else
			cout<<sum(z)-sum(y-1)<<endl;
	}
	return 0;
}
