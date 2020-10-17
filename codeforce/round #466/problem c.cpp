#include <bits/stdc++.h>
using namespace std;

bool a[30],Have[30];

inline int changeint(char x)
{
	return (int) x-96;
}

inline char changechar(int x)
{
	return (char) x+96;
}

int main()
{
	string s;
	int k,n;
	cin>>n>>k>>s;

	memset(a,0,sizeof(a));
	memset(Have,0,sizeof(Have));

	for(int i=0;i<(int) s.length();i++)
		a[ changeint(s[i]) ]=true;

	bool ok=false;
	for(int i=30;i>=1;i--)
	{
		if(a[i])
		{
			if(ok)
				Have[i]=true;
			else
				ok=true;
		}
	}

	ok=false;int poi=0;
	for(int i=n;i>=1;i--)
		if(have[s[i]])
		{
			ok=true;
			poi=i;
			break;
		}
	
	string ans;
	for(int i=1;i<=)
//	for(int i=1;i<=30;i++)
//		if(Have[i])
//			cout<<changechar(i)<<" ";
	return 0;
}