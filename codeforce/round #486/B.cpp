#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

string s[120];

bool cmp(const string &a, const string &b)
{
	return a.find(b) == string::npos;
}

int main()
{
	int N;
	cin>>N;
	for(int i = 1; i <= N; i++) cin>>s[i];
	
	sort(s + 1, s + N + 1, cmp);

	for(int i = 1; i <= N; i++)
		for(int j = 1; j < i; j++)
			if(s[i].find(s[j]) == string::npos)
			{
				puts("NO"); return 0;
			}

	puts("YES");
	for(int i = 1; i <= N; i++)
		cout<<s[i]<<endl;
	return 0;
}