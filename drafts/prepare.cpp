#include <cstdio>
#include <iostream>//基本输入流//基本输出流 
#include <algorithm>//STL 通用算法
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <sstream>

using namespace std;

int main()
{
	return 0;
	//#include <iomanip>
	//cout<<setiosflags(ios::fixed)<<setprecision(n)<<x<<endl;
}




int add(int x,int y)
{
	int res;
	res=x+y;
	return res;
}


int digit(int x)
{
	if(x<10)
	{
		return 1;
	}
	else if(x<100)
	{
		return 2;
	}
	else if(x<1000)
	{
		return 3;
	}
	else if(x<10000)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}