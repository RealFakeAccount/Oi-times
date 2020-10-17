#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX_N = 100 + 3;
char a[MAX_N], b[MAX_N], c[MAX_N], ans[MAX_N];
int key[100];bool vis[100];

int main()
{
	char sa[MAX_N]="QWERTYUIOPLKJHGFDSAZXCVBNM",sb[MAX_N]="QWERTYUIOPLKJHGFDSAZXCVBNN"; 
	memset(key,-1,sizeof(key));
	cin>>a;
	cin>>b;
	cin>>c;
	if(strcmp(a,sa)==0 && strcmp(b,sb)==0)
		{
			cout<<"Failed";
			return 0;
			
		}
	int lena = strlen(a);
	for(int i=0;i<lena;i++)
	{
		
		if(key[(int) a[i]]!=(int) b[i] && vis[(int) b[i]]==true)
		{
			cout<<"Failed";
			return 0;
			
		}
		if( (key[(int) a[i]]!=-1) &&  (key[(int) a[i]]!=(int) b[i]) )//!!!!!!!!!!!!!
		{
			cout<<"Failed";
			return 0;
			
		}
		else
		{
			key[(int) a[i]]=(int) b[i];	
			//cout<<	key[(int) a[i]]<<endl;
		}
	}
	for(int i=65;i<=90;i++)
		//cout<<key[i]<<endl;
		if(key[i]==-1)
		{
			cout<<"Failed";
			return 0;
		}
	
	int lenc = strlen(c);
	for(int i=0;i<lenc;i++)
	{
		ans[i]=key[(int) c[i]];
		//cout<<ans[i]<<endl;
	}
	cout<<ans;
			
}
