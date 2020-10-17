#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;

int main()
{
	freopen("data.in", "w", stdout);
	srand(time(NULL));
	cin>>N; cout<<N<<endl;
	for(int i = 1; i <= N; i++)
		putchar((rand() % 3) + 'a');
	putchar('\n'); 
	return 0;
}