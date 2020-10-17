#include<map>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct qt
	{
		int x;
		int ci;
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
char b[2]={A,B,C};
char b1[99999]
int main()
{
	int a,ma;
	bool v=true;
	for(int i=1;i<=8;i++)
	{
		cin>>a;
		ma=ma*10+a;
	}
	int head,tail;
	head=0;
	tail=1;
	q[1].x=ma;
	q[1].ci=0;
	do
	{
		head++;
		for(int i=0;i<=2;i++)
		{
			int c=chai(q[head].x,b[i]);
			for(int j=1;j<=head;j++)
			{
				if(q[j].x=c)
				{
					v=false;
					break;
				}
			}
			if(v)
			{
				tail++;
				q[tail].x=c;
				q[tail].ci=q[head].ci+1;
			}
		}
	}
	
	
}