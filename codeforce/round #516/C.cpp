#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

string s;

int main()
{
	scanf("%*d"); cin>>s;
	sort(s.begin(), s.end());
	cout<<s<<endl;
	return 0;
}