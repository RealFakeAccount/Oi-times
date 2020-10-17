#include<iostream>//基本输入输出流
#include<cstdio>
#include<cstring>
#include <algorithm>//STL 通用算法
using namespace std;

int n,s,t[5010]={0},c[5010]={0},ts[5010]={0},cs[5010]={0};
int f[5010],ans;
int main()
{
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>c[i];
		ts[i]=t[i]+ts[i-1];
		cs[i]=c[i]+cs[i-1];
	}
	memset(f,63,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i]=min(f[i],f[j-1]+ts[i]*(cs[i]-cs[j-1])+s*(cs[n]-cs[j-1]));
	cout<<f[n]<<endl;
	return 0;
}
