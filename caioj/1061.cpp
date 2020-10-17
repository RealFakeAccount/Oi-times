#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

char st[1000010];
char cc[7][10];

bool tf(int x,int j)
{
	for(int i=1;i<=strlen(cc[j]+1);i++)
		if(cc[j][i]!=st[x+i])
			return false;
	return true;
}

bool f[1000010];

int main()
{
	cc[1][1]='i';cc[1][2]='n';
	cc[2][1]='o';cc[2][2]='n';cc[2][3]='e';
	cc[3][1]='o';cc[3][2]='u';cc[3][3]='t';
	cc[4][1]='p';cc[4][2]='u';cc[4][3]='t';cc[4][4]='o';cc[4][5]='n';
	cc[5][1]='i';cc[5][2]='n';cc[5][3]='p';cc[5][4]='u';cc[5][5]='t';
	cc[6][1]='o';cc[6][2]='u';cc[6][3]='t';cc[6][4]='p';cc[6][5]='u';cc[6][6]='t';
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,false,sizeof(f));
		f[0]=true;
		scanf("%s",st+1);
		int n=strlen(st+1);
		bool bk=false;
		for(int i=0;i<n;i++)
		{
			if(st[i+1]!='i'&&st[i+1]!='n'&&st[i+1]!='o'&&st[i+1]!='u'&&st[i+1]!='t'&&st[i+1]!='p'&&st[i+1]!='e')
				break;
			else
			{
				for(int j=1;j<=6;j++)
				{
					if(i+strlen(cc[j]+1)>n)
						break;
					if(f[i]==false)
						break;
					if(tf(i,j)==true)
						f[i+strlen(cc[j]+1)]=true;
				}
			}
		}
		if(f[n]==false)
			printf("NO\n");
		else 
			printf("YES\n");
	}
	return 0;
}
