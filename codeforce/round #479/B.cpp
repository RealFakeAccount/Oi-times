#include <bits/stdc++.h>
using namespace std;

int N;
char s[110];

map<string, int> M;
int main()
{
	cin>>N;
	cin>>s;

	char cur[3];
	for(int i = 1; i < N; i++)
	{
		cur[0] = s[i - 1], cur[1] = s[i];
		//cout<<cur<<endl;
		M[cur]++;
	}

	int ans = 0;char ansc[3];
	for(int i = 1; i < N; i++)
	{
		cur[0] = s[i - 1], cur[1] = s[i];
		//cout<<cur<<" "<<M[cur]<<endl;
		if(M[cur] > ans)
		{
			strcpy(ansc, cur);
			ans = M[cur];
		}
	}
	cout<<ansc<<endl;
	return 0;
}