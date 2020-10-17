#include <bits/stdc++.h>
using namespace std;
const int MAXN=500000+10;
int bit[MAXN+10],n;

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
int main()
{
	int N,M;
	ios::sync_with_stdio(false);
	cin>>N>>M;
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
		cin>>x>>y>>z;
		if(x==1)
			add(y,z);
		else
			cout<<sum(y)-sum(z-1)<<endl;
	}
	return 0;
}
