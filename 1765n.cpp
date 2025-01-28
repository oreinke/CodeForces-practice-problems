#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    string str; cin >> str;
    int k; cin >> k;
    bool oBlock = true;
    string res = "";
    for (int i = 0; i < str.length(); ++i) {
        while (!res.empty() && k > 0) {
            if (oBlock) {
                
            }
            if (res[res.size() - 1] > str[i]) {
                res.pop_back();
                k--;
            }
        }
        res.push_back();
    }
    cout << res << endl;
    

}