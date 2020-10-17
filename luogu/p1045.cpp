#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e2 + 20;

int P;
int tmp[MAXN], pows[MAXN]

void calc1(){

}

int main()
{
	cin>>P;
	cout<<(int)(log10(2) * P + 1)<<endl;
	while(P){
		if(P & 1) calc1();
		calc2();
		P >>= 1;
	}

	return 0;
}