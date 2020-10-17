#include <iostream>
using namespace std;

long long n, k, A, B, cost, mnus;

int main() {
    cin >> n >> k >> A >> B;
    cost = 0;
    if (k == 1) {
        cost = A*(n-1);
        n = 1;
    }
    while (n != 1) {
        if (n % k == 0) {
            mnus = n - (n/k);
            if (mnus * A < B) {
                cost += A * mnus;
            } else {
                cost += B;
            }
            n /= k;
        } else {
            if (n > k) mnus = n - (n / k) * k;
            else mnus = n-1;
            n -= mnus;
            cost += A * mnus;
        }
    }
    cout << cost << endl;
    return 0;
}
