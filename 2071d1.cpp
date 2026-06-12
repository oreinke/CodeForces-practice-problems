#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n, l, r; cin >> n >> l >> r;
        vector <int> a (n);
        for (auto &x : a ) cin >> x;
        int cyc = 0;
        for (int x : a) cyc ^= x;
        int res = 0;
        if (l <= n) {
            for (int i = 0; i < l; ++i) res ^= a[i];
        }
        else {
            l /= 2;
            if ((l / n) % 2) res = cyc;
            l %= n;
            for (int i = 0; i < l; ++i) res ^= a[i];
        }
        cout << res << endl;
    }
}