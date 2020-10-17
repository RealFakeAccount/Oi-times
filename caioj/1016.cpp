#include<cstdio>
#include<iostream>
using namespace std;

int judge(int x)
{
	int x1,x2,x3,x4;
	x1=x%10;
	x2=x/10%10;
	x3=x/100%10;
	x4=x/1000;
	if ( x1==x4 && x2==x3 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int m,n;
	cin>>m;
	n=judge(m);
	if (n==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}