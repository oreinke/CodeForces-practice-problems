#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int l = 1, r = 1000;
        while (r > l) {
            int offset = (r - l) / 3;
            int ql = l + offset, qr = l + offset *2;
            cout << "? " << ql << " " << qr << endl;
            int q; cin >> q;
            if (q == -1) return 0;
            if (q == ql * qr) {
                l = qr + 1;
            }
            else if (q == ql * (qr + 1)) {
                l = ql + 1;
                r = qr;
            }
            else {
                r = ql;
            }
        }
        cout << "! " <<  r << endl;
    }
}