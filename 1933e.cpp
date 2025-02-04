#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> pre (n + 1);
        pre[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int num; cin >> num;
            pre[i] = pre[i - 1] + num;
        }
        int q; cin >> q;
        while (q--) {
            int l, u; cin >> l >> u;
            auto it = lower_bound(pre.begin(), pre.end(), pre[l - 1] + u);
            if (it == pre.end()) it--;
            ll segs = *it - pre[l - 1];
            ll offer = segs * u - ((segs - 1) * segs / 2);
            int res = it - pre.begin();
            if (res > l) {
                ll segs = *(it - 1) - pre[l - 1];
                if ((segs * u - ((segs - 1) * segs / 2)) >= offer) {
                    res--;
                }
            }
            cout << res << " ";

        }
        cout << endl;
    }
}