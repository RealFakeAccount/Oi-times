#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2005;
int n,ans,pre[N],nxt[N],f[N],a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) {
		f[i]=1;
		for(int j=1;j<i;++j)
			if(a[j]<=a[i]&&f[j]+1>f[i]) f[i]=f[j]+1;
		pre[i]=max(f[i],pre[i-1]);
	}
	for(int i=n;i>=1;--i) {
		f[i]=1;
		for(int j=n;j>i;--j)
			if(a[j]>=a[i]&&f[j]+1>f[i]) f[i]=f[j]+1;
		nxt[i]=max(f[i],nxt[i+1]);
	}
	for(int i=1;i<=n;++i) ans=max(ans,pre[i]+nxt[i+1]);
	printf("%d",ans);
	return 0;
}