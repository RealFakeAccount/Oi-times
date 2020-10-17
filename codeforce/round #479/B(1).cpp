#include <bits/stdc++.h>
using namespace std;
typedef pair<char, char> P;

map<P, int> M;
int main()
{
	int N;
	char ch[110];
	scanf("%d\n%s", &N, ch);

	P ans1; int ans2 = 0;
	for(int i = 1; i < N; i++)
	{
		P p;
		p.first = ch[i - 1], p.second = ch[i];
		M[p]++;
		if(M[p] > ans2)
		{
			ans2= M[p],
			ans1 = p;
		}
	}
	cout<<ans1.first<<ans1.second<<endl;
	return 0;
}