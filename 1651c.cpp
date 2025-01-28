#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
        
        ll a1 = a[0], a2 = a[n - 1], b1 = b[0], b2 = b[n - 1];
        ll b1D = 5e9;
        ll b2D = 5e9;
        ll a1D = 5e9;
        ll a2D = 5e9;
        for (int num : b) {
            if (a1D > abs(a1 - num)) {
                a1D = abs(a1 - num);
            }
            if (a2D > abs(a2 - num)) {
                a2D = abs(a2 - num);
            }
        }

        for (int num : a) {
            if (b1D > abs(b1 - num)) {
                b1D = abs(b1 - num);
            }
            if (b2D > abs(b2 - num)) {
                b2D = abs(b2 - num);
            }
        }
        ll total = a1D + a2D + b1D + b2D;

        total = min(total, min(abs(a1 - b1), a1D + b1D) + min(a2D + b2D, abs(a2 - b2)));
        total = min(total, min(abs(a1 - b2), a1D + b2D) + min(a2D + b1D, abs(a2 - b1)));

        cout << total << endl;
    }
}