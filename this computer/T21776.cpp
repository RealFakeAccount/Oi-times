#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long

using namespace std;

const int MAXN = 100005;

const int MOD = (int) 1e9 + 7;

struct Matrix {
  int mat[3][3];
  Matrix() {
    memset(mat, 0, sizeof(mat));
  }
  friend Matrix operator*(const Matrix & a, const Matrix & b) {
    Matrix res;
    memset(res.mat, 0, sizeof(res.mat));
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
          res.mat[i][j] += 1LL * a.mat[i][k] * b.mat[k][j] % MOD;
          res.mat[i][j] %= MOD;
        }
      }
    }
    return res;
  }
};

struct Node {
  Matrix mat;
  bool flag;
  Node *ls, *rs;
  void pushup() {
    mat = ls->mat * rs->mat;
  }
  void update() {
    flag ^= 1;
    for(int i = 0; i < 3; i++) {
      swap(mat.mat[i][0], mat.mat[i][1]);
    }
    for(int j = 0; j < 3; j++) {
      swap(mat.mat[0][j], mat.mat[1][j]);
    }
  }
  void pushdown() {
    if(flag) {
      ls->update();
      rs->update();
      flag = 0;
    }
  }
}pool[MAXN<<1];

Node *newNode() {
  static int cnt = 0;
  return &pool[cnt++];
}

int a[MAXN];

Node *build(int l, int r) {
  Node *cur = newNode();
  if(l < r) {
    int mid = (l + r) / 2;
    cur->ls = build(l, mid);
    cur->rs = build(mid + 1, r);
    cur->pushup();
  } else {
    if(a[l] == 0) {
      cur->mat.mat[0][0] = 1;
      cur->mat.mat[1][0] = 1;
      cur->mat.mat[2][0] = 1;
      cur->mat.mat[1][1] = 1;
      cur->mat.mat[2][2] = 1;
    } else {
      cur->mat.mat[0][0] = 1;
      cur->mat.mat[0][1] = 1;
      cur->mat.mat[1][1] = 1;
      cur->mat.mat[2][1] = 1;
      cur->mat.mat[2][2] = 1;
    }
  }
  return cur;
}

Matrix query(Node *cur, int l, int r, int a, int b) {
  if(a <= l && b >= r) return cur->mat;
  cur->pushdown();
  int mid = (l + r) / 2;
  if(b <= mid) return query(cur->ls, l, mid, a, b);
  else if(a > mid) return query(cur->rs, mid + 1, r, a, b);
  else {
    return query(cur->ls, l, mid, a, b) * 
           query(cur->rs, mid + 1, r, a, b);
  }
}

void modify(Node *cur, int l, int r, int a, int b) {
  if(a <= l && b >= r) {
    cur->update();
  } else {
    cur->pushdown();
    int mid = (l + r) / 2;
    if(a <= mid) modify(cur->ls, l, mid, a, b);
    if(b > mid) modify(cur->rs, mid + 1, r, a, b);
    cur->pushup();
  }
}

main() {
  int n, m;
  scanf("%lld %lld", &n, &m);
  for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  Node *root = build(1, n);
  while(m--) {
    int opt, l, r;
    scanf("%lld %lld %lld", &opt, &l, &r);
    if(opt == 1) {
      modify(root, 1, n, l, r);
    } else {
      Matrix res = query(root, 1, n, l, r);
      int ans = (res.mat[2][0] + res.mat[2][1]) % MOD;
      printf("%lld\n", ans);
    }
  }
  return 0;
}