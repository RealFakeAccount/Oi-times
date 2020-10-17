#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n,w,i;
	cin>>n;
	w=0;
	for(i=1;i<=n;i=i+2)
	{
		w=w+i;
	}
	cout<<w<<endl;
	return 0;
}
