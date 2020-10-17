#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000000+10;

int f[MAXN],h[MAXN];
int n;
int solve(int k)
{
	memset(f,63,sizeof(f));
	f[1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			if(i+j<=n)
			{
				if(h[i+j]>=h[i])
					f[i+j]=min(f[i+j],f[i]+1);
				else//h[i+j]<h[i]
					f[i+j]=min(f[i+j],f[i]);
			}
	return f[n];
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	int k,q;cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>k;
		cout<<solve(k)<<endl;
	}
	
	return 0;
}
