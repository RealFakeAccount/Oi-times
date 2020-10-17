#include <cstdio>
#include <iostream>
using namespace std;

int a[10];
int main()
{
	int h,w,i;
	w=0;
	for(i=1;i<=10;i++)
	{
		cin>>a[i];
	}
	cin>>h;
	h=h+30;
	for(i=1;i<=10;i++)
	{
		if(a[i]<=h)
		{
			w=w+1;
		}
	}
	cout<<w<<endl;
	return 0;
}