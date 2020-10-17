#include<cstdio>
#include<iostream>
using namespace std;

int judge2(int x)
{
	int x1,x2;
	x1=x%10;
	x2=x/10%10;
	if ( x1==x2 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int judge3(int x)
{
	int x1,x3;
	x1=x%10;
	x3=x/100%10;
	if ( x1==x3 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int judge4(int x)
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
	int m,n,i,s;
	cin>>m>>n;
	for(i=m;i<=n;i++)
	{
		if (i<10) 
		{
			cout<<i<<endl;
		}
		else if (i<100)
		{
			s=judge2(i);
			if (s==1)
			{
				cout<<i<<endl;
			}
		}
		else if (i<1000)
		{
			s=judge3(i);
			if (s==1)
			{
				cout<<i<<endl;
			}
		}
		else if (i<1000)
		{
			s=judge4(i);
			if (s==1)
			{
				cout<<i<<endl;
			}
		}
	}
	return 0;
}