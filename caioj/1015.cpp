#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int judge(int a)
{
	if (a==1)
	{
		return 1;
	}
	else
	{
		int t= sqrt(a+1);
		int i;
		for(i=2;i<=t;i++)
		{
			if(a%i==0)
			{
				return 1;
			}
		}
		return 0;
	}
}

int main()
{
	int m,n;
	cin>>m;
	n=judge (m);
	if (n==1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}
	return 0;
}