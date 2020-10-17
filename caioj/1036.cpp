#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,t;
void dg(int a,int b,int c)
{
	if(c==n)
	{
		t++;
		return ;
	}
	if(a>0&&b<n)
	{
		dg(a-1,b+1,c);
	}
	if(b>0&&c<n)
	{
		dg(a,b-1,c+1);
	}
}
int main()
{
	cin>>n;
	dg(n,0,0);
	cout<<t<<endl;
	return 0;
}