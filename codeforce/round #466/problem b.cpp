#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,A,B;
	cin>>n>>k>>A>>B;
	int cnt=0;
	while(n!=1)
	{
		if(n<k)
		{
			cnt+=(n-1)*A;
			break;
		}
		int r=n%k;
		if(r)
		{
			cnt+=r*A;
			n-=r;
		}
		else
		{
			if((n-n/k)*A<B)
			{
				cnt+=(n-1)*A;
				break;
			}
			else
			{
				cnt+=B;
			}
			n/=k;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
