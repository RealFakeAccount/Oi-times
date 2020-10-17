#include <bits/stdc++.h>
using namespace std;
int N, K;

int main()
{
	cin>>N>>K;
	while(K--)
	{
		if(N % 10 != 0) N--;
		else N /= 10;
		//cout<<N<<endl;
	}
	cout<<N<<endl;
	return 0;
}