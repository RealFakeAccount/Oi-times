#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main()
{
	cout<<"1.sync_with_stdio(false)"<<endl;
	freopen("read2.txt","r",stdin);
	ios::sync_with_stdio(false);
	char c;
	clock_t start = clock();
	for(int i=1;i<=10000000;i++)
	{
		for(int j=1;j<=6;j++)	
		{
			cin>>c;
		}
	}
	clock_t ends = clock();
	cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
	ios::sync_with_stdio(true);
	fclose(stdin);

	cout<<"2.scanf"<<endl;
	freopen("read2.txt","r",stdin);
	start = clock();
	for(int i=1;i<=10000000;i++)
	{
		for(int j=1;j<=6;j++)	
		{
			scanf("&c",&c);
		}
	}
	ends = clock();
	cout <<"Running Time : "<<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
	fclose(stdin);
	return 0;
}
