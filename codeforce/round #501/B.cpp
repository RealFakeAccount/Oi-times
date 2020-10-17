#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int MAXN = 50 + 2;

int N;
string a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin>>N;
	cin>>a>>b;
	if(a == b){
		puts("0");
		return 0;
	}
	map<char, int> cntl;
	for(int i = 0; i < N; i++) {
		if(cntl.find(a[i]) == cntl.end()) cntl[a[i]] = 1;
		else cntl[a[i]]++;
	}
	bool flag = true;
	for(int i = 0; i < N; i++){
		if(cntl.find(b[i]) == cntl.end()) {
			flag = false;
			break;
		}
		cntl[b[i]]--;
	}
	map<char, int>::iterator it;
	for (it = cntl.begin(); it != cntl.end(); ++it)
		if(it->second != 0) {
			flag = false;
			break;
		}
	if(!flag) {
		puts("-1"); return 0;
	}
	vector<int> ans;
	for(int i = 0; i < N; i++){
		if(a[i] != b[i]){
			int p = i;
			for(int j = i + 1; j < N; j++)
				if(a[j] == b[i]) {
					p = j; break;
				}
			for(int j = p - 1; j >= i; j--){
				swap(a[j], a[j + 1]);
				ans.push_back(j + 1);
			}
		}
	
	}
	cout<<ans.size()<<endl;
	for(int i = 0; i <(int) ans.size(); i++)
		cout<<ans[i]<<" ";
	return 0;
}