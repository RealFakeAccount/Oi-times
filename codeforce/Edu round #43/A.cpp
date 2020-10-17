#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 20;

int s[MAXN], N;

int main()
{
	cin>>N;
	getchar();
	for(int i = 1; i <= N; i++)
		s[i] = getchar() - '0';
	
	if(N == 1)
	{
		cout<<s[1]<<endl;
		return 0;
	}

	int cnt = 0;
	for(int i = 1; i <= N; i++)
		if(s[i] == 1) cnt++;

	cout<<1;
	for(int i = 1; i <= (N - cnt); i++)
		cout<<0;

	return 0;
}
