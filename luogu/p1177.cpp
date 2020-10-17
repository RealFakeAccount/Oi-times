#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[100000+10],N;
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>a[i];
	sort(a+1,a+1+N);
	for(int i=1;i<=N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
