#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

double d[101]={0},m[101]={0},a[101]={0};
int n;

int main()
{
	scanf("%d",&n);
	scanf("%lf",&a[1]);
	m[1]=a[1];
	d[1]=100.0;
	for(int i=2;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		m[i]=max(m[i-1],d[i-1]*a[i]/100.0);
		d[i]=max(d[i-1],m[i-1]*100/a[i]);
	}
	printf("%0.2lf\n",d[n]);
	return 0;
}
