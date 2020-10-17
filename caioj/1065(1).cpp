#include <cstring>
#include <iostream>
using namespace std;

int a[200],b[200]={0},c[200]={0};

int main()
{
	int n,i,j,maxx;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		b[i]=1;
		for(j=1;j<=i-1;j++)
			if((a[i]>a[j])&&(b[j]+1>b[i]))
				b[i]=b[j]+1;
	}
	for(i=n;i>=1;i--)
	{
		c[i]=1;
		for(j=i+1;j<=n;j++)
			if((a[i]<a[j])&&(c[j]+1>c[i]))
				c[i]=c[j]+1;
	}
	maxx=0;
	for(i=1;i<=n;i++)
		if(b[i]+c[i]>maxx)
			maxx=b[i]+c[i];
	cout<<n-maxx+1<<endl;
	return 0;
}
