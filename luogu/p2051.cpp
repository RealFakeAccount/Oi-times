#include <bits/stdc++.h>
using namespace std;
const int MAXN=100+2;
const int P=9999973;
int M,N;
long long f[MAXN][MAXN][MAXN];

int C(int x)
{
	return x*(x-1)/2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>M;
	memset(f,0,sizeof(f));
	f[0][0][0]=1;

	for(int i=1; i<=N; i++)
		for(int j=0; j<=M; j++)
			for(int k=0; k<=M-j; k++)
			{
	            f[i][j][k]+=f[i-1][j][k];
	            if(j>=1)  f[i][j][k]+=f[i-1][j-1][k+1]*(k+1);   
	            if(k>=1)  f[i][j][k]+=f[i-1][j][k-1]*(M-j-k+1);  
	            if(j&&k)  f[i][j][k]+=f[i-1][j-1][k]*(M-j-k+1)*k;
	            if(j>=2)  f[i][j][k]+=f[i-1][j-2][k+2]*C(k+2);  
	            if(k>=2)  f[i][j][k]+=f[i-1][j][k-2]*C(M-j-k+2); 
	            f[i][j][k]%=P;
			}
	long long ans=0;
	for(int i=0; i<=M; i++)
		for(int j=0; j<=M-i; j++)
			ans+=f[N][i][j],ans%=P;
	cout<<ans<<endl;
	return 0;
}

