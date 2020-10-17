#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

inline void putint(int n)
{
	if(n == 0) return (puts("0"), void());
	char ch[16]; int cnt = 0;
	while(n) ch[cnt++] = n % 10, n /= 10;
	while(cnt--) putchar(ch[cnt] + '0');
}

int main()
{
    int n, c[101];
    while (n = read())
    {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++)
            c[read()]++;
        int first = 1;
        for (int i = 1; i <= 100; i++)
            for (int j = 0; j < c[i]; j++)
            {
                if (!first) 
                    putchar(' ');
                first = 0;
                putint(i);
            }
        putchar('\n');
    }
    return 0;
}