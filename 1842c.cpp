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
        vi dp(n);
        map<int, int> prev;
        int buf;
        cin >> buf;
        prev[buf] = 0;
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            int num; cin >> num;
            if (prev.find(num) != prev.end()) {
                dp[i] = min(dp[i - 1] + 1, prev[num]);
                prev[num] = min(dp[i - 1], prev[num]);
            }
            else {
                dp[i] = dp[i - 1] + 1;
                prev[num] = dp[i - 1];
            }
        }

        cout << n - dp[n - 1] << endl;
        
    }
}