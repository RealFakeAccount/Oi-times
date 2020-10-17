#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>//STL 通用算法
using namespace std;

int l1,l2,l3,c1,c2,c3;
int n,st,en;
int sta[103]={0},f[1100]={0};

int piaojia(int x)
{
	if(x<=l1) return c1;
	if(x<=l2) return c2;
	if(x<=l3) return c3;
	return c3;
}

int main()
{
	cin>>l1>>l2>>l3>>c1>>c2>>c3;
	cin>>n;
	cin>>st>>en;
	if(st>en)
		swap(st,en);
	for(int i=2;i<=n;i++)
		cin>>sta[i];
	memset(f,63,sizeof(f));
	f[st]=0;
	for(int i=st;i<=en;i++)
		for(int j=i+1;j<=en;j++)
		{
			if(sta[j]-sta[i]>l3)
				break;
			f[j]=min(f[j],f[i]+piaojia(sta[j]-sta[i]));
		}
	cout<<f[en]<<endl;
	
	return 0;
}
