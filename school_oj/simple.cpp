#include <bits/stdc++.h>
using namespace std;
const int MAXN=100000+10;
long long f[MAXN*2];


int main()
{
	freopen("simple.in","r",stdin);
	freopen("simple.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n*2;i++)
		cin>>f[i];
	sort(f+1,f+n*2+1);
	int ans=0;
	for(int i=1;i<=n*2;i=i+2)
		ans+=f[i];
	cout<<ans;
	return 0;
}
