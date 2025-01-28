#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        int a = 0, b = 0, bF = -1;

        string res = "";
        bool valid = true;
        vector<int> after (10, 0);

        for (int i = 0; i < n; ++i) {
            after[str[i] - '0']++; 
        }

        for (int i = 0; i < n && valid; ++i) {
            int num = str[i] - '0';
            after[num]--;
            bool canPut = true;
            for (int j = 0; j < num; ++j) {
                if (after[j] > 0) {
                    canPut = false;
                }
            }
            if (canPut && (bF == -1 || num <= bF)) {
                a = num;
                res.push_back('1');
            }
            else {
                if (num >= b) {
                    res.push_back('2');
                    if (bF == -1) {
                        bF = num;
                    }
                    b = num;
                }
                else {
                    valid = false;
                }
            }
        }
        if (!valid || (bF < a && bF != -1)) {
            cout << "-\n";
        }
        else {
            cout << res << endl;
        }
        

    }
}