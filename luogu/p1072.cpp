#include <bits/stdc++.h>
#define inf 1000000000
#define N 50000
#define ll long long
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,tot;
int a0,b0,a1,b1,ans;
int pri[50005];
bool mark[50005];
void getpri()
{
    for(int i=2;i<=N;i++)
    {
	if(!mark[i])pri[++tot]=i;
	for(int j=1;j<=tot&&pri[j]*i<=N;j++)
	{
	    mark[pri[j]*i]=1;
	    if(pri[j]%i==0)break;
	}
    }
}
void solve(int x)
{
	int c0=0,c1=0,c2=0,c3=0;
	while(a0%x==0){a0/=x;c0++;}
	while(a1%x==0){a1/=x;c1++;}
	while(b0%x==0){b0/=x;c2++;}
	while(b1%x==0){b1/=x;c3++;}
	if(c0==c1&&c2==c3)
        {
	    if(c1<=c3)ans*=c3-c1+1;
	    else ans=0;
        }
	else if(c0!=c1&&c2!=c3&&c1!=c3)ans=0;
}
int main()
{
    getpri();
    n=read();
    while(n--)
    {
	ans=1;
	a0=read();a1=read();b0=read();b1=read();
	for(int i=1;i<=tot;i++)
	    solve(pri[i]);
	if(b1!=1)solve(b1);
	printf("%d\n",ans);
    }
    return 0;
}
