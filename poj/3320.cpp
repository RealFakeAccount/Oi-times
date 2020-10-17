#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
const int MAXP=1000000+10;
int P;
int a[MAXP];

void solve()
{
	set<int> all;
	for(int i=0;i<P;i++)
		all.insert(a[i]);
	int n=all.size();
	
	int s=0,t=0,num=0;
	map<int,int> cnt;
	int res=P;
	for(;;)
	{
		while(t<P && num<n)
		{
			if(cnt[a[t++]] ++ == 0)
				num++;
		}
		if(num<n)
			break;
		res=min(res,t-s);
		if(--cnt[a[s++]]==0)
			num--;
	}
	cout<<res<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>P;
	for(int i=0;i<P;i++)
		cin>>a[i];
	solve();
	return 0;
}
