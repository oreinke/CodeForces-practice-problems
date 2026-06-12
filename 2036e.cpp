#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, q; cin >> n >> k >> q;

    vector<vector<int>> g (k, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) cin >> g[j][i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j) g[j][i] |= g[j][i - 1];
    }

    while (q--) {
        int m; cin >> m;
        int greater = 0, lower = n - 1;
        while (m--) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            if (o == '>') {
                
                greater = max(greater,(int) (upper_bound(g[r].begin(), g[r].end(), c) - g[r].begin()));
            }
            else {
                lower = min(lower,(int) (lower_bound(g[r].begin(), g[r].end(), c) - g[r].begin()) - 1);
            }
        }
        if (greater <=  lower) cout << greater + 1 << "\n";
        else cout << "-1\n";
    }
}