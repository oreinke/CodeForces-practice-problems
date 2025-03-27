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
        vector<ull> a (n) ,b (n);
        for (auto &x : a) cin >> x;
        ull sum = 0;
        map<int, ull> cnt;
        map<int, ull> cntMad;
        ull curVal = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            cnt[a[i]]++;
            if (a[i] > curVal && cnt[a[i]] >= 2) curVal = a[i];
            b[i] = curVal;
            cntMad[curVal]++;
        }

        for (int i = 1; i < n; ++i) {
            
            if (cntMad[b[i]] == 1) {
                sum += b[i] -  b[i - 1];
                b[i] = b[i - 1];
                cntMad[b[i]]++;
            }
        }
        for (int i = 0; i < n - 1; ++i ) {
            if (b[i] != b[i + 1]) {
                sum += b[i] * cntMad[i] * (n - 2 - i);
                sum += (b[i] * (b[i] + 1)) / 2;
            }
        }
        sum += cntMad[n- 1] * (b[n - 1] - 1) / 2;
        cout << sum <<endl;

    }
}