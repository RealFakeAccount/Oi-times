#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	while(cin>>a>>b>>c)
	{
		double cow = 1.0 * a / (a + b);
		double x = cow * b / (a + b - c - 1);
		double car = 1.0 * b / (a + b);
		double y = car * (b - 1) / (a + b - c - 1);
		printf("%.5lf\n", x + y);
	}
	return 0;
}