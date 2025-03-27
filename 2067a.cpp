#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if (y - x == 1 || ((x > y) && ((x - y - 8) % 9 == 0))) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
}