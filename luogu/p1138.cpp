#include <bits/stdc++.h>
using namespace std;
const int MAXN=10000+5;
int a[MAXN];

int main()
{
	int N,K;
	cin>>N>>K;
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+N+1);

	int L=a[1],cnt=1;
	for(int i=1;i<=N;i++)
	{
		if(a[i]==L)
			continue;
		cnt++,L=a[i];
		if(cnt==K)
		{
			cout<<a[i]<<endl;
			return 0;
		}
	}
	cout<<"NO RESULT"<<endl;
	return 0;
}