#include <bits/stdc++.h>
using namespace std;
const int MAXN=30;
struct mite1
{
	int cost;int impo;
	mite1(int u=0,int v=0) : cost(u),impo(v) {
	} 
};

mite1 e[MAXN];int f[30000+10];

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		e[i]=mite1(u,v);
	}
	//cout<<e[2].cost<<" "<<e[2].impo;
	memset(f,0,sizeof(f));
	for(int i=1;i<=m;i++)
		for(int j=n;j>=e[i].cost;j--)
			f[j]=max(f[j],f[j-e[i].cost]+e[i].cost*e[i].impo);
	cout<<f[n]<<endl;
	
	return 0;
}
