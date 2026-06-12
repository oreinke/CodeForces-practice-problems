#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<pll> a (n);
        for (int i = 0; i < n; ++i) cin >> a[i].first;
        for (int i = 0; i < n; ++i) cin >> a[i].second;
       
        sort (a.begin(), a.end());

        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, a[i].first * min(a[i].second, m / a[i].first));
        }

        for (int i = 0; i < n - 1; ++i) {
            if(a[i].first != a[i + 1].first - 1) continue;
            ll l = min(a[i].second, m / a[i].first);
            ll r = min(a[i + 1].second, (m - l * a[i].first) / a[i + 1].first);
            
            ll change =min(l, min(a[i + 1].second - r, m - (l * a[i].first + r * a[i + 1].first)));
            res = max(res, l * a[i].first + r * a[i + 1].first + change);
        }

        cout << res << endl;
    }
}