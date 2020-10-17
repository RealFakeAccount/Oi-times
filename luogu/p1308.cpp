#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string tag, cur;

inline void chg(string &s){
	for(int i = 0; i < (int) s.size(); i++)
		if('A' <= s[i] && s[i] <= 'Z') 
			s[i] -= 'A', s[i] += 'a';
}

int main()
{
	//freopen("p1308.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin>>tag; chg(tag);
	int ans1 = -1, ans2 = 0, len = 0;
	while(cin>>cur){
		chg(cur);
		if(cur == tag){
			if(ans1 == -1) ans1 = len;
			++ans2;
		}
		len += cur.length() + 1;
	}
	if(ans1 == -1) puts("-1");
	else cout<<ans2<<" "<<ans1<<endl;
	return 0;
}