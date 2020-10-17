#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000000 + 10;

int f[MAXN];
int N, M;

void process(const char *tmp){
    f[0] = f[1] = 0;
    for(int i = 1; i < N; i++){
        int j = f[i];
        while(j && tmp[i] != tmp[j]) j = f[j];
        f[i + 1] = (tmp[i] == tmp[j] ? j + 1 : 0);
    }
}

void findstr(const char *str, const char *tmp){
    process(tmp);
    int j = 0;
    for(int i = 0; i < N; i++){
        while(j && str[i] != tmp[j]) j = f[j];
        if(str[i] == tmp[j]) ++j;
        if(j == M) printf("%d\n", i - M + 2);
    }
}

char ch1[MAXN], ch2[MAXN];

int main()
{
    scanf("%s %s", ch1, ch2);
    N = strlen(ch1), M = strlen(ch2);
    findstr(ch1, ch2);
    for(int i = 1; i <= M; i++) printf("%d ", f[i]);
    return 0;
}