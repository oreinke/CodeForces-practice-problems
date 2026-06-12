#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update (int pos, ll dif) {
        for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) {
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a (n);
    for (auto &x : a) cin >> x;

    FT ft = FT(n + 1);
    for (int i = 0; i < n; ++i) {
        cout << i - ft.query(a[i])  << " ";
        ft.update(a[i], 1);
    }
    cout << endl;
}