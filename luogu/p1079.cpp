#include <deque>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

char list[26][26];

int main()
{
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
                if (('A'+i+j)<='Z')
                    list[i][j]='A'+i+j;
                else
                    list[i][j]='A'+i+j-'Z'+'A'-1;  
    string k,c;   
    getline(cin,k);
    getline(cin,c);   
    if (k.size()<c.size())   
    {
        string t;  
        t=k;  
        int n=ceil((double)c.size()/k.size());
        for (int i=0;i<n;i++)
            k.insert(k.end(),t.begin(),t.end()); 
    }
    for (int i=0;i<c.size();i++)
        for (int j=0;j<26;j++)
            if (list[toupper(k[i])-'A'][j]==c[i] || list[toupper(k[i])-'A'][j]==toupper(c[i]))  
            {
                if (c[i]>='a' && c[i]<='z')
                    putchar('a'+j);
                else
                    putchar('A'+j); 
            }
    return 0;
}


