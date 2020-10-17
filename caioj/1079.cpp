#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>//STL 通用算法

using namespace std;
int n,h,fish[210][3000]={0},f[210][3000]={0};
int fi[210]={0},di[210]={0},ti[210]={0};
int maxx=0;

int main()
{
	//freopen("1079.txt","r",stdin);
	cin>>n>>h;
	h=h*12;
	for(int i=1;i<=n;i++)
		cin>>fi[i];
	for(int i=1;i<=n;i++)
		cin>>di[i];
	for(int i=1;i<=n-1;i++)
		cin>>ti[i];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=h;j++)
			fish[i][j]=fish[i][j-1] + fi[i]-di[i]*(j-1);
	
	memset(f,-63,sizeof(f));
	for(int i=0;i<=h;i++)
		f[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=ti[i-1];j<=h;j++)
			for(int j1=0;j1<=j-ti[i-1];j1++)
			{
				f[i][j]=max(f[i][j],f[i-1][j1]+fish[i][j-ti[i-1]-j1]);
				/*cout<<"***********"<<endl;
				cout<<"i="<<i<<" j="<<j<<endl;
				cout<<f[i][j]<<endl;*/
				maxx=max(maxx,f[i][j]);
			}
	cout<<maxx<<endl;
	return 0;
}
