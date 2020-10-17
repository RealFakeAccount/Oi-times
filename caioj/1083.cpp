#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>//STL 通用算法
using namespace std;

int i,j,k,x,n,in,maxx,m,a[10000]={0},b[10000]={0},h[10000]={0};

int main()
{
	i=1;n=0;m=0;
	cin>>in;
	while(cin>>a[i])
	{
		maxx=0;
		for(j=1;j<=i-1;j++)
			if(a[j]>=a[i])
				if(b[j]>maxx)
					maxx=b[j];
		b[i]=maxx+1;
		if(b[i]>m)
			m=b[i];
		x=0;
		for(k=1;k<=n;k++)
			if(h[k]>=a[i])
				if(x==0)
					x=k;
				else if(h[k]<h[x])
					x=k;
		if(x==0)
			{
				n++;
				x=n;
			}
		h[x]=a[i];
		i++;
		if(i>in)
			break;
	}
	cout<<n<<endl;
	return 0;
}
