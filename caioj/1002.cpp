#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a,b,c,d,e;
	cin>>a>>b>>c;
	e=(a+b+c)/3.0;
	d=a*b*c;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<e<<" "<<d<<endl;
	return 0;
}