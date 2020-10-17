#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int N, M;

priority_queue<int, vector<int>, greater<int> > q;
int main()
{
	cin>>N;
	int opt, x;
	for(int i = 1; i <= N; i++ )
	{
		scanf("%d", &opt);
		if(opt == 1) 
		{
			scanf("%d", &x);
			q.push(x);
		}
		if(opt == 2)
			printf("%d\n",q.top());
		if(opt == 3)
			q.pop();
	}
	return 0;
}