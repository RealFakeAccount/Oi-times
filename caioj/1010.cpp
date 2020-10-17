#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n,i;
	double w;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		w=w+1.0/i;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(5)<<w<<endl;
	return 0;
}