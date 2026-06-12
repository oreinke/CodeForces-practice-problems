#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> l, r;
        for (int i = 0; i < n; ++i) {
            char c; cin >> c;
            int x; cin >> x;
            if (c == '+') l.push_back({0, x});
            else l.push_back({1, x});
            
            cin >> c >> x;
            if (c == '+') r.push_back({0, x});
            else r.push_back({1, x});
        }

        ll left = 1, right = 1, carry = 0;
        for (int i = 0; i < n; ++i) {
            ll lAdd = 0, rAdd = 0;
            if (l[i].first) lAdd = left * (l[i].second - 1);
            else lAdd = l[i].second;

            if (r[i].first) rAdd = right * (r[i].second - 1);
            else rAdd = r[i].second;

            if (i != n - 1) {
                if (l[i + 1].first + r[i + 1].first == 2) {
                    if (l[i + 1].second > r[i + 1].second) {
                        left += lAdd + rAdd + carry;
                        carry = 0;
                    }
                    else if (l[i + 1].second < r[i + 1].second) {
                        right += lAdd + rAdd + carry;
                        carry = 0;
                    }
                    else {
                        
                        carry += lAdd + rAdd;
                        carry *= l[i + 1].second;
                        // carry *= l[i + 1].second;
                    }   
                }
                else if (l[i + 1].first) {
                    left += (carry + lAdd + rAdd);
                    carry = 0;
                }
                else if (r[i + 1].first) {
                    right += (carry + lAdd+ rAdd);
                    carry = 0;
                }
                else {
                    carry += lAdd + rAdd;
                }
            }
            else {
                left += carry + lAdd + rAdd;

            }
            // cout << "l: " << left << ", r: " << right << ", carry: " << carry <<endl;   
        }
        cout << left + right << endl;
    }
}