#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        unsigned long long x, m;
        cin >> x >> m;
        int cnt = 0;
        for (unsigned long long i = 1; i <= min(2 * x, m); ++i ) {
            if (i == x)
                continue;

            unsigned long long offer = (x ^ i) & ~(x & i);
            if (offer != 0 && (x % offer == 0 || i % offer == 0))
                cnt++;
        }
        cout << cnt << endl;
    }
}