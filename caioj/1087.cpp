#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int t,a,n,ans=9999999;
int ti[1001],ai[1001],wi[1001];
int f[410][410];
int main()
{
	//freopen("1087.txt","r",stdin);
	cin>>t>>a>>n;
	for(int i=1;i<=n;i++)
		cin>>ti[i]>>ai[i]>>wi[i];
	memset(f,63,sizeof(f));
	f[0][0]=0;
	for(int g=1;g<=n;g++)
		for(int i=t;i>=0;i--)
			for(int j=a;j>=0;j--)
			{
				f[i+ti[g]][j+ai[g]]=min(f[i][j]+wi[g],f[i+ti[g]][j+ai[g]]);
				if(i+ti[g]>=t&&j+ai[g]>=a)
					ans=min(ans,f[i+ti[g]][j+ai[g]]);
				int t1=min(t,i+ti[g]),t2=min(a,j+ai[g]);
				f[t1][t2]=min(f[t1][t2],f[i+ti[g]][j+ai[g]]);
			}
	cout<<ans<<endl;
	return 0;
} 
