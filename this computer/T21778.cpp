#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 100005;

vector<int> vec[MAXN];

struct Node {
  pair<int, int> val;
  Node *ls, *rs;
  Node(): val(make_pair(0, 0)), ls(NULL), rs(NULL) { }
  void pushup() {
    val = max(ls->val, rs->val);
  }
}pool[MAXN<<1];

Node *newNode() {
  static int cnt = 0;
  return &pool[cnt++];
}

Node *build(int l, int r) {
  Node *cur = newNode();
  if(l < r) {
    int mid = (l + r) / 2;
    cur->ls = build(l, mid);
    cur->rs = build(mid + 1, r);
    cur->pushup();
  } else {
    cur->val = make_pair(0, -l);
  }
  return cur;
}

void add(Node *cur, int l, int r, int p, int v) {
  cur->val.first += v;
  if(l < r) {
    int mid = (l + r) / 2;
    if(p <= mid) add(cur->ls, l, mid, p, v);
    else add(cur->rs, mid + 1, r, p, v);
    cur->pushup();
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    vec[l].push_back(k);
    vec[r + 1].push_back(-k);
  }
  Node *root = build(1, 100000);
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <(int) vec[i].size(); j++) {
      int cur = vec[i][j];
      if(cur > 0) {
        add(root, 1, 100000, cur, 1);
      } else {
        add(root, 1, 100000, -cur, -1);
      }
    }
    int ans;
    if(root->val.first) ans = -root->val.second; else ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}