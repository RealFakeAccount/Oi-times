#include <cstdio>
using namespace std;
int main()
{
	int n,s;
	s=0;
	scanf("%d",&n);
	int x=n;
	while(x>0)
	{
		s=s+x%10;
		x=x/10;
	}
	printf("%d",s);
	return 0;
}