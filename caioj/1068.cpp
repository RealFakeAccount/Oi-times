#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S,T;
int f[1002][1002];

int main()
{
	cin>>S;
	cin>>T;
	int ls = S.length(),lt = T.length();
	for(int i=1;i<=ls;i++)
		for(int j=1;j<=lt;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(S[i]==T[j])
				f[i][j]=f[i-1][j-1]+1;
				//f[i][j]=max(f[i][j],f[i-1][j-1]+1);也行吧。。
		}
		cout<<f[ls][lt]<<endl;
}
