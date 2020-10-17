#include <bits/stdc++.h>
#include <time.h>
using namespace std;
//fast readin
inline int readIn()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
//end
//faster readin
const int BUFSIZE=120<<20;
char Buf[BUFSIZE+1],*buf=Buf;
template<class T>
inline void scan(T&a)
{
	for(a=0;*buf<'0' || *buf>'9';buf++);
	while(*buf>='0' && *buf<='9')
	{
		a=a*10+(*buf-'0');
		buf++;
	}
} 
//end
int main()
{
	cout<<"1.sync_with_stdio(false)"<<endl;
	freopen("read1.txt","r",stdin);
	ios::sync_with_stdio(false);
	int c;
	clock_t start = clock();
	for(int i=1;i<=9999999;i++)
		cin>>c;
	cin>>c;
	cout<<c<<endl;
	clock_t ends = clock();
	cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
	fclose(stdin);
	
	cout<<"2.fast readin"<<endl;
	freopen("read1.txt","r",stdin);
	start = clock();
	for(int i=1;i<=10000000;i++)
		c=readIn();
	ends = clock();
	cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
	fclose(stdin);
	
	cout<<"3.faster readin"<<endl;
	freopen("read1.txt","r",stdin);
	fread(Buf,1,BUFSIZE,stdin);
	start = clock();
	for(int i=1;i<=9999999;i++)
		scan(* &c);
	scan(* &c);
	cout<<c<<endl;
	ends = clock();
	cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
	fclose(stdin);
	
	cout<<"4.scanf"<<endl;
	freopen("read1.txt","r",stdin);
	start = clock();
	for(int i=1;i<=10000000;i++)
		scanf("%d",&c);
	ends = clock();
	cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
	fclose(stdin);
	return 0;
}
