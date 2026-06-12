#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, tar; cin >> n >> tar;
        string buf; cin >> buf;
        vi a (n, 0);
        a[n - 1] = -1;
        if (buf[n - 1 ]== '1') a[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            a[i] = a[i + 1];
            if (buf[i] == '1') a[i]++;
            else a[i]--;
        }
        a[0] = -1e9;
        // cout << "------------------------\n";
        // for (int i = 0; i < n; ++i) cout << a[i] << ", " ;
        // cout << endl << "------------------------" <<endl;
        sort(a.rbegin(), a.rend());
        ll cur = 0, cnt = 0;
        for (int x : a) {
            if (x <= 0) break;
            cur += x;
            cnt++;
            if (cur >= tar) break;
        }

        if (cur >= tar) cout << cnt + 1 <<endl;
        else cout << "-1\n";

    }
}