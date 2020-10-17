#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, K;

int main()
{
	cin>>N>>M>>K;
	if(K <= (N - 1))
	{
		cout<<K + 1<<" "<<1<<endl;
	}
	else
	{
		M--;
		K -= N;
		ll x, y;
		y = N - (K / M);
		if((K / M) % 2 == 0)
		{
			x = (K % M) + 2;
		}
		else
		{
			x = M - ((K % M)) + 1;
		}
		cout<<y<<" "<<x<<endl;
	}
	
	return 0;
}
