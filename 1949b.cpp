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
        vi a(n);
        vi b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int res = 0;
        for (int offset = 0; offset < n; ++offset) {
            int curMin = 2e9;
            for (int i = 0; i < n; ++i) {
                curMin = min(curMin, abs(a[i] - b[(i + offset) % n]));
                if (curMin < res) break;
            }
            res = max(res, curMin);
        }
        cout << res << endl;
    }
}