#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 50 + 2;

int a[MAXN];
int N;

int main()
{
	cin>>N;
	for(int i = 1; i <= N; i++)
		scanf(" %d", &a[i]);

	int ans = 0;
	for(int i = 1; i < N; i++)
		for(int j = i; j <= N; j++)
			if(a[i] > a[j])
			{
				reverse(a + i + 1, a + j + 1);
				ans++;
			}
	cout<<ans<<endl;
	return 0;
}