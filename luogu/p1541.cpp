#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=350+5;
const int MAX_M=120+5;

int n1=0,n2=0,n3=0,n4=0,N,M;
int f[41][41][41][41]={0};
int m[MAX_N]={0};

int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		cin>>m[i];
	int x;
	for(int i=1;i<=M;i++)
	{
		cin>>x;
		if(x==1) n1++;
		if(x==2) n2++;
		if(x==3) n3++;
		if(x==4) n4++;
	}
	f[0][0][0][0]=m[1];
	int num=0;
	for(int i1=0;i1<=n1;i1++)
		for(int i2=0;i2<=n2;i2++)
			for(int i3=0;i3<=n3;i3++)
				for(int i4=0;i4<=n4;i4++)
				{
					num=1+i1*1+i2*2+i3*3+i4*4;
					if(i1) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1-1][i2][i3][i4]+m[num]);
					if(i2) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2-1][i3][i4]+m[num]);
					if(i3) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3-1][i4]+m[num]);
					if(i4) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3][i4-1]+m[num]);
				}
	cout<<f[n1][n2][n3][n4]<<endl;
	return 0;
}
