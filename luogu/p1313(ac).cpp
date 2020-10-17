#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXK=1000+10;

int tri[MAXK][MAXK]={0};
int m,n,k,a,b;
long long ans;

void xishu()
{
	for(int i=0;i<=k;i++)
		tri[i][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k+1;j++)
			tri[i][j]=(tri[i-1][j]+tri[i-1][j-1])%10007;
}

int main()
{
	cin>>m>>n>>k>>a>>b;
	if((a==0)&&(b==0))
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(a==0)
	{
		int ans=1;
		for(int i=1;i<=k;i++)
			ans*=n;
		cout<<ans<<endl;
		return 0;
	}
	if(b==0)
	{
		int ans=1;
		for(int i=1;i<=k;i++)
			ans*=m;
		cout<<ans<<endl;
		return 0;
	}
	xishu();
	//for(int i=0;i<=4;i++)
	//<<tri[2][i];
//	for(int i=0;i<=4;i++)
	//	cout<<tri[3][i];
	long long ma=1,nb=1;
	for(int i=1;i<=a;i++)
		ma=ma*m%10007;
	for(int i=1;i<=b;i++)
		nb=nb*n%10007;
	ans=(ma*nb*tri[k][b]%10007);
	cout<<ans<<endl;
	return 0;
}

