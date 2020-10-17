#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>//STL 通用算法
using namespace std;

struct node
{
	int head,tail,v;
}r[101];

int m,n,k,s[101][101]={0},f[101][101]={0};

int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>r[i].head>>r[i].tail>>r[i].v;
	cin>>k;
	for(int x=1;x<=m;x++)
		for(int y=x;y<=m;y++)
			for(int z=1;z<=n;z++)
				if(x<=r[z].head && r[z].tail<=y)
					s[x][y]+=r[z].v;
				//cout<<x<<" "<<y<<endl;
				//cout<<s[x][y]<<endl;
	memset(f,-63,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=k;j++)
			for(int k1=0;k1<i;k1++)
			//cout<<i<<" "<<j<<endl;
			f[i][j]=max(f[i][j],f[k1][j-1]+s[k1+1][i]);
			//cout<<f[i][j]<<endl;
	cout<<f[m][k]<<endl;
	return 0;
}
