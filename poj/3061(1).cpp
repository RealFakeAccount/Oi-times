#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100000;

int a[MAXN],N,S;

void solve()
{
	int res=N+1;
	int s=0,t=0,sum=0;
	for(;;)
	{
		while(t<N && sum<S)
		{
			sum+=a[t++];
		}
		if(sum<S)
			break;
		res=min(res,t-s);
		sum-=a[s++];
	}
	if(res>N)
		cout<<0<<endl;
	else
		cout<<res<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	int cnt;
	cin>>cnt;
	while(cnt--)
	{
		cin>>N>>S;
		memset(a,0,sizeof(a));
		for(int i=0; i<N; i++)
			cin>>a[i];
		solve();
	}
	return 0;
}
