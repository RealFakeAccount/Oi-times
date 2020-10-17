#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100000;

int a[MAXN],N,S;

void solve()
{
	int ans=100000001,sum=0,l=0,r=1,cnt=0;
	while(r<=N)
	{
		while(sum<S && r<=N)
		{
			sum+=a[r];
			++r;
			++cnt;
		}
		while(sum-a[l]>=S)
		{
			sum-=a[l];
			++l;
			--cnt;
		}
		ans=min(ans,cnt);
		++r;
	}
	if(ans!=-1)
		cout<<ans+1<<endl;
	else cout<<0<<endl;
	return;

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
		for(int i=1; i<=N; i++)
			cin>>a[i];
		solve();
	}
	return 0;
}
