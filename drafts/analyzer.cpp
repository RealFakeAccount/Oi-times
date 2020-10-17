#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef pair<int, ull> P;
const int BASE = 191;
const int MAX_SENTENCE_SIZE = 1e3 + 10;

ull Hash(string &s) {
	ull tmp = 1;

	for(int i = 0; i < (int) s.size(); i++) 
		(tmp *= BASE) += s[i];

	return tmp;
}

struct Word
{
	string spe;
	ull idx;
	int len;

	void init(string &s) {
		spe = s;
		idx = Hash(s);
		len = s.size();
	}
};

map<ull, Word> pool;
map<ull, int> Article;

char buff[MAX_SENTENCE_SIZE];

void Init_Sentences() {
	int n = strlen(buff);
	string tmp;
	for(int i = 0; i < n + 1; i++) {
		if(isalpha(buff[i])) tmp.push_back(buff[i]);
		else {
			if(tmp.size()) {
				ull hsnum = Hash(tmp);

				if(pool.find(hsnum) == pool.end()) {//don't exist before?
					Word newword;
					newword.init(tmp);
					pool[hsnum] = newword;
				}

				Article[hsnum]++;
			}

			tmp.clear();
		}
	}
}

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	while(scanf(" %s", buff) == 1) 
		Init_Sentences(), memset(buff, 0, sizeof(buff));

	vector<P> cnt;
	for(auto it : Article) 
		cnt.push_back(make_pair(it.second, it.first));

	sort(cnt.begin(), cnt.end());
	reverse(cnt.begin(), cnt.end());
	for(auto it : cnt) 
		cout<<pool[it.second].spe<<" "<<it.first<<endl;
	return 0;
}