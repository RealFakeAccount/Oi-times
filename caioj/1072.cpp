#include <algorithm>//STL 通用算法
#include <iostream>//基本输入流//基本输出流 
#include <cstring>
#include <cstdio>

using namespace std;

struct node
{
	int y,ans,x;
	node()
	{
		y=0;ans=0;x=0;
	}
}f[1001][1001];

int main()
{
	char a[1001],b[1001],s[1001];
	int lena,lenb;
	scanf("%s",a+1);lena=strlen(a+1);
	scanf("%s",b+1);lenb=strlen(b+1);
	for(int i=1;i<=lena;i++)
		for(int j=1;j<=lenb;j++)
		{
			f[i][j].ans=max(f[i-1][j].ans,f[i][j-1].ans);
			if(f[i-1][j].ans>f[i][j-1].ans)
			{
				f[i][j].x=f[i-1][j].x;
				f[i][j].y=f[i-1][j].y;
			}
			else
			{
				f[i][j].x=f[i][j-1].x;
				f[i][j].y=f[i][j-1].y;
			}
			if(a[i]==b[j])
			{
				f[i][j].ans=f[i-1][j-1].ans+1;
				f[i][j].x=f[i-1][j-1].x;
				f[i][j].y=f[i-1][j-1].y;
			}	
		}
	cout<<f[lena][lenb].ans<<endl;
	int i=lena,j=lenb,len=0; 
	while(f[i][j].ans>0)
	{
		int ii=i,jj=j;
		s[++len]=a[f[ii][jj].x];
		i=f[ii][jj].x-1;j=f[ii][jj].y-1;
	}
	for(int i=len;i>=1;i--)
		cout<<s[i];
	return 0;
}
