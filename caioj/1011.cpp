#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n,a;
	double x,w;
	x=0;
	cin>>n;
	double i[n];
	for(a=1;a<=n;a++)
	{
		cin>>i[a];
	}
	for(a=1;a<=n;a++)
	{
		x=x+i[a];
	}
	w=x/n;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<w<<endl;
	return 0;
}