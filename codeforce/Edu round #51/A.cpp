#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e2 + 10;

int T;
string s;

inline int type(char ch){
	if('0' <= ch && ch <= '9') return 0;
	if('a' <= ch && ch <= 'z') return 1;
	else return 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		int cnt[3]; cin>>s; memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < (int) s.size(); i++)
			cnt[type(s[i])]++;
		
		for(int i = 0; i < 3; i++) if(cnt[i] == 0){
			int pos = 0;
			for(int j = 0; j < 3; j++) if(cnt[j] > 1) pos = j; 

			++cnt[i], --cnt[pos];
			for(int j = 0; j < (int) s.size(); j++) if(type(s[j]) == pos){
				if(i == 0) s[j] = '1';
				else if(i == 1) s[j] = 'a';
				else s[j] = 'A';
				break;
			}
		}cout<<s<<endl;
	}
	return 0;
}
