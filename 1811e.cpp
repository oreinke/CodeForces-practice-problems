#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    vector<ll> perms;
    perms.push_back(1);
    ll curNum = 1;
    while (curNum * 9 <= 10e12) {
        curNum *= 9;
        perms.push_back(curNum);
    }
    int choices[] = {0, 1, 2, 3, 5, 6, 7, 8 , 9};

    while(t--) {
        ll rank; cin >> rank;
        // rank--;
        vector<int> res;
        // cout << "perm size: " << perms.size() << ", rank: " << rank << endl;
        for (int i = perms.size() - 1; i >= 0; --i) {
            // cout << "i: " << i << endl;
            if (res.size() == 0 && rank / perms[i] == 0) {
                continue;
            }
            else {
                res.push_back(choices[rank / perms[i]]);
                rank %= perms[i];
            }
        }
        for (int i : res) {
            cout << i;
        }
        cout << endl;

    }
}