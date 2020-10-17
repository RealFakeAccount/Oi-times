#include <cstdio>
#include <iostream>
using namespace std;

int a[105];
int main()
{
	int n,i,m;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	m=a[1];
	for(i=2;i<=n;i++)
	{
		if(m<=a[i])
		{
			m=a[i];
		}
	}
	cout<<m<<endl;
	return 0;
}
