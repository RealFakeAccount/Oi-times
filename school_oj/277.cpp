#include <bits/stdc++.h>
using namespace std;
const int MAXN=100+5;
int in[MAXN],a[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>in[i];
		sum+=in[i];
	}
	sum/=n;
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+in[i]-sum;
	sort(a+1,a+n+1);
	int ans=0,mid=a[(n+1)/2];
	for(int i=1;i<=n;i++)
		ans+=abs(a[i]-mid);
	cout<<ans<<endl;
	return 0;
}
