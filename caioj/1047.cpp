#include<map>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct qt
	{
		int x;
		int fa;
		char ch;
	}q[5000000];
int chai(int n,char a)
{
	int s[9],t,k;
	for(int i=8;i>=1;i--)
	{
		s[i]=n%10;
		n/=10;
	}
	if(a=='A') for(int i=1;i<=4;i++){t=s[i];s[i]=s[9-i];s[9-i]=t;}
	if(a=='B') {t=s[4];k=s[5];for(int i=4;i>=2;i--){s[i]=s[i-1];s[9-i]=s[10-i];}s[1]=t;s[8]=k;}
	if(a=='C') {t=s[2];s[2]=s[7];s[7]=s[6];s[6]=s[3];s[3]=t;}
	t=0;
	for(int i=1;i<=8;i++) t=t*10+s[i];
	return t; 
}
int main()
{
	map<int,int> pan;
	int a,m=0,n=1,ma=0,j=0;
	char ans[1000];
	for(int i=1;i<=8;i++)
	{
		cin>>a;
		ma=ma*10+a;
	}
	q[0].x=12345678;q[0].ch='1';
	if(q[0].x==ma)
	{
		cout<<0;
		return 0;
	}
	for(;;)
	{
		if(pan[chai(q[m].x,'A')]!=1)
		{
			q[n].x=chai(q[m].x,'A');q[n].fa=m;q[n].ch='A';pan[q[n].x]=1;
		    if(q[n].x==ma) break;
	        n++;	
		}
		if(pan[chai(q[m].x,'B')]!=1)
		{		
		    q[n].x=chai(q[m].x,'B');q[n].fa=m;q[n].ch='B';pan[q[n].x]=1;
		    if(q[n].x==ma) break;
		    n++;
		}
        if(pan[chai(q[m].x,'C')]!=1)
        {
        	q[n].x=chai(q[m].x,'C');q[n].fa=m;q[n].ch='C';pan[q[n].x]=1;
		    if(q[n].x==ma) break;
		    n++;
        }
		m++;
	}
	while(n!=0)
	{
		ans[j]=q[n].ch;
		n=q[n].fa;
		j++;
	}
	cout<<j<<endl;
	for(int i=j-1;i>=0;i--) cout<<ans[i];
	return 0;
}