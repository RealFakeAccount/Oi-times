#include <bits/stdc++.h>
using namespace std;

int n,m,i,j,k,l,r,mid,a[100001],x;

int pd(int c,int d)
{
	if(abs(c-x)<=abs(d-x))
		return c;
	return d;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	
	{
		l=1;r=n;
		cin>>x;
		while(l<r)
		{
			mid=(l+r+1)/2;
			if(a[mid]>x)
				r=mid-1;
			else
				l=mid;
		}
		cout<<pd(a[l],a[l+1])<<endl;
	}
	return 0;
}
