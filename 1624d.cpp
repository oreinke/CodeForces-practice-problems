#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        vector<int> freq(26, 0);
        for (char c : str) {
            freq[c - 'a']++;
            // cout << "char: " << c << ", freq: " << freq[c - 'a'] << endl;
        }

        int nEven = 0;
        int nOdd = 0;
        for (int i : freq) {
            nEven += i / 2;
            nOdd += i % 2;
        }
       // cout << str << ", evenP: " << nEven << ", odds: " << nOdd << endl;

        if (nEven / k == 0) {
            cout << "1\n";
        }
        else {
            cout << ((nEven / k) * 2) + (((nOdd + 2 * (nEven % k)) >= k) ? 1 : 0) << endl;
        }
    }
}