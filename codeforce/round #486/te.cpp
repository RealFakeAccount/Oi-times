#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("B.out", "w", stdout);
	int N;
	cout<<(N = ran
		d() % 100)<<endl;
	for(int i = 1; i <= N; i++)
		{for(int j = 1; j <= rand() % 100; j++)
					cout<<(char)rand() % 26 + 'a';
			cout<<endl;
		}

	return 0;
}