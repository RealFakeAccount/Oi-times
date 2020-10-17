#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	long long n,s,i;
	cin>>n;
	s=1;
	for(i=1;i<=n;i++)
	{
		s=s*i;
	}
	cout<<s<<endl;
	return 0;
}