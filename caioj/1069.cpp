#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;

char a[51],b[51];
int  f[51][51],l1,l2;

int main()
{
    scanf("%s%s",a+1,b+1);
    l1=strlen(a+1); l2=strlen(b+1);
    for(int i=1;i<=l1;i++)
		for(int j=1;j<=l2;j++)
		{
			if(a[i]==b[j]) 
				f[i][j]=f[i-1][j-1]+2;
			for(int k=1;k<i;k++) 
				f[i][j]=max(f[i][j],f[k][j]-1);
			for(int k=1;k<j;k++) 
				f[i][j]=max(f[i][j],f[i][k]-1);
			f[i][j]=max(f[i][j],f[i-1][j-1]);
		} 
		printf("%d",f[l1][l2]);
}
