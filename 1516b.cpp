#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

bool rec (int s, int val, int n, vector<vector<ull>> &dp, map<pair<int,ull>, bool> &memo) {
    if (s == n) {
        return true;
    }
    if (memo.find({s, val}) == memo.end()) {
        bool found = false;
        for (int i = s; i < n && !found; ++i) {
            if (dp[s][i] == val) {
                found = rec(i + 1, val, n, dp, memo);
            }
        }
        memo[{s, val}] = found;
        return found;
    }
    else {
        return memo[{s, val}];
    }
    
    
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ull> arr(n);
        for (auto &x : arr) cin >> x;
        vector<vector<ull>> dp(n, vector<ull>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = arr[i];
            // cout << i << ", " << dp[i][i] <<endl;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = (dp[i][j - 1] | arr[j]) - (dp[i][j - 1] & arr[j]);
            }
        }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << dp[i][j] <<  " ";
        //     }
        //     cout << endl;
        // }

        map<pair<int, ull>, bool> memo;
        bool found = false;
        for (int i = 0; (i < n - 1) && !found; ++i) {
            found = rec(i + 1, dp[0][i], n, dp, memo);
        }
        if (found) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}