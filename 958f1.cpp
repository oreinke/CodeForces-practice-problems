#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n, m; cin >> n >> m;
    vii pre (n + 1, vi (m, 0));
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        int ind; cin >> ind;
        ind--;
        pre[i][ind]++;
    }
    vi target (m);
    for (auto &x : target) cin >> x;

    bool found = false;
    for (int i = 1; i <= n && !found; ++i) {
        for (int j = i; j <= n && !found; ++j) {
            bool match = true;
            for (int k = 0; k < m; ++k) {
                if ((pre[j][k] - pre[i - 1][k]) != target[k]) {
                    match = false;
                }
            }

            if (match) {
                found = true;
            }
        }
    }

    if (found) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

}